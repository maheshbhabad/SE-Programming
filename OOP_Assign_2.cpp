/*
Name: Sahil S. Naik
PRN: S20111006
Subject: OOP Lab
Assignment: #1
*/


#include <iostream>
#include<complex>
using namespace std;

void cmplx(float num, float imagi)
{
    std::complex<float> mycomplex(num, imagi);
    cout<<"\nGiven complex number is : "<<real(mycomplex)<<" + "<<imag(mycomplex)<<"i\n";
}

void operate_complx(float n1, float i1, float n2, float i2)
{
    float temp1, temp2;
    std::complex<float> addcomp(n1+n2, i1+i2);
    cout<<"\nAddition of given complex number is : "<<real(addcomp)<<" + "<<imag(addcomp)<<"i\n";
    temp1 = (n1*n2) - (i1*i2);
    temp2 = (n1*i2) + (i1*n2);
    cout<<"\nMultiplication of given complex number is : "<<temp1<<" + "<<temp2<<"i\n";
}

void show_complex()
{
    std::complex<int>mycomplex(0,0);
    cout<<"\nComplex numbers are in the format of : "<<real(mycomplex)<<" + "<<imag(mycomplex)<<"i\n";
}

int main()
{
    float num1, img1, num2, img2;
    int work=1, chc;
    while (work!=0)
    {
        cout<<"\nWhat to do?\n1 = Show example of Complex Number\n2 = Enter Complex Number\n3 = Perform Complex Operations\n4 = Exit\nEnter Choice = ";
        cin>>chc;
        if (chc == 1)
        {
            show_complex();
        }
        else if (chc == 2)
        {
            cout<<"Enter Complex number :\nReal part = ";
            cin>>num1;
            cout<<"Imaginary part = ";
            cin>>img1;
            cmplx(num1, img1);
        }
        else if (chc == 3)
        {
            cout<<"Enter Complex number 1 :\nReal part = ";
            cin>>num1;
            cout<<"Imaginary part = ";
            cin>>img1;
            cout<<"Enter Complex number 2 :\nReal part = ";
            cin>>num2;
            cout<<"Imaginary part = ";
            cin>>img2;
            operate_complx(num1, img1, num2, img2);
        }
        else if (chc == 4)
        {
            cout<<"Exiting...";
            work = 0;
        }
        else
        {
            cout<<"Invalid Choice!\nNow Exiting...";
        }

    }
    return 0;
}

