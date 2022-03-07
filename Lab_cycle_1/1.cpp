/*Write a C++ program to calculate the grades of a list of students with attributes
(Name, Roll_no, Marks of 3 subjects) using class with member functions
input(), calcGrade(), display().*/

#include <iostream>
using namespace std;

class Grades{
    string name;
    int rollno;
    double mark1,mark2,mark3;
    public:
    void input(string a,int b,double c,double d,double e){
        name=a;
        rollno=b;
        mark1=c;
        mark2=d;
        mark3=e;
    }
    char calcGrade(double total){
        if(total>=90){
            return 'A';
        }
        else if(total>=80 && total<90){
            return 'B';
        }
        else if(total>=60 && total<80){
            return 'C';
        }
        else if(total>=40 && total<60){
            return 'D';
        }
        else{
            return 'F';
        }
    }
    void display(){
        cout<<"\n";
        cout<<"Name :"<<name<<", Roll No :"<<rollno<<"\n\n";
        cout<<"Subject 1 :"<<mark1<<", Grade :"<<calcGrade(mark1)<<"\n\n";
        cout<<"Subject 2 :"<<mark2<<", Grade :"<<calcGrade(mark2)<<"\n\n";
        cout<<"Subject 3 :"<<mark3<<", Grade :"<<calcGrade(mark3)<<"\n\n";
    }
};

main(){
	Grades student1;
	Grades student2;
	student1.input("Ram",8081001,67.75,83.50,84.25);
	student2.input("Sam",8081001,43.50,39.75,58.00);
	student1.display();
	student2.display();
}

