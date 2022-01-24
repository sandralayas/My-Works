//1. Write a C++ program to calculate the standard deviation of a set of numbers.

#include <iostream>
#include <math.h>
using namespace std;

main()
{
    cout<<"\nEnter the number of test cases :";
    int size;
    int sum_no=0;
    int sum_sqr=0;
    cin>>size;
    int a[size];
    cout<<"\nEnter "<<size<<" numbers having less than 10 digits :\n";
    for(int j=0;j<size;j++){
        cin>>a[j];
    }
    int x=0;
    for(int i=0;i<size;i++){
        x=a[i];
        sum_no+=x;
    }
    int mean=sum_no/size;
    for(int i=0;i<size;i++){
        x=a[i];
        sum_sqr+=pow((x-mean),2);
    }
    cout<<"\nThe mean deviation is :"<<sqrt(sum_sqr/size)<<endl;
}