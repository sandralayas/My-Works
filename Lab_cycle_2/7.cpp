/*Write a C++ program illustrating how the constructors are implemented and the
order in which they are called when the classes are inherited. Use three classes
named Alpha, Beta and Gamma such that alpha and beta are base classes and
gamma is a derived class inheriting alpha & beta.*/

#include<iostream>
using namespace std;

class Alpha{
    private:
    double alpha1,alpha2;

    public:
    Alpha(){}
    Alpha(double a,double b){alpha1=a;alpha2=b;}

    void show(){
        cout<<"\n The first alpha class variable : "<<alpha1\
        <<"\n The second alpha class variable : "<<alpha2<<"\n\n";
    }
};

class Beta{
    private:
    double beta1,beta2;

    public:
    Beta(){}
    Beta(double a,double b){beta1=a;beta2=b;}

    void show(){
        cout<<"\n The first beta class variable : "<<beta1\
        <<"\n The second beta class variable : "<<beta2<<"\n\n";
    }
};

class Gamma:public Alpha,public Beta{
    public:
    Gamma(){}
    Gamma(double a1,double a2,double b1,double b2):\
    Alpha(a1,a2),Beta(b1,b2){}    
};

int main(){

string choice;
double x,y;

    do{
        cout<<"\n 0. Exit program\
        \n 1. Enter the variables for alpha class\
        \n 2. Enter the variables for beta class\
        \n 3. Gamma class ??\
        \n\n Enter your choice : ";cin>>choice;
        if(choice=="0")break;
        else if(choice=="1"){
            cout<<"\n Enter the variables for alpha class : ";cin>>x>>y;
            Alpha A(x,y);
            A.show();
        }
        else if(choice=="2"){
            cout<<"\n Enter the variables for beta class : ";cin>>x>>y;
            Beta B(x,y);
            B.show();
        }
        else cout<<"\n Ivalid choice !! \n";
    }while(choice!="0");
return 0;
}