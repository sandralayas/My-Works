/*Write a C++ program using class to process shopping list for a Departmental
Store. The list include details such as the Code-no and price of each item and
perform the operations like adding & deleting items to the list and printing the
total value of an order.*/
#include<iostream>
using namespace std;

class Shopping{
    int code[50];
    double price[50];
    int num;
    public:
    void number(){num=0;}
    void input(){
        cout<<"\n\nenter the code : ";cin>>code[num];
        cout<<"\n\nenter the price : ";cin>>price[num];
        num++;
    }
    void output(){
        for(int i=0;i<num;i++){
            cout<<"\nthe code : "<<code[i]<<"\n";
            cout<<"the price : "<<price[i]<<"\n";
        }
    }
    void deletes(){
        int a;cout<<"\n\nenter the code to delete : ";cin>>a;
        for(int i=a;i<num;i++){
            price[i]=price[i+1];code[i]=code[i+1];
        }
        num--;
    }
    void total(){
        double sum=0;
        for(int i=0;i<num;i++){
            sum=sum+price[i];
        }
        cout<<"\n\nthe total price : "<<sum<<"\n\n";
    }
};

main(){
    
    Shopping order;
    order.number();
    
    string user;
    while(user!="exit"){
        cout<<"\na) adding new item";
        cout<<"\nb) delete an item";
        cout<<"\nc) total amount";
        cout<<"\nd) bill";
        cout<<"\nenter exit to stop the program \n\n";

        cout<<"\n\nenter your choice : ";cin>>user;
        if(user=="a"){
            int items;cout<<"enter the number of items to buy :";cin>>items;
            for(int i=0;i<items;i++){order.input();}
        }
        else if(user=="b"){order.deletes();}
        else if(user=="c"){order.total();}
        else if(user=="d"){order.output();}
        else if(user!="exit"){cout<<"you have entered a wrong opt \n\n";}
    }

}