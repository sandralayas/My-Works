//Write a C++ program to generate the Fibonacci series.

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout<<"\nEnter the number of terms needed :";
    int limit;
    cin>>limit;
    int pre=0;
    int suc=1;
    while(limit!=0){
        cout<<pre<<", ";
        int temp;
        temp=pre;
        pre=suc;
        suc=temp+suc;
        limit-=1;
    }
    cout<<"\n\n";
    return 0;
}
