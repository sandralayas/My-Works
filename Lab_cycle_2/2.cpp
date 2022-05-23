/*Write a C++ program to design a class representing complex numbers and
having the functionality of performing addition & multiplication of two complex
numbers using operator overloading (Use friend operator functions).*/

#include<iostream>
using namespace std;

class complex{
    float real,image;
    public:
    complex(void){}
    complex(float a,float b){real=a;image=b;}
    friend complex operator+(complex,complex);
    friend complex operator*(complex,complex);
    void output(void){
	char opera=' ';
	if(image>=0)opera='+';
	cout<<real<<opera<<image<<"i";
    }
};

complex operator+(complex c1,complex c2){
    return complex(c1.real+c2.real,c1.image+c2.image);
}

complex operator*(complex c1,complex c2){
    int temp_real,temp_image;
    temp_real=c1.real*c2.real-c1.image*c2.image;
    temp_image=c1.real*c2.image+c2.real*c1.image;
    return complex(temp_real,temp_image);
}

int main(void){
int exit;
do{
    cout<<"\n\n";
    int r_c1,i_c1, r_c2,i_c2;
    cout<<" \n Enter the first complex number : ";
    cin>>r_c1>>i_c1;
    cout<<" \n Enter the second complex number : ";
    cin>>r_c2>>i_c2;
    complex complex1(r_c1,i_c1),complex2(r_c2,i_c2);
    complex1.output();cout<<" <- 1st complex number\n";
    complex2.output();cout<<" <- 2nd complex number\n\n";

    (complex1+complex2).output();cout<<" <- Sum of the complex numbers\n";
    (complex1*complex2).output();cout<<" <- Product of the complex numbers\n";
    cout<<"\n\n";

cout<<"\n Enter '0' to exit the program : ";cin>>exit;
}while(exit);
return 0;
}
