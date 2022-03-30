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
	
    bool check_roll(int r){
        if(roll==r) return true;
        return false;
    }
    void show_student(){
        cout<<"\n The roll number of the student is : "<<roll;
        cout<<"\n";
    }
};

class Test:virtual public Student{
    private:
    double test;

    public:
    Test(){}
    Test(int r,double m):Student(r){test=m;}

    void show_test(){
        cout<<"\n The score for test of the student is : "<<test;
        cout<<"\n";
    }
};

class Sport:virtual public Student{
    private:
    double sport;

    public:
    Sport(){}
    Sport(int r,double m):Student(r){sport=m;}

    void show_sport(){
        cout<<"\n The score for sports of the student is : "<<sport;
        cout<<"\n";
    }
};

class Result:public  Test, public Sport{
    private:
    int roll;
    double total;

    public:
    Result(){}
    Result(int r,double a,double b):Student(r),Test(r,a),Sport(r,b){total=a+b;roll=r;}

    void show(){
        cout<<"\n The result of the student "<<roll<<" is : "<<total;
        cout<<"\n";
    }
};

int main(){

string choice;

int roll,num=0,count;double test,sport;

cout<<"\n Enter the number of students : ";cin>>count;
Result students[count];
Result student(0,0,0);

while(num!=count){
    cout<<"\n Enter the roll number of student "<<num+1<<" : ";cin>>roll;
    cout<<" Enter the score for the test : ";cin>>test;
    cout<<" Enter the score for the sport : ";cin>>sport;cout<<"\n";

    Result temp(roll,test,sport);
    students[num]=temp;num++;
}

cout<<"\n All the details of students saved\
\n Enter the roll number of the student to check : ";cin>>roll;
    do{

    while(true){
        num=count-1;
        while(num>=0){
            if(students[num].check_roll(roll)){
                student=students[num];break;
            }
            num--;
        }
        if(num==-1){
            cout<<"\n Invalid Roll number\
            \n Enter the roll number again : ";cin>>roll;
        }
        else break;
    }


    cout<<" \n 0. Exit the program\
            \n 1. Display the scores for test\
            \n 2. Display the scores for sport\
            \n 3. Display the final result\
            \n 4. Change the student to check\
            \n\n  Enter your choice : ";cin>>choice;

    if(choice=="0")break;
    else if(choice=="1"){
        student.show_student();student.show_test();
    }
    else if(choice=="2"){
        student.show_student();student.show_sport();
    }
    else if(choice=="3"){
        student.show_student();student.show();
    }
    else if(choice=="4"){
        cout<<"\n Enter the roll number of the student to check : ";cin>>roll;
    }
    else cout<<"\n Invalid choice !!\n";

    }while(choice!="0");
return 0;    
}
