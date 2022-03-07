/*Create a class TIME with members hours, minutes, seconds. Take input, add
two time objects by passing objects to function and display result.*/

#include<iostream>
using namespace std;

class Time{
    int mins;
    int hours;
    public:
    void input(int a,int b){mins=a;hours=b;}
    void output(){cout<<"\n\n"<<hours<<" hours and "<<mins<<" minutes"<<"\n\n";}
    void adding(Time a,Time b){
        mins=a.mins+b.mins;
        hours=mins/60;
        mins=mins%60;
        hours=hours+a.hours+b.hours;
    }
};

main(){
    int x,y;Time t1,t2,sum;
    cout<<"enter the minutes :";
    cin>>x;
    cout<<"enter the hours :";
    cin>>y;
    t1.input(x,y);

    cout<<"enter the minutes :";
    cin>>x;
    cout<<"enter the hours :";
    cin>>y;
    t2.input(x,y);

    t1.output();t2.output();

    sum.adding(t1,t2);sum.output();
}