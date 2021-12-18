/*
Name: Sahil S. Naik
PRN: S20111006
Subject: DSL Lab
Assignment: #27
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;


int prec(char c)
{
    if(c=='/'|| c=='*')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
};
string infixtoprefix(string s)
{
    stack<char>st;
    string res;

    for(int i=0;i<s.length();i++){

        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while (!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top())>prec(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }

    return res;
}
int main()
{
    cout<<"Given Expression is : (a-b/c)*(a/k-l)\nIts Infix to Prefix is : ";
    cout<<infixtoprefix("(a-b/c)*(a/k-l)")<<endl;
}

