/*Write a C++ program using classes to perform bank transaction for n customers
(cust_name, acc_no, acc_type, balance). The program should be menu driven
and it should have the following menus like adding new account, withdraw
(keep a min balance of 500), deposit, balance enquiry and account statement
(cust_name, acc_no, acc_type, balance).*/

#include<iostream>
using namespace std;

class BankAccount{
    string name[50];
    int acc[50];
    string type[50];
    float balance[50];
    int num;
    public:

void accounts(void){num=0;}

void deposit(void){
    float x;cout<<"\n\n Enter the depositing amount : ";cin>>x;

    int reqcode;
    int a;cout<<"\n Enter the account number : ";cin>>a;
    for(int i=0;i<num;i++){
        if(acc[i]==a){reqcode=i;break;}
    }

    balance[reqcode]=balance[reqcode]+x;
}

void withdraw(void){
    float x;cout<<"\n\n Enter the withdrawing amount : ";cin>>x;
    
    int reqcode;
    int a;cout<<"\n Enter the account number : ";cin>>a;
    for(int i=0;i<num;i++){
        if(acc[i]==a){reqcode=i;break;}
    }

    if(balance[reqcode]>=x){
        balance[reqcode]=balance[reqcode]-a;
    }
    else{cout<<"\n Your balance :"<<balance[reqcode]<<"\n You can't withdraw that amount\n\n";}
}

void display(int number){
    cout<<"\n\n Name  |  Account no.  |  Account type  |  Balance amount\n";
    cout<<name[number]<<"     "<<acc[number]<<"     "<<type[number]<<\
    "     "<<balance[number]<<"     ";
}

void input(){

    string a;int b;string c;float d;

    cout<<" Name    Account type\n";
    cin>>a>>c;name[num]=a;type[num]=c;
    cout<<"\n\n";
    cout<<" Enter your account number : ";
    cin>>b;acc[num]=b;
    cout<<"\n\n";
    cout<<" Enter your balance amount : ";
    cin>>d;balance[num]=d+500.00;;
    cout<<"\n\n";
    num++;
}

void display_balance(void){
    int reqcode;
    int a;cout<<"\n\n Enter the account number : ";cin>>a;
    for(int i=0;i<num;i++){
        if(acc[i]==a){reqcode=i;break;}
    }
    cout<<"\n  Balance : "<<balance[reqcode];
}

void account_statement(void){
	int reqcode;
    int a;cout<<"\n\n Enter the account number : ";cin>>a;
    for(int i=0;i<num;i++){
        if(acc[i]==a){display(i);break;}
    }
}

};

int main(void){

    BankAccount account;
    account.accounts();
    string user;
    while(user!="exit"){
        cout<<"\na) Adding new account";
        cout<<"\nb) Withdraw";
        cout<<"\nc) Deposit";
        cout<<"\nd) Balance enquiry";
        cout<<"\ne) Account statement";
        cout<<"\n Enter 'exit' to stop the program \n\n";

        cout<<"\n\nenter your choice : ";cin>>user;
        if(user=="a"){account.input();}
        else if(user=="b"){account.withdraw();}
        else if(user=="c"){account.deposit();}
        else if(user=="d"){account.display_balance();}
        else if(user=="e"){account.account_statement();}
        else if(user!="exit"){cout<<"you have entered a wrong opt \n\n";}
    }
return 0;
}
