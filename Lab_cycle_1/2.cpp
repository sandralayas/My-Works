/*Write a C++ program to calculate the area of different shapes like Rectangle,
Square etc (at least 5 shapes) using overloaded function area().*/

#include <iostream>
#include <cmath>
using namespace std;

//pralleogram
double area(double base,double height){return base*height;}
//rectangle
int area(int length,int breadth){return length*breadth;}
//square
double area(double side){return side*side;}
//circle
float area(int side){return side*side*3.14159265359;}
//triangle
double area(double a,double b,double c){
    double s=(a+b+c)*0.5;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(void){
    string user;
    while(user!="exit"){
        cout<<"\n\na) Pralleogram";
        cout<<"\nb) Rectangle";
        cout<<"\nc) Square";
        cout<<"\nd) Circle";
        cout<<"\ne) Triangle";
        cout<<"\n Enter 'exit' to stop the program \n\n";

        cout<<"\n\n Enter your choice : ";cin>>user;
        if(user=="a"){
		int base,height;
		cout<<" Enter the base and height : ";cin>>base>>height;
		cout<<" Area of Pralleogram: "<<area(base,height)<<"\n";}
        else if(user=="b"){
		double base,height;
		cout<<" Enter the base and height : ";cin>>base>>height;
		cout<<" Area of Rectangle: "<<area(base,height)<<"\n";}
        else if(user=="c"){
		double base;
		cout<<" Enter the side : ";cin>>base;
		cout<<" Area of Square: "<<area(base)<<"\n";}
        else if(user=="d"){
		int base;
		cout<<" Enter the radius : ";cin>>base;
		cout<<" Area of Circle: "<<area(base)<<"\n";}
        else if(user=="e"){
		int s1,s2,s3;
		cout<<" Enter the three sides : ";cin>>s1>>s2>>s3;
		cout<<" Area of Triangle: "<<area(s1,s2,s3)<<"\n";}
        else if(user!="exit"){cout<<" You have entered a wrong opt \n\n";}
    }
return 0;
}
