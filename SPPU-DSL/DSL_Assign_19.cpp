/*
Name: Sahil S. Naik
PRN: S20111006
Subject: DSL Lab
Assignment: #19
*/

#include <iostream>
#include <string.h>
using namespace std;

class Base_Node
{
    friend class People_List;
    int prn;
    char people_name[30];
    Base_Node *next;

public:
    Base_Node(int temp, char s[10])
    {
        prn=temp;
        strcpy(people_name, s);
        next = NULL;
    }
};

class People_List
{
    Base_Node *start;

public:
    People_List()
    {
        start = NULL;
    }

    void display()
    {
        Base_Node *ptr;
        ptr = start;
        cout<<"\nInfo is : \n";
        while(ptr != NULL)
        {
            cout<<"\n"<<ptr->prn;
            cout<<"\n"<<ptr->people_name;
            ptr=ptr->next;
        }
    }
    void append_member();
    void register_member();
    void append_president();
    void append_secretary();
    void remove_member();
    void delete_all();
    void remove_secretary();
    void remove_president();
    void member_count();
    void reverse(Base_Node*);
    void reverse_0()
    {
        reverse(start);
    }
    void concatinate_list(People_List, People_List);
};

void People_List::append_member()
{
    int prn;
    char people_name[30];
    Base_Node *ptr, *temp;
    cout<<"\nEnter PRN number : ";
    cin>>prn;
    cout<<"Enter your Name : ";
    cin>>people_name;
    temp = new Base_Node(prn, people_name);
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void People_List::append_president()
{
    int prn;
    char name[30];
    Base_Node *temp;
    cout<<"\nEnter PRN number : ";
    cin>>prn;
    cout<<"Enter your Name : ";
    cin>>name;
    temp=new Base_Node(prn, name);
    temp->next=start;
    start=temp;
}

void People_List::append_secretary()
{
    int prn;
    char name[30];
    Base_Node *ptr, *temp;
    cout<<"\nEnter PRN number : ";
    cin>>prn;
    cout<<"Enter your Name : ";
    cin>>name;
    temp=new Base_Node(prn, name);
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
}

void People_List::register_member()
{
    int choice;
    char ques;
    do
    {
        cout<<"\nRegister as...\n1 = President\n2 = Secretary\n3 = Member\nEnter your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : append_president();
            break;

            case 2 : append_secretary();
            break;

            case 3 : append_member();
            break;

            default:cout<<"\nInvalid Choice!";
            break;
        }

        cout<<"\nInsert More? Yes/No ? : ";
        cin>>ques;

    }while(ques=='yes' || ques=='Yes' || ques=='y' || ques=='YES');
}

void People_List::delete_all()
{
    int choice;
    char ques;
    do
    {
        cout<<"\nRemove who?\n1 = President\n2 = Secretary\n3 = Member\nEnter your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : remove_president();
            break;

            case 2 : remove_secretary();
            break;

            case 3 : remove_member();
            break;

            default:cout<<"\nInvalid Choice!";
            break;
        }
        cout<<"Remove more Members? Yes/No ? : ";
        cin>>ques;

    }while(ques=='yes' || ques=='Yes' || ques=='y' || ques=='YES');
}

void People_List::remove_secretary()
{
    Base_Node *ptr, *prev;
    ptr=start;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }

    prev->next=NULL;
    delete ptr;
    cout<<"\nRemoved!";
}

void People_List::remove_president()
{
    Base_Node *ptr;
    ptr=start;
    start=start->next;
    delete ptr;
    cout<<"\nRemoved!";
}

void People_List::remove_member()
{
    Base_Node *ptr, *prev;
    int num;
    cout<<"\nEnter PRN to remove : ";
    cin>>num;
    ptr=start;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
        if(ptr->prn==num)
        {
            break;
        }
    }
    if(ptr->next==NULL)
    {
        cout<<"\nNo such Data Found!";
    }
    else if(ptr->prn==num)
    {
        prev->next=ptr->next;
        ptr->next=NULL;
        delete ptr;
        cout<<"\nRemoved!";
    }
}

void People_List::member_count()
{
    Base_Node *ptr;
    int cnt=0;
    ptr=start;
    while(ptr!=NULL)
    {
        cnt++;
        ptr=ptr->next;
    }
    cout<<"\nTotal Members are : "<<cnt;
}

void People_List::reverse(Base_Node *ptr)
{
    if(ptr==NULL)
        return;

    else
    {
        reverse(ptr->next);
    }
    cout<<"\n"<<ptr->prn;
    cout<<"\n"<<ptr->people_name;
}

void People_List::concatinate_list(People_List l1, People_List l2)
{
    Base_Node *ptr;
    ptr = l1.start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        ptr->next=l2.start;
        l1.display();
    }
}

int main()
{
    int choice;
    char ques;
    People_List lit1, lit2, lit3, lit4;
    do
    {
        cout<<"\nWelcome! What to do?\n1 = Create Member\n2 = Display Members\n3 = Remove members\n4 = Count nodes\n5 = Reverse list\n6 = Merge lists\nEnter your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : lit1.register_member();
            break;

            case 2 : lit1.display();
            break;

            case 3 : cout<<"\nEnter the Nodes to be deleted : ";
            lit1.delete_all();
            break;

            case 4 : cout<<"\nNumber of Nodes are : ";
            lit1.member_count();
            break;

            case 5 : cout<<"\nReversed List is : ";
            lit1.reverse_0();
            break;

            case 6 : lit2.append_member();
            lit1.concatinate_list(lit1,lit2);

            default:cout<<"\nInvalid Choice!";
            break;
        }
        cout<<"\nDo you want to continue? Yes/No : ";
        cin>>ques;

    }while(ques=='yes' || ques=='Yes' || ques=='y' || ques=='YES');
    cout<<"Thank you!";
    return 0;
}
