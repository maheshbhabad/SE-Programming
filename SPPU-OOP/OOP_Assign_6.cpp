/*
Name: Sahil S. Naik
PRN: S20111006
Subject: OOP Lab
Assignment: #6
*/

#include <algorithm>
#include <iostream>
using namespace std;

void show(int a[], int arraysize)
{
    for (int i = 0; i < arraysize; ++i)
        cout << a[i] << ",";
}

int main()
{
    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int asize = sizeof(a) / sizeof(a[0]);
    cout << "The array is : \n";
    show(a, asize);
    cout << "\n\nLet's say we want to search for 2";
    cout << "\nwe first sort the array"<<endl;
    cout << "\nThe array before sorting is : \n";
    show(a, asize);
    sort(a, a + asize);
    cout << "\n\nThe array after sorting is :\n";
    show(a, asize);
    cout<<endl;
    cout << "\nNow, we do the binary search";
    if (binary_search(a, a + 10, 2))
        cout << "\nElement 2 found in the array";
    else
        cout << "\nElement not found in the array";

    cout << "\n\nNow, say we want to search for 10";
    if (binary_search(a, a + 10, 10))
        cout << "\nElement found in the array"<<endl;
    else
        cout << "\nElement 10 not found in the array"<<endl;
    return 0;
}
