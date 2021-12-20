/*
Name: Sahil S. Naik
PRN: S20111006
Subject: CG Lab
Assignment: #7
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

using namespace std;

int x,y,angle = 0;

void Rain(int x)
{
    int GroundY=400;
    int i, rx, ry;
    for(i=0; i<400; i++)
    {
        rx=rand() % getmaxx();
        ry=rand() % getmaxx();
        if(ry<GroundY-4)
        {
            line(rx,ry,rx+0.5,ry+4);
        }
    }
}

int main()
{

    int gd=DETECT,gm,i;
    initgraph(&gd,&gm,NULL);

    for(i=0; i<getmaxx()-50; i++)
    {
        Rain(x);
        line(0,400,getmaxx(),400);
        rectangle(50+(2*i),250,100+(2*i),350);
        circle(75+(2*i),225,25);
        line(60+(2*i),350,90+(2*i),400);
        line(90+(2*i),350,60+(2*i),400);
        line(100+(2*i),300,125+(2*i),275);
        line(125+(2*i),275,125+(2*i),190);
        line(50+(2*i),190,200+(2*i),190);
        arc(125+(2*i),190,0,180,75);

        if(i%2==0)
        {
            line(75+(2*i),275,25+(2*i),325);
        }
        else
        {
            line(75+(2*i),275,125+(2*i),325);
        }
        delay(150);
        cleardevice();
    }
    closegraph();
    return 0;
}

