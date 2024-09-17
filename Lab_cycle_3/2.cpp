/*Write a C++ program to demonstrate the use of class templates.*/

#include <iostream>
using namespace std;

template <typename T>T Add(T x, T y){return x+y;}
template <typename T>T Substact(T x, T y){return x-y;}
template <typename T>T Multiply(T x, T y){return x*y;}
template <typename T>T Divide(T x, T y){return x/y;}

int main(){
    string choice;
do{
    cout<<"\n\n Enter 'exit' to exit the program\
    \n Enter '1' to output in integer value\
    \n Enter '2' to out put in decimal value\
    \n\n Enter your choice : ";cin>>choice;

    if(choice=="exit")break;

    else if(choice=="1"){
        double digit_1,digit_2;

        do{
        cout<<"\n\n Enter '0' to return to main program\
        \n\n 1. Addition\
        \n 2. Substraction\
        \n 3. Multiplication\
        \n 4. Division\
        \n\n Enter your choice : ";cin>>choice;

        if(choice=="0")break;

        else if(choice=="1"){
            cout<<"\n Enter the 1st digit : ";cin>>digit_1;
            cout<<" Enter the 2nd digit : ";cin>>digit_2;
            cout<<"\n The sum is : "<<Add<int>(digit_1,digit_2);
        }
        else if(choice=="2"){
            cout<<"\n Enter the 1st digit : ";cin>>digit_1;
            cout<<" Enter the 2nd digit : ";cin>>digit_2;
            cout<<"\n The diffrence is : "<<Substact<int>(digit_1,digit_2);
        }
        else if(choice=="3"){
            cout<<"\n Enter the 1st digit : ";cin>>digit_1;
            cout<<" Enter the 2nd digit : ";cin>>digit_2;
            cout<<"\n The product is : "<<Multiply<int>(digit_1,digit_2);
        }
        else if(choice=="4"){
            cout<<"\n Enter the 1st digit : ";cin>>digit_1;
            cout<<" Enter the 2nd digit : ";cin>>digit_2;
            cout<<"\n The quoient is : "<<Divide<int>(digit_1,digit_2);
        }
        else cout<<"\nInvalid Choice !!\n";
        }while(choice!="0");
    }

    else if(choice=="2"){
        double digit_1,digit_2;

        do{
        cout<<"\n\n Enter '0' to return to main program\
        \n\n 1. Addition\
        \n 2. Substraction\
        \n 3. Multiplication\
        \n 4. Division\
        \n\n Enter your choice : ";cin>>choice;

        if(choice=="0")break;

        else if(choice=="1"){
            cout<<"\n Enter the 1st digit : ";cin>>digit_1;
            cout<<" Enter the 2nd digit : ";cin>>digit_2;
            cout<<"\n The sum is : "<<Add<double>(digit_1,digit_2);
        }
        else if(choice=="2"){
            cout<<"\n Enter the 1st digit : ";cin>>digit_1;
            cout<<" Enter the 2nd digit : ";cin>>digit_2;
            cout<<"\n The diffrence is : "<<Substact<double>(digit_1,digit_2);
        }
        else if(choice=="3"){
            cout<<"\n Enter the 1st digit : ";cin>>digit_1;
            cout<<" Enter the 2nd digit : ";cin>>digit_2;
            cout<<"\n The product is : "<<Multiply<double>(digit_1,digit_2);
        }
        else if(choice=="4"){
            cout<<"\n Enter the 1st digit : ";cin>>digit_1;
            cout<<" Enter the 2nd digit : ";cin>>digit_2;
            cout<<"\n The quoient is : "<<Divide<double>(digit_1,digit_2);
        }
        else cout<<"\nInvalid Choice !!\n";
        }while(choice!="0");
    }

    else cout<<"\nInvalid Choice !!\n";

}while(choice!="exit");
    
return 0;
}

