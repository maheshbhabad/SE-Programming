/*
Name: Sahil S. Naik
PRN: S20111006
Subject: DSL Lab
Assignment: #29
*/


#include<iostream>
using namespace std;
#define MAX 10

struct make_queue
{
    int data[MAX];
    int start, rear;
};

class get_Queue
{
    struct make_queue q;
public:
    get_Queue()
    {
        q.start=q.rear=-1;
    }
    int isempty();
    int isfull();
    void enqueue(int);
    int del_queue();
    void display();
};

//Function to check whether our Queue is empty or not
int get_Queue::isempty()
{
    return(q.start==q.rear)?1:0;
}

//Function to check whether our Queue is full or not
int get_Queue::isfull()
{
    return(q.rear==MAX-1)?1:0;
}

//Function to add our Jobs in Queue
void get_Queue::enqueue(int x)
{
    q.data[++q.rear]=x;
}

//Function to delete our Jobs from Queue
int get_Queue::del_queue()
{
    return q.data[++q.start];
}

//Function to Display our current Queue
void get_Queue::display()
{
    int i;
    cout<<"\n-> Queue Contains : ";
    for(i=q.start+1; i<=q.rear; i++)
    {
        cout<<q.data[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    get_Queue Q_obj;
    int chc, x;
    do
    {
        cout<<"\n1 = Insert Job\n2 = Delete Job\n3 = Display\n4 = Exit\nEnter your Choice : ";
        cin>>chc;
        switch(chc)
        {
            case 1 :
                if(!Q_obj.isfull())
                {
                    cout<<"\nEnter Job Data : ";
                    cin>>x;
                    Q_obj.enqueue(x);
                }
                else
                {
                    cout<<"\n-> Queue is Full!\n";
                }
                 break;

            case 2:
                if(!Q_obj.isempty())
                {
                    cout<<"\n-> Deleted Job = "<<Q_obj.del_queue();
                }
                else
                {
                    cout<<"\n-> No Jobs in Queue!";
                }
                Q_obj.display();
                break;

            case 3:
                if(!Q_obj.isempty())
                {
                    Q_obj.display();
                }
                else
                {
                    cout<<"\n-> No Jobs in Queue. Empty!\n";
                }
                break;

            case 4:
                cout<<"\nExiting...\n";
        }
    }while(chc!=4);

    return 0;
}
