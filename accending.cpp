//1. Write a C++ program to calculate the standard deviation of a set of numbers.

#include <iostream>
#include <math.h>
using namespace std;

main()
{
    cout<<"\nEnter the number of test cases :";
    int size;
    cin>>size;
    int arr1[size];
    int arr2[size];
    cout<<"\nEnter "<<size<<" numbers having less than 10 digits :\n";
    for(int a=0;a<size;a++){
        cin>>arr1[a];
    }
    int element=arr1[0];
    int position=0;
    for(int b=0;b<size;b++){
        for(int c=0;c<size;c++){
            if(arr1[c]<element){
                position=c;
                element=arr1[c];
            }
        }
        arr2[b]=arr1[position];
        for(int d=position;d<size;d++){
            arr1[d]=arr1[d+1];
        }
        element=arr1[0];
        position=0;
    }
    for(int e=0;e<size;e++){
        cout<<arr2[e]<<", ";
    }
    cout<<"\n\n";
}