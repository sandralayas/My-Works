/*Write a C++ program to define classes Shapes, Circle, Square, Ellipse and
Rectangle with member functions to get the values for finding corresponding
areas and print the same. Utilize the concept of Abstract Class and Runtime
polymorphism to solve the problem.*/

#include<iostream>
using namespace std;

//Abstact class
class Shape{
	private:
	double dimention1,dimention2;

	public:
	Shape(){}
	Shape(double side1,double side2){
		dimention1=side1;dimention2=side2;
	}

	virtual void show()=0;
};

class Triangle:public Shape{
	private:
	double base,height;

	public:
	Triangle(){}
	Triangle(double a,double b):Shape(a,b){
		base=a;height=b;
	}

	void show(){
		cout<<"\n The base length : "<<base;
		cout<<"\n The height length : "<<height;
		cout<<"\n The area of the triangle : "<<base*height*0.5<<"\n\n";
	}
};

class Rectangle:public Shape{
	private:
	double side1,side2;

	public:
	Rectangle(){}
	Rectangle(double a,double b):Shape(a,b){
		side1=a;side2=b;
	}

	void show(){
		cout<<"\n The first side1 : "<<side1;
		cout<<"\n The second side2 : "<<side2;
		cout<<"\n The area of the rectangle : "<<side1*side2<<"\n\n";
	}
};

class Square:public Shape{
	private:
	double side;

	public:
	Square(){}
	Square(double a,double b):Shape(a,b){
		side=a;
	}

	void show(){
		cout<<"\n The side : "<<side;
		cout<<"\n The area of the square : "<<side*side<<"\n\n";
	}
};

class Circle:public Shape{
	private:
	double radius;

	public:
	Circle(){}
	Circle(double a,double b):Shape(a,b){
		radius=a;
	}

	void show(){
		cout<<"\n The radius : "<<radius;
		cout<<"\n The area of the circle : "<<3.14159265359*radius*radius\
		<<"\n\n";
	}
};

class Ellipse:public Shape{
	private:
	double side1,side2;

	public:
	Ellipse(){}
	Ellipse(double a,double b):Shape(a,b){
		side1=a;side2=b;
	}

	void show(){
		cout<<"\n The major axis : "<<side1;
		cout<<"\n The minor axis : "<<side2;
		cout<<"\n The area of the rectangle : "<<3.14159265359*side1*side2\
		<<"\n\n";
	}
};

int main(){

	string choice;
	double side1,side2;
	Shape *_shape;

	do{
		cout<<"\n\n Enter '0' to exit \
		\n 1. Triangle \
		\n 2. Rectangle \
		\n 3. Square \
        \n 4. Circle \
        \n 5. Ellipse \
		\n\n Enter your choice : ";cin>>choice;
		
		if(choice=="0")break;

		else if(choice=="1"){
		cout<<"\n Enter the base : ";cin>>side1;
		cout<<" Enter the height : ";cin>>side2;
		Triangle _triangle(side1,side2);
        _shape=&_triangle;
		_shape->show();
		}

		else if(choice=="2"){
		cout<<"\n Enter the first side : ";cin>>side1;
		cout<<" Enter the second side : ";cin>>side2;
		Rectangle _rectangle(side1,side2);
        _shape=&_rectangle;
		_shape->show();
		}

		else if(choice=="3"){
		cout<<"\n Enter the side : ";cin>>side1;
		Square _square(side1,side2);
        _shape=&_square;
		_shape->show();
		}

        else if(choice=="4"){
		cout<<"\n Enter the radius : ";cin>>side1;
		Circle _circle(side1,side2);
        _shape=&_circle;
		_shape->show();
		}

        else if(choice=="5"){
		cout<<"\n Enter the major axis : ";cin>>side1;
        cout<<" Enter the minor axis : ";cin>>side2;
		Ellipse _ellipse(side1,side2);
        _shape=&_ellipse;
		_shape->show();
		}

		else{
		cout<<"\n Your choice is not given above \n\n";
		}
		
	}while(choice!="0");


return 0;
}
