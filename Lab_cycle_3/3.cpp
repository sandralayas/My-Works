/*Write a C++ program to demonstrate the use of exception handling.*/

#include<iostream>
using namespace std;

int main(){

string exit;
double divident,divisor;

    do{
        cout<<"\n Enter the divident : ";cin>>divident;
        cout<<" Enter the divisor : ";cin>>divisor;
        try{
            if(divisor==0){
                cout<<"\n Zero error";
                throw divisor;
            }
            else cout<<"\n The quotient is : "<<divident/divisor<<"\n";
        }
        catch(double divisor){
            cout<<"\n Exception Caught !\
            \n Divisor is : "<<divisor<<"\n";
        }
        cout<<"\n Enter '0' to exit the program : ";cin>>exit;
    }while(exit!="0");

return 0;
}