/*Write a C++ program to design a student class representing student roll no. and
a test class (derived class of student) representing the scores of the student in
various subjects and sports class representing the score in sports. The sports and
test class should be inherited by a result class having the functionality to add
the scores and display the final result for a student. Demonstrate the concept of
Virtual base class on Hybrid inheritance.*/

#include<iostream>
using namespace std;

class Student{
	private:
	int roll;

	public:
	Student(){}
	Student(int r){roll=r;}

    void show(){
        cout<<"\n The roll number of the student is : "<<roll;
    }
};

class Test:public Student{
    private:
    double marks;

    public:
    Test(){}
    Test(int r,double m):Student(r){marks=m;}

    void show(){
        cout<<"\n The score for test of the student is : "<<marks;
    }
};

class Sport:public Student{
    private:
    double marks;

    public:
    Sport(){}
    Sport(int r,double m):Student(r){marks=m;}

    void show(){
        cout<<"\n The score for sports of the student is : "<<marks;
    }
};

class Result:public  Test,virtual public Sport /*,public Student*/{
    private:
    int roll;
    double total;

    public:
    Result(){}
    //Result(int r):Student(r){roll=r;}
    Result(int r,double a,double b):Test(r,a),Sport(r,b){total=a+b;roll=r;}

    void show(){
        cout<<"\n The result of the student "<<roll<<" is : "<<total;
    }
};

int main(){

string choice;
int roll;
double test,sport;

    do{
    
    cout<<"\n 0. Exit the program\
    \n 1. Enter the roll number of the student\
    \n 2. Enter the scores for test\
    \n 3. Enter the scores for sport\
    \n 4. Display the final result\
    \n\n Enter your choice : ";cin>>choice;

    if(choice=="0")break;
    else if(choice=="1"){
        cout<<"\n Enter the roll number of the student : ";cin>>roll;
        Student student(roll);
        student.show();
    }
    else if(choice=="2"){
        cout<<"\n Enter the score for the test : ";cin>>test;
        Result student(test);
        student.show();
    }
    else if(choice=="3"){
        cout<<"\n Enter the score for the sport : ";cin>>sport;
        Result student(sport);
        student.show();
    }
    else if(choice=="4"){
        Result student(test,sport);
        student.show();
    }
    else cout<<"\n Invalid choice\n";

    }while(choice!="0");
return 0;    
}