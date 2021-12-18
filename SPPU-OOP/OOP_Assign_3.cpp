#include<iostream>
using namespace std;

class Publication
{
public:
    char b_title[50];
    float b_price;
};

class Book : public Publication
{
public:
    int b_pages;
};

class Tape : public Publication
{
public:
    float t_min;
};

int main()
{
    int chc;
    while(chc!=3)
    {
        cout<<"\nChoose a Option\n1 = Register a Book & Tape\n2 = View Registered book\n3 = Exit\nChoice = ";
        cin>>chc;
        if(chc == 1)
        {
            Tape tp;
            Book bk;
            cout<<"Enter book title : ";
            cin>>bk.b_title;
            cout<<"Enter book price : ";
            cin>>bk.b_price;
            cout<<"Enter count of book pages : ";
            cin>>bk.b_pages;
            cout<<"Enter duration of tape : ";
            cin>>tp.t_min;
            try
            {
                if(bk.b_price<=0)
                {
                    throw(1);
                }
                if(bk.b_pages<=0)
                {
                    throw(2);
                }
                if(tp.t_min<=0)
                {
                    throw(3);
                }
            }
            catch(int i1)
            {
                cout<<"Price and Duration can't be 0 or Negative!"<<endl;
                cout<<"All values of book named "<<bk.b_title<<" has set to Zero."<<endl;
                bk.b_price=0;
                bk.b_pages=0;
                tp.t_min=0;
            }
        }

        else if(chc == 2)
        {
            Tape tp3;
            Book bk2;
            cout<<"\nBook title is "<<bk2.b_title<<" containing "<<bk2.b_pages<<" pages, selling at Rs."<<bk2.b_price<<endl;
            cout<<"Tape duration is "<<tp3.t_min<<"(min)."<<endl;
        }
    }

    return 0;
}
