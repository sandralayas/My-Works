/*Write a program to perform addition of two complex numbers using constructor
overloading. The first constructor which takes no argument is used to create
objects which are not initialized, second which takes one argument is used to
initialize real and imag parts to equal values and third which takes two
argument is used to initialized real and imag to two different values.*/

#include<iostream>
using namespace std;

class Complex{
    float x;
    float y;
    public:
    Complex(void){x=0;y=0;}
    Complex(float a){x=a;y=a;}
    Complex(float a,float b){x=a;y=b;}
    Complex operator+(Complex);
	
	//void input(int a,int b){x=a;y=b;}	
	
    void display(void){
	char opera=' ';
	if(y>=0)opera='+';
	cout<<x<<opera<<y<<"i"<<"\n\n";
    }

};

Complex Complex::operator+(Complex c){
    return Complex(x+c.x,y+c.y);
}

int main(void){
int user,exit,num=0;
Complex complex[2];
do{
while(num!=2){
    cout<<"\n\n Complex number "<<num+1<<endl;
    cout<<"\n 1. Non initialized complex number\n";
    cout<<" 2. Equal imaginary and real part\n";
    cout<<" 3. Unequal imaginary and real part\n\n Enter your choice : ";
	cin>>user;

    switch(user){

    case 1:
    complex[num]=Complex();num++;break;

    case 2:
    float x;
    cout<<" Enter the equal value : ";cin>>x;
    complex[num]=Complex(x);num++;break;
    
    case 3:
    float y;
    cout<<"\n Enter the real part :";cin>>x;
    cout<<" Enter the imaginary part :";cin>>y;
    complex[num]=Complex(x,y);num++;break;

    default:"\n Wrong Option\n";break;
    }
}
    cout<<"\n The first complex number :";complex[0].display();
    cout<<"\n The second complex number :";complex[1].display();
    complex[2]=complex[0]+complex[1];cout<<"\n The added complex number :";
	complex[2].display();

    num=0;
cout<<"\n Enter '0' to exit the program : ";cin>>exit;
}while(exit!=0);
return 0;
}
