#include <iostream>
using namespace std;

main()
{
    cout<<"Enter the size of the  array of numbers :";
    int z;
    cin>>z;
    int a[z];
    for(int j=0;j<z;j++){
        cin>>a[j];
    }
    int w=0;
    int x=a[0];
    int y=0;
    for(int i=0;i<z;i++){
        if(a[i]>=x){
            w=x;
            x=a[i];
            if(w<x){
                if(w>y){
                    y=w;
                }
            }
        }
        else if(a[i]>y){
            y=a[i];
        }

    }
cout<<"Second greatest number :";
cout<<y<<"\n"<<"\n";
return 0;
}