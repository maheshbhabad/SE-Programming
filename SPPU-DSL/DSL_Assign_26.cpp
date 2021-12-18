/*
Name: Sahil S. Naik
PRN: S20111006
Subject: DSL Lab
Assignment: #26
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define bool int

struct stack_node
{
    char data;
    struct stack_node *next;
};

void push(struct stack_node**top_ref, int new_data);

int pop(struct stack_node**top_ref);

// This function checks for matching pairs of parenthesis
bool is_matching(char character1, char character2)
{
    if(character1 == '(' && character2 == ')')
        return 1;
    else if(character1 == '{' && character2 == '}')
        return 1;
    else if(character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

// This functions checks is parenthesis present are closed and opened properly or not
bool parent_bal(char express[])
{
    int i = 0;
    struct stack_node *stack = NULL;
    while (express[i])
    {
        if(express[i]=='{' || express[i]=='(' || express[i]=='[')
            push(&stack, express[i]);

        if(express[i]=='}' || express[i]==')' || express[i]==']')
        {
            if(stack==NULL)
                return 0;
            else if(!is_matching(pop(&stack), express[i]))
                return 0;
        }
        i++;
    }
    if(stack==NULL)
        return 1;
    else
        return 0;
}

void push(struct stack_node**top_ref, int new_data)
{
    struct stack_node* new_node = (struct stack_node*)malloc(sizeof(struct stack_node));

    if(new_node==NULL)
    {
        cout<<"\nStack Overflow!";
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

int pop(struct stack_node**top_ref)
{
    char removal;
    struct stack_node*top;
    if(*top_ref==NULL)
    {
        cout<<"\nStack Overflow!";
    }
    else
    {
        top = *top_ref;
        removal = top->data;
        *top_ref = top->next;
        free(top);
        return removal;
    }
}

int main()
{
    char express[100];
    cout<<"Enter a code sentence : ";
    cin>>express;
    if(parent_bal(express))
        cout<<"\nGiven sentence is well parenthesized!\n";
    else
        cout<<"\nGiven sentence is not well parenthesized!\n";
    return 0;
}

