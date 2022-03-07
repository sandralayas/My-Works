/*Write a C++ program to design a class having static member function named
showcount() which has the property of displaying the number of objects created
of the class.*/

#include<iostream>
using namespace std;

class Class{
    string object;
    static int number;
    public:
    void input(){
        string a;cout<<"\n\nenter the object : ";cin>>a;
        object=a;number++;
    }
    void output(){cout<<"the object : "<<object<<"\n\n";}
    static void showcount(){cout<<"the number of objects : "<<number<<"\n\n";}
};

int Class::number;

main(){
    Class object1,object2,object3;

    object1.input();Class::showcount();object1.output();
    object2.input();Class::showcount();object2.output();
    object3.input();Class::showcount();object3.output();
}