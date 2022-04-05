/*Write a C++ program to design a class having static member function named
showcount() which has the property of displaying the number of objects created
of the class.*/

#include<iostream>
using namespace std;

class Book{
    string name,author;
    int year,pages;
    
    static int number;
    public:
    Book(void){}
    void input(void){
        string a,b;int c,d;
	cout<<"\n\n Enter the name of the book : ";cin>>a;name=a;
	cout<<" Enter the year of publication : ";cin>>c;year=c;
	cout<<" Enter the author of the book : ";cin>>b;author=b;
	cout<<" Enter the number of pages : ";cin>>d;pages=d;
	number++;
    }
    void output(void){
	cout<<"\n\n "<<name<<"  "<<year<<"  "<<author<<"  "<<pages<<"\n\n";
	}
    static void showcount(void){cout<<"\n\n The number of objects : "\
<<number<<"\n";}
};



int Book::number;

int main(void){
int exit,num=0;
Book books[20];
do{
    books[num].input();Book::showcount();books[num].output();
    num++;

cout<<"\n Enter '0' to exit the program : ";cin>>exit;
}while(exit);
return 0;
}
