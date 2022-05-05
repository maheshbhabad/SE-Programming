#include<iostream>
#include<string>
#include<stack>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;

class Ntree //Node Declaration
{
public:
    char d;
    Ntree *l, *r;
    Ntree(char d)
    {
        this->d = d;
        this->l = NULL;
        this->r = NULL;
        //l = Left, r = Right, d = character
    }
};

class Stack_Node  //Stack Declaration
{
public:
    Ntree *ntree;
    Stack_Node *n;
    Stack_Node(Ntree*ntree) //Constructor
    {
        this->ntree = ntree;
        n = NULL;
    }
};

class ExpressTree
{
    Stack_Node *top;
public:
    ExpressTree()
    {
        top = NULL;
    }

    void clear()
    {
        top = NULL;
    }

    void push(Ntree *ptr)
    {
        if (top == NULL)
        {
            top = new Stack_Node(ptr);
        }
        else
        {
            Stack_Node *nptr = new Stack_Node(ptr);
            nptr->n = top;
            top = nptr;
        }
    }

    Ntree *pop()
    {
        if (top == NULL)
        {
            cout<<"UnderFlow!"<<endl;
        }
        else
        {
            Ntree *ptr = top->ntree;
            top = top->n;
            return ptr;
        }
    }

    Ntree *peek()
    {
        return top->ntree;
    }

    void insertT(char val)
    {
        if (isOperand(val))
        {
            Ntree *nptr = new Ntree(val);
            push(nptr);
        }
        else if (isOperator(val))
        {
            Ntree *nptr = new Ntree(val);
            nptr->l = pop();
            nptr->r = pop();
            push(nptr);
        }
        else
        {
            cout<<"Invalid Expression!"<<endl;
            return;
        }
    }

    bool isOperand(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }

    bool isOperator(char ch)
    {
        return ch = '+' || ch == '-' || ch == '*' || ch =='/';
    }

    void Build_Tree(string eqn)
    {
        for(int i = eqn.length()-1; i>=0; i--)
        {
            insertT(eqn[i]);
        }
    }

    void postfix()
    {
        Post(peek());
    }

    void Post(Ntree*ptr)
    {
        if (ptr != NULL)
        {
            Post(ptr->l);
            Post(ptr->r);
            cout<<ptr->d;
        }
    }
};

int main()
{

    //eg. prefix = +--a*bc/def

    string s;
    ExpressTree et;
    cout<<"\nEnter Equation in Prefix Form: ";
    cin>>s;
    et.Build_Tree(s);
    cout<<"\nPostfix : ";
    et.postfix();
    cout<<"\n";
}
