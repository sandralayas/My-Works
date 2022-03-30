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
    Alpha(double a,double b){alpha1=a;alpha2=b;cout<<"\n Alpha object created\n";}

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
    Beta(double a,double b){beta1=a;beta2=b;cout<<"\n Beta object created\n";}

    void show(){
        cout<<"\n The first beta class variable : "<<beta1\
        <<"\n The second beta class variable : "<<beta2<<"\n\n";
    }
};

class Gamma:public Alpha,public Beta{
	private:
    double gamma1,gamma2;

    public:
    Gamma(){}
    Gamma(double a1,double a2,double b1,double b2):\
    Alpha(a1,a2),Beta(b1,b2){
		gamma1=a1+a2;
		gamma2=b1+b2;
		cout<<"\n Gamma object created\n";
	}

	void show(){
        cout<<"\n The first gamma class variable : "<<gamma1\
        <<"\n The second gamma class variable : "<<gamma2<<"\n\n";
    }
};

int main(){

string choice;
double v,w,x,y;

    do{
        cout<<"\n 0. Exit program\
        \n 1. Enter the variables for alpha class\
        \n 2. Enter the variables for beta class\
        \n 3. Display Gamma class\
        \n\n Enter your choice : ";cin>>choice;
        if(choice=="0")break;
        else if(choice=="1"){
            cout<<"\n Enter the variables for alpha class : ";cin>>v>>w;
            Alpha A(v,w);
            A.show();
        }
        else if(choice=="2"){
            cout<<"\n Enter the variables for beta class : ";cin>>x>>y;
            Beta B(x,y);
            B.show();
        }
		else if(choice=="3"){
            Gamma G(v,w,x,y);
            G.show();
        }
        else cout<<"\n Ivalid choice !! \n";
    }while(choice!="0");
return 0;
}
