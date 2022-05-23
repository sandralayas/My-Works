//Write a C++ program to find the factorial of a given number.

#include <iostream>
#include <math.h>
using namespace std;

int factorial(int num){
    if(num==1){
        return 1;
    }
    else{
        return factorial(num-1)*num;
    }
}

int main()
{
    cout<<"\nEnter the number of test cases :";
    int size;
    int element=0;
    cin>>size;
    int a[size];
    cout<<"\nEnter "<<size<<" numbers having less than 10 digits :\n";
    for(int j=0;j<size;j++){
        cin>>a[j];
    }
    for(int i=0;i<size;i++){
        element=a[i];
        cout<<"the factorial of "<<element<<" is "<<factorial(element)<<"\n\n";
    }
    return 0;
}
