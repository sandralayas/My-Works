/*Write a Program to swap private data members of classes named as Class1,
Class2 using friend function.*/

#include<iostream>
using namespace std;

class Class2;

class Class1{
    int var1;
    public:
    Class1(void){}
    void input(int a){var1=a;}
    void output(void){cout<<" The variable of class 1 : "<<var1<<"\n\n";}
    friend void swap(Class1&,Class2&);
};

class Class2{
    int var2;
    public:
    Class2(void){}
    void input(int a){var2=a;}
    void output(){cout<<" The variable of class 2 : "<<var2<<"\n\n";}
    friend void swap(Class1&,Class2&);
};

void swap(Class1 &a,Class2 &b){
    int temp=a.var1;
    a.var1=b.var2;b.var2=temp;
}

int main(void){
    Class1 test1;
    Class2 test2;

    int a;
    cout<<" Enter the variable of class 1 : ";
    cin>>a;test1.input(a);cout<<"\n\n";

    cout<<" Enter the variable of class 2 : ";
    cin>>a;test2.input(a);cout<<"\n\n";

    test1.output();test2.output();

    swap(test1,test2);

    test1.output();test2.output();
return 0;
}
