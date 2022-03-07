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
    double s=a+b+c*0.5;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

main(){
    cout<<"\n\npralleogram :"<<area(2.1,2.1);
    cout<<"\n\nrectangle :"<<area(2,3);
    cout<<"\n\nsquare :"<<area(2.5);
    cout<<"\n\ncircle :"<<area(2);
    cout<<"\n\ntriangle :"<<area(2.0,3.0,4.0)<<"\n\n";
}