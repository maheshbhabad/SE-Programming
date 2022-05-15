#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class Employee
{

        string emp_name, emp_desig, emp_id, emp_sal;
   public:
       void create_file(char* file_name)
       {
           ofstream new_file;
           new_file.open(file_name);
           new_file.close();
       }

       string ret_emp_id()
       {
           return emp_id;
       }

       void write_file(char* file_name)
       {

           ofstream old_file;
           old_file.open(file_name, ios::app);
           cout<<"\n-------------------------------\nFile opened Successfully!"<<endl;

            cout<<"Enter Employee name: ";
            cin>>emp_name;
            cout<<"Enter Employee ID: ";
            cin>>emp_id;
            cout<<"Enter Employee Designation: ";
            cin>>emp_desig;
            cout<<"Enter Employee Salary: ";
            cin>>emp_sal;

            old_file<<emp_id<<"\t"<<emp_name<<"\t"<<emp_desig<<"\t"<<emp_sal<<endl;
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();


       }

       void del_from_file(char* file_name, int id)
       {
            ifstream is(file_name);

            ofstream ofs;
            ofs.open("temp.txt", ofstream::out);

            char c;
            int line_no = 1;
            while(is.get(c))
            {
                if(c=='\n')
                {
                    line_no++;
                }
                if (line_no!=id)
                {
                    ofs<<c;
                }
            }

            ofs.close();
            is.close();
            remove(file_name);
            rename("temp.txt", file_name);
       }

       void search_file(char* file_name)
       {
            ifstream old_file;
            old_file.open(file_name, ios::in);
            string words, srch_id;

            cout<<"Enter id: ";
            cin>>srch_id;

            while(getline(old_file, words))
            {
                for(int i=0; i<srch_id.size(); i++)
                {
                    if(srch_id[i]==words[i])
                    {
                        cout<<"\nRecord found!\n";
                        cout<<words<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"\nNot match!\n";
                        break;
                    }
                }
            }
       }
};

int main()
{
    int chc, exit=0, id;
    Employee file;
    while(exit!=1)
    {
        cout<<"\nWhat to do?\n1 = Create File\n2 = Write in File\n3 = Delete from file\n4 = Search\n5 = Exit\nEnter choice: ";
        cin>>chc;

        if(chc==1)
        {
            cout<<"\nFile created with name Employee.txt!\n";
            file.create_file("Employee.txt");
        }

        else if(chc==2)
        {
            cout<<"\nFile opened!";
            file.write_file("Employee.txt");
        }

        else if(chc==3)
        {
            cout<<"Enter Employee ID: ";
            cin>>id;
            file.del_from_file("Employee.txt", id);
        }

        else if(chc==4)
        {
            file.search_file("Employee.txt");
        }

        else if(chc==5)
        {
            cout<<"Exiting...\n";
            exit+=1;
        }

        else
        {
            cout<<"Invalid Choice!\n";
        }
    }
    return 0;
}
