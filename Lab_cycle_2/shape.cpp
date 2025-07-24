/*Write a C++ program to demonstrate the concept of Multiple and Multilevel
inheritance including constructors with parameters.*/

#include<iostream>
using namespace std;

class Shape{
	private:
	double dimention1,dimention2;

	public:
	Shape(){}
	Shape(double side1,double side2){
		dimention1=side1;dimention2=side2;
	}

	void show(){
		cout<<"\n The first dimention : "<<dimention1;
		cout<<"\n\n The second dimention : "<<dimention2;
	}
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

int main(){

	string choice;
	double side1,side2;

	do{
		cout<<"\n\n Enter '0' to exit \
		\n 1. Triangle \
		\n 2. Rectangle \
		\n 3. Square \
		\n\n Enter your choice : ";cin>>choice;
		
		if(choice=="0")break;

		else if(choice=="1"){
		cout<<"\n Enter the base : ";cin>>side1;
		cout<<" Enter the height : ";cin>>side2;
		Triangle triangle(side1,side2);
		triangle.show();
		}

		else if(choice=="2"){
		cout<<"\n Enter the first side : ";cin>>side1;
		cout<<" Enter the second side : ";cin>>side2;
		Rectangle rectangle(side1,side2);
		rectangle.show();
		}

		else if(choice=="3"){
		cout<<"\n Enter the side : ";cin>>side1;
		Square square(side1,side2);
		square.show();
		}

		else{
		cout<<"\n Your choice is not given above \n\n";
		}
		
	}while(choice!="0");


return 0;
}