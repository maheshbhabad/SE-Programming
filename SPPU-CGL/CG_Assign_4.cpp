/*
Name: Sahil S. Naik
PRN: S20111006
Subject: CG Lab
Assignment: #4
*/

#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

int main()
{
    int gd=DETECT, gm, chc;
    initgraph(&gd, &gm, (char*)"");
    cout<<"What to do?\n1 = Scaling\n2 = Translation\n3 = Rotation\nEnter your Choice : ";
    cin>>chc;
    switch(chc)
    {
    case 1:
        {
            int x1=30, y1=30, x2=70, y2=70, y=2, x=2;
            cout<<"Before Scaling : Cyan"<<endl;
            setcolor(3);
            rectangle(x1,y1,x2,y2);
            cout<<"After Scaling : Green"<<endl;
            setcolor(10);
            rectangle(x1*x, y1*y, x2*x, y2*y);
            getch();
            break;
        }
    case 2:
        {
            int x1=200, y1=150, x2=300, y2=250;
            int tx=50, ty=50;
            cout<<"Before Translation : Cyan"<<endl;
            setcolor(3);
            rectangle(x1,y1,x2,y2);
            setcolor(4);
            cout<<"After Translation : Red"<<endl;
            rectangle(x1+tx, y1+ty, x2+tx, y2+ty);
            getch();
            break;
        }
    case 3:
        {
            long x1=200,y1=200,x2=300,y2=300;
            double a;
            cout<<"Rectangle with rotation"<<endl;
            setcolor(3);
            rectangle(x1,y1,x2,y2);
            cout<<"Angle of rotation: ";
            cin>>a;
            a=(a*3.14)/180;
            long xr=x1+((x2-x1)*cos(a)-(y2-y1)*sin(a));
            long yr=y1+((x2-x1)*sin(a)+(y2-y1)*cos(a));
            setcolor(2);
            rectangle(x1,y1,xr,yr);
            getch();
            break;
        }
    default:
        {
            cout<<"Invalid Choice!"<<endl;
            break;
        }
    }
    closegraph();
    return 0;
}
