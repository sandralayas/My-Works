/*Write a Program to swap private data members of classes named as Class1,
Class2 using friend function.*/

#include<iostream>
using namespace std;

class Class2;

class Class1{
    int var1;
    public:
    Class1(){}
    void input(int a){var1=a;}
    void output(){cout<<"the varable 1 : "<<var1<<"\n\n";}
    friend void swap(Class1&,Class2&);
};

class Class2{
    int var2;
    public:
    Class2(){}
    void input(int a){var2=a;}
    void output(){cout<<"the varable 2 : "<<var2<<"\n\n";}
    friend void swap(Class1&,Class2&);
};

void swap(Class1 &a,Class2 &b){
    int temp=a.var1;
    a.var1=b.var2;b.var2=temp;
}

main(){
    Class1 test1;
    Class2 test2;

    int a;
    cout<<"enter the varable 1 : ";
    cin>>a;test1.input(a);cout<<"\n\n";

    cout<<"enter the varable 2 : ";
    cin>>a;test2.input(a);cout<<"\n\n";

    test1.output();test2.output();

    swap(test1,test2);

    test1.output();test2.output();
}