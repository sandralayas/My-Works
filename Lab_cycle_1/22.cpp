/* Adding two polynomials using linked list*/

#include<iostream>
using namespace std;

class Node{
	private:
	Node *the_address;
	int the_value;
	
	public:
	Node* give_next(void){
		return the_address;
	}
	int give_value(void){
		return the_value;
	}
	void set_value(int value){
		the_value=value;
	}
	void set_address(Node *address){
		the_address=address;
	}
	void next_node(void){
		the_address=new Node;
	}
};

Node Linked_list(int length){
	int count=0;
	int value;
	
	Node Start;
	Node *ptr;

	Start.next_node();
	ptr=Start.give_next();
	cout<<"                       ";
	while(count!=length){
		cout<<"  x^"<<count;count++;
	}
	count=0;
	cout<<"\n Enter the coffecients : ";
	while(count!=length){
		cin>>value;
		ptr->set_value(value);
		ptr->next_node();
		ptr=ptr->give_next();
		count++;
	}
	return Start;
}

void Display(Node Start,int length){
	Node *ptr;
	int count=0;
	cout<<"\n   \t";
	while(count!=length){
		cout<<"\tx^"<<count;count++;
	}
	cout<<"\n The sum : \t";
	ptr=Start.give_next();
	
	while(length>0){
		cout<<ptr->give_value()<<'\t';
		ptr=ptr->give_next();
		length--;
	}
}

void Insert(Node START,int ITEM){
    
    Node *PTR=START.give_next();
    Node *ptr;
    while(PTR!=NULL){
        ptr=PTR;
        PTR=PTR->give_next();
    }
    
    ptr->set_value(ITEM);
    ptr->next_node();

}

void Add(Node A,Node B,int a,int b){
	bool bb;
	if(b>a)bb=true;
	else bb=false;
	
	Node *PTR=A.give_next();
    	Node *ptr=B.give_next();
    	Node Start=A;int start=a;
    	if(bb){
    		PTR=B.give_next();
    		ptr=A.give_next();
    		Start=B;start=b;
    	}
    	
    	//Node SUM,*sum;
    	//SUM.next_node();
    	
    	int sum;
    	while(ptr!=NULL){
    		sum=PTR->give_value()+ptr->give_value();
    		PTR->set_value(sum);
    		
    		PTR=PTR->give_next();
    		ptr=ptr->give_next();
    	}
    	Display(Start,start);
}

int main(void){
	char choice;
	
	int length1,length2,ITEM;
	Node START1,START2;
	Node *LOC;
	do{
		cout<<"\n\n Enter 0 to exit the program\
\n Enter 1 to input the polynomials\
\n Enter 2 to add the polynomials\
\n\n Enter the choice : ";cin>>choice;

	if(choice=='0')break;
	else if(choice=='1'){
		cout<<"\n Enter the degree of the 1st polynomial: ";cin>>length1;
		START1=Linked_list(length1);
		cout<<"\n Enter the degree of the 2nd polynomial: ";cin>>length2;
		START2=Linked_list(length2);
	}
	else if(choice=='2'){
		Add(START1,START2,length1,length2);
	}
	}while(choice!='0');

return 0;
}
