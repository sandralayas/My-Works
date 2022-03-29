/*Write a C++ program to demonstrate the concept of Multiple and Multilevel
inheritance including constructors with parameters.*/

#include <iomanip>
#include <ios>
#include<iostream>
using namespace std;

class Student{
	private:
	string s_name;
	int roll;
	double marks;

	public:
	Student(){}
	Student(string n,int r,double m){
		s_name=n;roll=r;marks=m;
	}

	void show(){
		cout<<s_name<<setw(15)<<setfill(' ')<<roll<<setw(15)<<setfill(' ')<<marks;
	}
	int giveroll(){return roll;}
};

class Teacher{
	private:
	string t_name;
	int id;
	double age;

	public:
	Teacher(){}
	Teacher(string n,int i,int a){
		t_name=n;id=i;age=a;
	}

	void show(){
		cout<<t_name<<setw(15)<<setfill(' ')<<id<<setw(15)<<setfill(' ')<<age;
	}
	int giveid(){return id;}
};

class Class:public Student,public Teacher{
	private:
	int rolls;
	Teacher teacher;
	Student student[30];

	public:
	Class(){}
	Class(string x1,string y1,int x2,int  y2,double x3,\
	double y3):Student(x1,x2,x3),Teacher(y1,y2,y3){}
	Class(Student s[100],Teacher t[100]){

		//input  the students
		int s_count=0;
		cout<<"\n Enter the number of students in a class : ";cin>>rolls;
		int count[rolls];
		cout<<"\n Enter the roll numbers of the students :\n";
		for(int i=0;i<rolls;i++){
			cout<<"\n  "<<i+1<<". ";cin>>count[i];
		}

		//input the teacher
		int the_id;
		cout<<"\n Enter the ID of the teacher in the class : ";cin>>the_id;

		//serching the students
		for(int i=0;i<100;i++){
			//from the list
			for(int j=0;j<rolls;j++){
				if(s[i].giveroll()==count[j]){
					student[s_count]=s[i];
					s_count++;
				}
			}
		}

		//serching the teacher
		for(int i=0;i<100;i++){
			if(t[i].giveid()==the_id){
				teacher=t[i];
			}
		}
	}
	void show(){
		cout<<"\n Name "<<setw(15)<<setfill(' ')<<" Roll_number "\
		<<setw(15)<<setfill(' ')<<" Marks ";
		for(int i=0;i<rolls;i++){
			cout<<"\n  "<<i+1<<". ";student[i].show();
		}
		cout<<"\n\n Name "<<setw(15)<<setfill(' ')<<" ID_number "\
		<<setw(15)<<setfill(' ')<<" Age ";
		teacher.show();
	}
};

int main(){

	string choice;
	string name;int id_roll;double age_marks;
	int std=0,tec=0,cls=0;

	do{

		Student student[100];
		Teacher teacher[100];
		Class classes[100];

		Student *sptr=&student[100];
		Teacher *tprt=&teacher[100];

		cout<<"\n\n Enter '0' to exit \
		\n 1. Add a student \
		\n 2. Add a teacher \
		\n 3. Assign a class \
		\n 4. List of students and teachers \
		\n 5. Display a class \
		\n\n Enter your choice : ";cin>>choice;
		
		if(choice=="0")break;

		else if(choice=="1"){
		cout<<"\n Enter the student's name : ";cin>>name;
		cout<<" Enter the student's roll number : ";cin>>id_roll;
		cout<<" Enter the student's marks : ";cin>>age_marks;
		student[std]=Student(name,id_roll,age_marks);
		student[std].show();
		std++;
		}

		else if(choice=="2"){
		cout<<"\n Enter the teacher's name : ";cin>>name;
		cout<<" Enter the teacher's ID number : ";cin>>id_roll;
		cout<<" Enter the teacher's age : ";cin>>age_marks;
		teacher[tec]=Teacher(name,id_roll,age_marks);
		teacher[tec].show();
		tec++;
		}

		else if(choice=="3"){
			cout<<"\n This is class "<<cls+1<<"\n";
			classes[cls]=Class(sptr,tprt);
			cls++;
		}
		
		else if(choice=="4"){
			cout<<"\n Name "<<setw(15)<<setfill(' ')<<" Roll_number "\
			<<setw(15)<<setfill(' ')<<" Marks ";
			for(int i=0;i<std;i++){
				cout<<"\n  "<<i+1<<". ";student[i].show();
			}
			cout<<"\n\n Name "<<setw(15)<<setfill(' ')<<" ID_number "\
			<<setw(15)<<setfill(' ')<<" Age ";
			for(int i=0;i<tec;i++){
				cout<<"\n  "<<i+1<<". ";teacher[i].show();
			}
		}

		else if(choice=="5"){
			int num;
			cout<<"\n Enter the class you want : ";cin>>num;
			classes[num].show();
		}
		else{
		cout<<"\n Your choice is not given above \n\n";
		}
		
	}while(choice!="0");


return 0;
}
