/*Write a C++ program to demonstrate the use of pure virtual functions and
abstract base classes.*/

#include<iostream>
using namespace std;

//absrtact class
class Person{
    private:
    int age;

    public:
    Person(){}
    Person(int a){age=a;}
    virtual void display()=0;

};

class Teacher:virtual public Person{
    private:
	int age;
    int id;

    public:
    Teacher(){}
    Teacher(int a,int i):Person(a){id=i,age=a;}

    void display(){
		cout<<"\n The age of the teacher : "<<age;
        cout<<"\n The ID of the teacher : "<<id<<"\n";
    }

};

class Student:virtual public Person{
    private:
	int age;    
	int roll;

    public:
    Student(){}
    Student(int a,int r):Person(a){roll=r,age=a;}

    void display(){
		cout<<"\n The age of the student : "<<age;
        cout<<"\n The roll number of the student : "<<roll<<"\n";
    }

};

class Classes:public Student,public Teacher{
    private:
    int code,id,age1,age2,roll;

    public:
    Classes(){}
    Classes(int a1,int a2,int i,int r,int c):Person(a1),Teacher(a1,i),Student(a2,r){
		code=c;
		id=i;age1=a1;roll=r;age2=a2;
		}
	bool check(int c){
		if(code==c) return true;
		else return false;
	}
    void display(){
		cout<<"\n The class code : "<<code;
		cout<<"\n\n The ID of the class teacher : "<<id;
		cout<<"\n The age of the teacher : "<<age1;
		cout<<"\n The roll number of the student in the class : "<<roll;
		cout<<"\n The age of the student : "<<age2;
	}
};

// main program

int main(){
    Person *_test;
	Classes _class[10];

    string choice;
    int a1,a2,id,roll,code;
	int num=0;

do{
    cout<<"\n\n Enter '0' to exit the program\
    \n\n 1. Enter details of a teacher\
    \n 2. Enter details of a student\
    \n 3. Assign the class for the entered details\
    \n 4. Display the class\
    \n\n Enter your choice : ";cin>>choice;

    if(choice=="0")break;

    else if(choice=="1"){
		cout<<"\n Enter the age : ";cin>>a1;
        cout<<" Enter the ID : ";cin>>id;
        Teacher _teacher(a1,id);
        _test=&_teacher;
        _test->display();
    }
    else if(choice=="2"){
		cout<<"\n Enter the age : ";cin>>a2;
        cout<<" Enter the roll number : ";cin>>roll;
        Student _student(a2,roll);
        _test=&_student;
        _test->display();
    }
	else if(choice=="3"){
		cout<<"\n Enter the class code : ";cin>>code;
		Classes _temp(a1,a2,id,roll,code);
		_class[num]=_temp;
		_test=&_class[num];
		num++;
	}	
	else if(choice=="4"){
		int req;
		cout<<"\n Enter the class code : ";cin>>code;
		for(int i=0;i<=num;i++){
			if(_class[i].check(code)){
				req=i;break;
			}
		}
		_class[req].display();
	}
    else cout<<"\n Invalid Choice !!\n";

}while(choice!="0");
    
return 0;
}
