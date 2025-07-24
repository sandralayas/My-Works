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
	char opera=' ';
	if(imaginary>=0)opera='+';
        cout<<"\n"<<real<<opera<<imaginary<<" j\n\n";
    }
Complex sum(Complex complex1,Complex complex2){
    Complex complex3;
    complex3.real=complex1.real+complex2.real;
    complex3.imaginary=complex1.imaginary+complex2.imaginary;
    return complex3;
}

int main(void){
int user;
do{
    double x,y;Complex complex[2];

    for(int i=0;i<2;i++){
    cout<<"\n Enter the real part :";
    cin>>x;
    cout<<" Enter the imaginary part :";
    cin>>y;
	complex[i].input(x,y);
    }

    cout<<"\n The first complex number :";complex[0].output();
    cout<<"\n The second complex number :";complex[1].output();

    cout<<"\n The added complex number :";sum(complex[0],complex[1]).output();

cout<<" Enter '0' to exit the program : ";cin>>user;
}while(user!=0);
return 0;
}

