/*Create a class TIME with members hours, minutes, seconds. Take input, add
two time objects by passing objects to function and display result.*/

#include<iostream>
using namespace std;

class Time{
    int hours,mins,secs;
    public:
    void input(int a,int b,int c){hours=a;mins=b;secs=c;}
    void output(void){cout<<hours<<" hours and "<<mins<<\
				" minutes and "<<secs<<" seconds\n";}
    void adding(Time a,Time b){

	secs=a.secs+b.secs;
	mins=secs/60;
	secs=secs%60;
	mins=mins+a.mins+b.mins;
        hours=mins/60;
        mins=mins%60;
        hours=hours+a.hours+b.hours;
    }
};

int main(void){
int user;
do{
    int x,y,z;Time t1,t2,sum;
    
    cout<<" Enter the hours :";
    cin>>x;
    cout<<" Enter the minutes :";
    cin>>y;
    cout<<" Enter the seconds :";
    cin>>z;
    t1.input(x,y,z);
    cout<<"\n\n";
    cout<<" Enter the hours :";
    cin>>x;
    cout<<" Enter the minutes :";
    cin>>y;
    cout<<" Enter the seconds :";
    cin>>z;
    t2.input(x,y,z);

    cout<<"\n The first time :";t1.output();
    cout<<"\n The second time :";t2.output();

    sum.adding(t1,t2);cout<<"\n The added time :";sum.output();

	cout<<" \nEnter '0' to exit the programe : ";cin>>user;
}while(user!=0);
return 0;
}

