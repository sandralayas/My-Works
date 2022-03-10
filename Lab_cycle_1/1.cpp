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
        
        cout<<name<<"   "<<rollno<<"   "<<calcGrade((mark1+mark2+mark3)/3)<<"\n";
    }
};

int main(void){
	int count,rollno;string name;double mark1,mark2,mark3; 
	cout<<"\n Enter the number of students : ";cin>>count;
	Grades student[count];
	cout<<"\n Slno    Name    Rollno    Mark1   Mark2   Mark3\n";
	for(int i=0;i<count;i++){
		cout<<" "<<i+1<<".  "; 
		cin>>name>>rollno>>mark1>>mark2>>mark3;
		student[i].input(name,rollno,mark1,mark2,mark3);
	}
	cout<<"\n Name    Rollno    Grade\n";
	for(int i=0;i<count;i++){student[i].display();}
return 0;
}

