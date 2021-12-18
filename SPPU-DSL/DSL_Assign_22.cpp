/*
Name: Sahil S. Naik
PRN: S20111006
Subject: DSL Lab
Assignment: #22
*/

#include <iostream>
using namespace std;
struct node
{
    int roll;
    struct node *next;
};

class show_info
{
    node *head1=NULL;
    node *temp1=NULL;
    node *head2=NULL;
    node *temp2=NULL;
    node *head3=NULL;
    node *temp3=NULL;
    node *head4=NULL;
    node *head5=NULL;
    node *temp4=NULL;
    int prn, i, strength, f, van_stu, but_stu;

public:
    node *create_student();
    void insert_student();
    void all_student();
    void vanilla();
    void butterscotch();
    void union_ice();
    void inter_ice();
    void not_ice();
    void only_van();
    void only_but();
    void display();
};

node *show_info::create_student()
{
    node *p = new(struct node);
    cout<<"Enter Student Roll number : ";
    cin>>prn;
    p->roll=prn;
    p->next=NULL;
    return p;
}

void show_info::insert_student()
{
    node *p = create_student();
    if (head3==NULL)
    {
        head3=p;
    }
    else
    {
        temp3=head3;
        while(temp3->next!=NULL)
        {
            temp3=temp3->next;
        }
        temp3->next=p;
    }
}

void show_info::display()
{
    temp3=head3;
    while(temp3->next!=NULL)
    {
        cout<<"\n"<<temp3->roll;
        temp3=temp3->next;
    }
    cout<<"\n"<<temp3->roll;
}

void show_info::all_student()
{
    cout<<"\nEnter number of students to add : ";
    cin>>strength;
    head3=NULL;
    for(i=0; i<strength; i++)
    {
        insert_student();
        head4=head3;
    }
    display();
    head3=NULL;
}

void show_info::vanilla()
{
    cout<<"\nEnter no. of students who like Vanilla : ";
    cin>>van_stu;
    head3=NULL;
    for(i=0; i<van_stu; i++)
    {
        insert_student();
        head1=head3;
    }
    display();
    head3=NULL;
}

void show_info::butterscotch()
{
    cout<<"\nEnter no. of students who like Butterscotch : ";
    cin>>but_stu;
    for(i=0; i<but_stu; i++)
    {
        insert_student();
        head2=head3;
    }
    display();
    head3=NULL;
}

void show_info::union_ice()
{
    cout<<"\nStudents who like Vanilla or Butterscotch are : ";
    temp1 = head1;
    while(temp1!=NULL)
    {
        node *p = new(struct node);
        p->roll=temp1->roll;
        p->next=NULL;
        if(head5==NULL)
        {
            head5=p;
        }
        else
        {
            temp3=head5;
            while(temp3->next!=NULL)
            {
                temp3=temp3->next;
            }
            temp3->next=p;
        }
        temp1=temp1->next;
    }
    temp2=head2;
    while(temp2!=NULL)
    {
        f=0;
        temp1=head1;
        while(temp1!=NULL)
        {
            if(temp2->roll==temp1->roll)
            {
                f=1;
            }
            temp1=temp1->next;
        }
        if(f==0)
        {
            node *p=new(struct node);
            p->roll = temp2->roll;
            p->next=NULL;
            if(head5==NULL)
            {
                head5=p;
            }
            else
            {
                temp3=head5;
                while(temp3->next!=NULL)
                {
                    temp3=temp3->next;
                }
                temp3->next=p;
            }
        }
        temp2=temp2->next;
    }
    temp3=head5;
    while(temp3->next!=NULL)
    {
        cout<<"\n"<<temp3->roll;
        temp3=temp3->next;
    }
    cout<<"\n"<<temp3->roll;
}

void show_info::only_van()
{
    cout<<"\nStudent who like only Vanilla are : ";
    temp1=head1;
    while(temp1!=NULL)
    {
        temp2=head2;
        f=0;
        while(temp2!=NULL)
        {
            if(temp1->roll==temp2->roll)
            {
                f=1;
            }
            temp2=temp2->next;
        }
        if(f==0)
        {
            cout<<"\n"<<temp1->roll;
        }
        temp1=temp1->next;
    }
}

void show_info::only_but()
{
    cout<<"\nStudent who like only Butterscotch are : ";
    temp2=head2;
    while(temp2!=NULL)
    {
        temp1=head1;
        f=0;
        while(temp1!=NULL)
        {
            if(temp2->roll==temp1->roll)
            {
                f=1;
            }
            temp1=temp1->next;
        }
        if(f==0)
        {
            cout<<"\n"<<temp2->roll;
        }
        temp2=temp2->next;
    }
}

void show_info::inter_ice()
{
    cout<<"\nStudents who like both ice-creams are : ";
    temp1=head1;
    while(temp1!=NULL)
    {
        temp2=head2;
        while(temp2!=NULL)
        {
            if(temp1->roll==temp2->roll)
            {
                cout<<"\n"<<temp1->roll;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}

void show_info::not_ice()
{
    cout<<"\nStudents who like neither of ice-creams are : ";
    temp3=head4;
    while(temp3!=NULL)
    {
        temp4=head5;
        f=0;
        while(temp4!=NULL)
        {
            if(temp3->roll==temp4->roll)
            {
                f=1;
            }
            temp4=temp4->next;
        }
        if(f==0)
        {
            cout<<"\n"<<temp3->roll;
        }
        temp3=temp3->next;
    }
}

int main()
{
    show_info s;
    int pick;
    char choice;
    do
    {
        cout<<"\nChoose a option-";
          cout<<"\n  1 = To enter all students Roll number  ";
          cout<<"\n  2 = To enter the Roll number of student who like Vanilla";
          cout<<"\n  3 =  To enter the Roll number of student who like Butterscotch";
          cout<<"\n  4 =  To display the Roll number of student who like Vanilla or Butterscotch";
          cout<<"\n  5 =  To display the Roll number of student who like only Vanilla";
          cout<<"\n  6 =  To display the Roll number of student who like only Butterscotch";
          cout<<"\n  7 =  To display the Roll number of student who like both Vanilla and Butterscotch ";
          cout<<"\n  8 =  To display the Roll number of student who neither like Vanilla nor Butterscotch";
          cout<<"\nEnter your Choice : ";
          cin>>pick;
          switch(pick)
          {
              case 1 : s.all_student();
              break;

              case 2 : s.vanilla();
              break;

              case 3 : s.butterscotch();
              break;

              case 4 : s.union_ice();
              break;

              case 5 : s.only_van();
              break;

              case 6 : s.only_but();
              break;

              case 7 : s.inter_ice();
              break;

              case 8 : s.not_ice();
              break;

              default:cout<<"\nInvalid Choice!";
          }
          cout<<"\nDo you want to continue? y/n ? ";
          cin>>choice;
    }while(choice=='y' || choice=='Y');

    return 0;
}
