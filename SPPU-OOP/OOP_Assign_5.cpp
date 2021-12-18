/*
Name: Sahil S. Naik
PRN: S20111006
Subject: OOP Lab
Assignment: #5
*/

#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;

int main()
{
    list<int> lst;
    int i;
    for(i=0; i<10; i++)
    {
        lst.push_back(rand());
    }
    cout<<"Original Values are : ";
    list<int>::iterator p = lst.begin();
    while(p != lst.end())
    {
        cout<<*p<<" ";
        p++;
    }
    cout<<endl<<endl;
    lst.sort();
    cout<<"Sorted Values are : ";
    p = lst.begin();
    while(p != lst.end())
    {
        cout<<*p<<" ";
        p++;
    }
    cout<<endl;
}
