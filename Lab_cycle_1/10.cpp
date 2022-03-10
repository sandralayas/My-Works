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
    void number(void){num=0;}
    void input(){
        cout<<"\n\n Enter the code : ";cin>>code[num];
        cout<<"\n\n Enter the price : ";cin>>price[num];
        num++;
    }
    void output(void){
	cout<<"\n  Code    :   Price "<<"\n";
        for(int i=0;i<num;i++){
            cout<<code[i]<<"         :   "<<price[i]<<"\n";
        }
    }
    void deletes(void){
	int reqcode;
        int a;cout<<"\n\n Enter the code to delete : ";cin>>a;
	cout<<" You have removed an item\n\n";
        for(int i=0;i<num;i++){
            if(code[i]==a){reqcode=i;}
        }
	for(int i=reqcode;i<num;i++){
	    price[i]=price[i+1];code[i]=code[i+1];
	}
	num--;
    }
    void total(void){
        double sum=0;
        for(int i=0;i<num;i++){
            sum=sum+price[i];
        }
        cout<<"\n\n The total price : "<<sum<<"\n\n";
    }
};

int main(void){
    
    Shopping order;
    order.number();
    
    string user;
    while(user!="exit"){
        cout<<"\n a) Adding new item";
        cout<<"\n b) Delete an item";
        cout<<"\n c) Total amount";
        cout<<"\n d) Bill";
        cout<<"\n Enter exit to stop the program \n\n";

        cout<<"\n\n Enter your choice : ";cin>>user;
        if(user=="a"){
            int items;cout<<" Enter the number of items to buy :";cin>>items;
            for(int i=0;i<items;i++){order.input();}
        }
        else if(user=="b"){order.deletes();}
        else if(user=="c"){order.total();}
        else if(user=="d"){order.output();}
        else if(user!="exit"){cout<<" You have entered a wrong opt \n\n";}
    }
return 0;
}
