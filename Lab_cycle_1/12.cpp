/*Write a Program to design a class complex to represent complex numbers. The
complex class should use an external function (use it as a friend function) to
add two complex numbers. The function should return an object of type
complex representing the sum of two complex numbers.*/

#include <iostream>
#include <string>
using namespace std;

class Complex{
    double real;
    double imaginary;
    public:
    void input(double a,double b){
        real=a;
        imaginary=b;
    }
    friend Complex sum(Complex,Complex);
    void output(void);
};
void Complex::output(){
        cout<<"\n"<<real<<"+"<<imaginary<<" j\n\n";
    }
Complex sum(Complex complex1,Complex complex2){
    Complex complex3;
    complex3.real=complex1.real+complex2.real;
    complex3.imaginary=complex1.imaginary+complex2.imaginary;
    return complex3;
}

int main(void){
    double x,y;Complex complex[2];

    for(int i=0;i<2;i++){
    cout<<"\nenter the real part :";
    cin>>x;
    cout<<"enter the imaginary part :";
    cin>>y;
	complex[i].input(x,y);
    }

    cout<<"\n the first complex number :";complex[0].output();
    cout<<"\n the second complex number :";complex[1].output();

    cout<<"\n the added complex number :";sum(complex[0],complex[1]).output();
return 0;
}
