#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

class I_O_Files
{
public:
    void create_file(char* file_name)
    {
        ofstream new_file;
        new_file.open(file_name);
        cout<<file_name<<" created Successfully!";
        new_file.close();
    }

    void write_to_file(char* file_name)
    {
        int get_num;
        string input_text;
        ofstream old_file;
        old_file.open(file_name, ios::app);
        cout<<"\n-------------------------------\nFile opened Successfully!"<<endl;

        srand(time(NULL));
        get_num = rand() % 10+1;
        if(get_num==1)
        {
            old_file<<"Real eyes Realize Real Rice!\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }
        else if(get_num==2)
        {
            old_file<<"There is something written in this file!\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }
        else if(get_num==3)
        {
            old_file<<"Bit suspicious, but it worked!\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }
        else if(get_num==4)
        {
            old_file<<"Tabs or Space?\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }
        else if(get_num==5)
        {
            old_file<<"If it works, it ain't Stupid!\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }
        else if(get_num==6)
        {
            old_file<<"Nothing to Report!\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }
        else if(get_num==7)
        {
            old_file<<"Nothing to Report! Or maybe there is something.\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }
        else if(get_num==8)
        {
            old_file<<"Just another lovely day, without studies!\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }
        else if(get_num>8)
        {
            old_file<<"Nothing to Report! Seriously?\n";
            cout<<"Text written to the file!\n-------------------------------\n";
            old_file.close();
        }

    }

    void read_from_file(char* file_name)
    {
        string get_lines;
        ifstream old_file;
        old_file.open(file_name, ios::in);
        cout<<"\n------------------------------------------------------------\nThe information in this file is :\n\n";
        while (getline(old_file, get_lines))
        {
            cout<<get_lines<<endl;
        }
        cout<<"\n-------------------------------------------------------------\n"<<endl;
        old_file.close();
    }
};

int main()
{
    int choice, exit=0;
    I_O_Files io;
    char* f_name;
    while(exit!=1)
    {
        cout<<"\nWhat to do?\n1 = Create a new file.\n2 = Read previous file\n3 = Write to previous file\n4 = Exit\nEnter your Choice : ";
        cin>>choice;
        if(choice == 1)
        {
            cout<<"Enter name of file to create with extension : ";
            cin>>f_name;
            io.create_file(f_name);
        }
        else if(choice == 2)
        {
            cout<<"Enter name of file to read with extension : ";
            cin>>f_name;
            io.read_from_file(f_name);
        }
        else if(choice == 3)
        {
            cout<<"Enter name of file to write with extension : ";
            cin>>f_name;
            io.write_to_file(f_name);
        }
        else if(choice == 4)
        {
            cout<<"Exiting..."<<endl;
            exit += 1;
        }
        else
        {
            cout<<"Invalid Choice!";
        }
    }
    return 0;
}
