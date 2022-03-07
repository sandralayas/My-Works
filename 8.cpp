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
    complex(){}
    complex(float a){x=a;y=a;}
    complex(float a,float b){x=a;y=b;}
    complex operator+(complex);
    void display(){cout<<x<<"+"<<y<<"i"<<"\n\n";}
};
complex complex::operator+(complex c){
    return complex(x+c.x,y+c.y);
}
main(){
    complex c1(1.1,2.2),c2(3.3,4.4),c3;
    c3=c1+c2;
    c1.display();
    c2.display();
    c3.display();
}