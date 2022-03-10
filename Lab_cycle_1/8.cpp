/*Write a program to perform addition of two complex numbers using constructor
overloading. The first constructor which takes no argument is used to create
objects which are not initialized, second which takes one argument is used to
initialize real and imag parts to equal values and third which takes two
argument is used to initialized real and imag to two different values.*/

#include<iostream>
using namespace std;

class complex{
    float x;
    float y;
    public:
    complex(void){x=0;y=0;}
    complex(float a){x=a;y=a;}
    complex(float a,float b){x=a;y=b;}
    complex operator+(complex);
	
	void input(int a,int b){x=a;y=b;}	
	
    void display(void){cout<<x<<"+"<<y<<"i"<<"\n\n";}
};
complex complex::operator+(complex c){
    return complex(x+c.x,y+c.y);
}

int main(void){
    float x,y;complex complex[2];

    for(int i=0;i<2;i++){
    cout<<"\n Enter the real part :";
    cin>>x;
    cout<<" Enter the imaginary part :";
    cin>>y;
	complex[i].input(x,y);
    }

    cout<<"\n The first complex number :";complex[0].display();
    cout<<"\n The second complex number :";complex[1].display();

    complex[2]=complex[0]+complex[1];cout<<"\n The added complex number :";complex[2].display();
return 0;
}
