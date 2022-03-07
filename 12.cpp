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
    void output();
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
main(){
    Complex complex1,complex2;
    complex1.input(1.1,2.2);
    complex2.input(1.1,2.2);
    complex1.output();
    complex2.output();
    sum(complex1,complex2).output();
}