/*Write a C++ program using class to process shopping list for a Departmental
Store. The list include details such as the Code-no and price of each item and
perform the operations like adding & deleting items to the list and printing the
total value of an order.*/
#include<iostream>
using namespace std;

class Shopping{
    int code[50];
    double price[50];
    int qty[50];
    string name[50];
    int num,cost;
    public:
    void number(void){num=0;}
    void item(void){cost=0;}
    void total(void){cout<<"\n\n The total price : "<<cost<<"\n\n";}
    void input(){
        cout<<"\n\n Enter the 3-digit code : ";cin>>code[num];
        cout<<" Enter the name : ";cin>>name[num];
        cout<<" Enter the price (000.00): ";cin>>price[num];
        cout<<" Enter the quantity (000): ";cin>>qty[num];
        num++;
    }
    void output(void){
	cout<<"\n  Code    :   Price        :   Quantity  :   Name\n\n";
        for(int i=0;i<num;i++){
            cout<<code[i]<<"       :   "<<price[i]<<"       :   "<<qty[i]<<"       :   "<<name[i]<<"\n";
        }
    }
    void deletes(void){
	int reqcode=0;
    int a;cout<<"\n\n Enter the code to delete : ";cin>>a;
	
        for(int i=0;i<num;i++){
            if(code[i]==a){
                reqcode=i;
                for(int i=reqcode;i<num;i++){
	                price[i]=price[i+1];code[i]=code[i+1];qty[i]=qty[i+1];name[i]=name[i+1];
                    num--;
                    cout<<" You have removed the item from stock\n\n";
                }
                break;
            }
	    }
        if(reqcode==0)cout<<" This item does not exit\n";
    }
    void summing(int customer,int quantity){
        for(int i=0;i<num;i++){
            if(code[i]==customer){
            	if(qty[i]<=quantity){
            		cout<<"\n\n The quantity exceeds the stock for item : "<<customer<<"\n\n";
            	}
            	else{
            		cost+=(price[i]*quantity);
            		qty[i]-=quantity;
            	}
            }
        }
    }
    void bill(int customer,int quantity){
        for(int i=0;i<num;i++){
            if(code[i]==customer){
            	cout<<code[i]<<"       :   "<<price[i]<<"       :   "<<quantity<<"       :   "<<name[i]<<"\n";
            }
        }
    }
};

// Main Program

int main(void){
int exit;
do{    
    Shopping order;
    order.number();
    order.item();
    
    string user;
    while(user!="exit"){
        cout<<"\n a) Adding an item to shop";
        cout<<"\n b) Delete an item from shop";
        cout<<"\n c) Stock available";
		cout<<"\n d) Buy an item from the stock";
        cout<<"\n Enter 'exit' to stop the program \n\n";

        cout<<"\n\n Enter your choice : ";cin>>user;
        if(user=="a"){
            int items;cout<<"\n Enter the number of items to stock : ";
			cin>>items;
            for(int i=0;i<items;i++){order.input();}
        }
        else if(user=="b"){order.deletes();}
        else if(user=="c"){order.output();}
        else if(user=="d"){
            int items;cout<<"\n Enter the number of items to buy : ";
			cin>>items;
            int list1[items];int list2[items];
            
            for(int i=0;i<items;i++){
                cout<<"\n Enter the 3-digit code of item "<<i+1<<" : ";
				cin>>list1[i];
				cout<<"\n Enter the quantity to buy : ";
            	cin>>list2[i];
                order.summing(list1[i],list2[i]);
            }
            cout<<"\n  Code    :   Price        :   Quantity  :   Name\n\n";
            for(int i=0;i<items;i++){
            	order.bill(list1[i],list2[i]);
            }
            order.total();
        }
        else if(user!="exit"){cout<<" You have entered a wrong opt \n\n";}
    }
cout<<"\n Enter '0' to exit the program : ";cin>>exit;
}while(exit!=0);
return 0;
}
