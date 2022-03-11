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
        else if(total>=50 && total<60){
            return 'D';
        }
        else{
            return 'F';
        }
    }
    void display(void){
        
        cout<<name<<"       "<<rollno<<"         "<<calcGrade((mark1+mark2+mark3)/3)<<"         "<<(mark1+mark2+mark3)/3<<"\n";
    }
};

int main(void){

int user,num,count=0;
string name;

Grades student[20];

do{
	cout<<"\n1) Add students";
        cout<<"\n2) Calculate grades";
        cout<<"\n Enter '0' to stop the program \n\n";

        
	cout<<"\n\n Enter your choice : ";
	cin>>user;

switch(user){
    case 0:break;
    case 1:
	int rollno;
	double mark1,mark2,mark3; 
	cout<<"\n Name    Rollno    Mark1   Mark2   Mark3\n"; 
	cin>>name>>rollno>>mark1>>mark2>>mark3;
	student[count].input(name,rollno,mark1,mark2,mark3);
	count++;
    	break;
    case 2:
	cout<<"\n Name    Rollno    Grade    Average\n";
	for(int i=0;i<count;i++){student[i].display();}
    	break;

    default:
	cout<<"\n Wrong choice\n";
	break;
}}while(user!=0);
      return 0;
}

