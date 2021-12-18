/*
Name: Sahil S. Naik
PRN: S20111006
Subject: OOP Lab
Assignment: #2
*/


/*
This includes :
    1. Use of constructors - default, parameter, copy
    2. Use destructor
    3. Static member function
    4. Friend class
    5. This pointer
    6. In-line code
    7. Dynamic memory allocation operators- new, delete
    8. Exception handling
*/


#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Database
{
    int roll;           //If no access specifier is declared then by default it's in private
    char name[20];
    char Class[10];
    char Div[10];
    char dob[11];
    char bg[16],ct[10];
    char phone[10];

    public:         //Access specified as public, hence any other function can access
    static int stdno;
    static void count()         //Static member function to remember the count of students registered so far
   {
      cout<<"\nNo. of objects created: "<<stdno;
   }
 void func_in(){cout<<"\nIn-line Function!";}

   Database()       //Dummy Function to represent how the values should be included
   {
        roll=99;
        strcpy(name,"Name");
        strcpy(Class,"Class");
        strcpy(Div,"Division");
        strcpy(dob,"DD/MM/YYYY");
        strcpy(bg,"Blood-Group");
        strcpy(ct,"City");
        strcpy(phone,"Phone no.");
        ++stdno;
   }
   Database(Database *ob)       //Actual Function to get information from the user and store it
   {
        strcpy(name,ob->name);
        strcpy(dob,ob->dob);
        strcpy(Class,ob->Class);
        strcpy(Div,ob->Div);
        strcpy(bg,ob->bg);
        strcpy(ct,ob->ct);
        strcpy(phone,ob->phone);
        ++stdno;
   }
void getdata()
   {
     cout<<"\n\nEnter: Name, Roll, Class, Division, DOB, Blood-Group, City, Phone\n";
     cin>>name>>roll>>Class>>Div>>dob>>bg>>ct>>phone;
   }
   friend void display(Database d);      //Friend function is used to Display all the data from it's Friend Class
   ~Database()      //A Destructor is invoked to save the Memory once all necessary things are Recorded.
   {
      cout<<"\n"<<this->name<<"(Object) is destroyed!\n";   //Use of 'this ->' pointer, it returns address of the object of the class
   }
};

void display(Database d)        //This function just displays all the data registered so far, it's also a parameterized constructor
{
 cout<<"\n"<<d.name<<"   "<<d.roll<<"        "<<d.Class<<"   "<<d.Div<<"     "<<d.dob<<"        "<<d.bg<<"          "<<d.ct<<"   "<<d.phone;
}
int Database::stdno;        //Returns Count of the students registered so far

int main()
{
    int n,i;
    Database d1,*ptr[5];
    cout<<"\nEnter Values in the Format -";
    display(d1);

    d1.getdata();
    display(d1);

    Database d2(&d1);
    cout<<"\n\nUse of copy constructor :\n";
    display(d2);        //Displays an exact copy of a Function


    cout<<"\nHow many Students you want to Register?: ";
    cin>>n;
    //Exception handling...
    //If entered invalid number of registrations.
    try
    {
        if(n==0 || n<0)
        {
            throw(1);
        }
        for(i=0;i<n;i++)
        {
            ptr[i]=new Database();      //Instantly creates new function and included data in it
            ptr[i]->getdata();
        }
    }
    catch(int err)
    {
        cout<<"Invalid Number of registrations!"<<endl;
        cout<<"No student can be registered!"<<endl<<"Final Reports are!"<<endl;
    }

    cout<<"\n"<<"Name    "<<"Roll no.  "<<"Class  "<<"Division  "<<"Date of Birth  "<<"Blood-Group     "<<"City    "<<"Phone no.  ";
    for(i=0;i<n;i++)
        display(*ptr[i]);
    Database::count();
    for(i=0;i<n;i++)
    {
        delete(ptr[i]);     //Deletes values once not in use
    }
    cout<<"\nObjects deleted!" ;
    return 0;
}
