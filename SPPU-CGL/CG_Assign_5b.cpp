/*
Name: Sahil S. Naik
PRN: S20111006
Subject: CG Lab
Assignment: #5b
*/

#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <unistd.h>
using namespace std;

void move(int j,int h,int &x,int &y)
{
    if(j==1)
    y-=h;
    else if(j==2)
    x+=h;
    else if(j==3)
    y+=h;
    else if(j==4)
    x-=h;
    lineto(x,y);
}

void hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y, char choice)
{
    if(i>0 && choice=='n')
    {
        i--;
        hilbert(d,r,u,l,i,h,x,y,'n');
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y,'n');
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y,'n');
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y,'n');
    }
    else if(i>0 && choice=='y')
    {
        i--;
        hilbert(d,r,u,l,i,h,x,y,'y');
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y,'y');
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y,'y');
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y,'y');
        sleep(1);
    }
}

int main()
{
    int n,x1,y1;
    int x0=10,y0=10,x,y,h,r=2,d=3,l=4,u=1;
    char chc[10];
    cout<<"\nHow many iterations : ";
    cin>>n;
    cout<<"Enter length : ";
    cin>>h;
    cout<<"Add 1 Second Delay? y/n : ";
    cin>>chc;
    x=x0;y=y0;
    int gm,gd=DETECT;
    initgraph(&gd,&gm,NULL);
    initwindow(1280, 720);
    moveto(x,y);
    hilbert(r,d,l,u,n,h,x,y,*chc);
    delay(1000);
    closegraph();
    return 0;
}
