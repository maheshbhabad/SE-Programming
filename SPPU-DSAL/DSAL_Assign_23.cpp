#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class student
{
    int admno;
    char name[50];
    char addr[50];
public:
    void setData()
    {

        cout << "\nEnter Roll Number: ";
        cin >> admno;
        cout << "Name: ";
        cin>>name;
        cout<<"City: ";
        cin>>addr;
    }

    void showData()
    {
        cout<<"\n______________________________\n";
        cout << "\nStudent Roll Number: " << admno;
        cout << "\nStudent Name: " << name;
        cout<<"\nCity: "<<addr<<endl;
        cout<<"______________________________\n\n";
    }

    int retAdmno()
    {
        return admno;
    }
};

void write_record()
{
    ofstream outFile;
    outFile.open("student.txt", ios::binary | ios::app);
    student obj;
    obj.setData();
    outFile.write((char*)&obj, sizeof(obj));
    outFile.close();
}

void display()
{
    ifstream inFile;
    inFile.open("student.txt", ios::binary);

    student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
    }

    inFile.close();
}

void search(int n)
{
    ifstream inFile;
    inFile.open("student.txt", ios::binary);

    student obj;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            obj.showData();
            break;
        }
    }

    inFile.close();
}

void delete_record(int n)
{
    student obj;
    ifstream inFile;
    inFile.open("student.txt", ios::binary);

    ofstream outFile;
    outFile.open("temp.txt", ios::out | ios::binary);

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() != n)
        {
            outFile.write((char*)&obj, sizeof(obj));
        }
    }

    inFile.close();
    outFile.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");
}

void modify_record(int n)
{
    fstream file;
    file.open("student.txt",ios::in | ios::out);

    student obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.retAdmno() == n)
        {
            cout << "\nEnter the new details of Student: ";
            obj.setData();
            int pos = -1 * sizeof(obj);
            file.seekp(pos, ios::cur);
            file.write((char*)&obj, sizeof(obj));
        }
    }

    file.close();
}

int main()
{
	int ch;
	do{
    cout<<"\n1. Write\n2. Display\n3. Search\n4. Delete\n5. Modify\n6. Exit";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
		    case 1:
		        cout<<"Enter number of records: ";
                int n;
                cin>>n;
                for(int i = 0; i <n; i++)
                write_record();
                break;

		    case 2:
			    cout << "\nList of records-";
			    display();
			    break;


		    case 3:
		    	cout<<"Enter Student Roll Number: ";
		    	int s;
		    	cin>>s;
		    	search(s);
			break;

		    case 4:
		    	cout<<"Enter Roll number to be deleted: ";
		    	int d;
		    	cin>>d;
                delete_record(d);
                cout << "Record Deleted!\n";
                break;

		    case 5:
	    	    cout<<"Enter Roll number to be modified: ";
	    	    int m;
	    	    cin>>m;
                modify_record(m);
		    break;

		    case 6:
		        cout<<"Exiting!";

                return 0;
    }

}while(ch!=6);
}
