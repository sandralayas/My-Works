/* Deletion from a Linked List*/

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
	void next_node(void){
		the_address=new Node;
	}
	void set_address(Node *ptr){
		the_address=ptr;
	}
};

Node Linked_list(int length){
	int count=1;
	int value;
	
	Node Start;
	Node *ptr;
	
	cout<<"\n Enter the value no."<<count<<" : ";cin>>value;
	Start.set_value(value);
	Start.next_node();
	ptr=Start.give_next();
	
	while(count!=length){
		count++;
		cout<<"\n Enter the value no."<<count<<" : ";cin>>value;
		ptr->set_value(value);
		ptr->next_node();
		ptr=ptr->give_next();
	}
	return Start;
}

void Display(Node Start,int length){
	Node *ptr;
	
	cout<<"\n The linked list : ";
	cout<<Start.give_value()<<' ';
	ptr=Start.give_next();
	
	while(length>1){
		cout<<ptr->give_value()<<' ';
		ptr=ptr->give_next();
		length--;
	}
}

bool Search(Node START,int ITEM,Node *LOC){
	Node *PTR=&START;
	while(PTR!=NULL){
		if(ITEM==PTR->give_value()){
			LOC=PTR;
			return true;
		}
		else PTR=PTR->give_next();
	}
	return false;
}


bool Delete(Node START,int ITEM,Node *LOC){
	
	if(Search(START,ITEM,LOC)){
		if(START.give_next()==NULL)return false;
		Node *PTR=&START;
		Node *ptr;
		while(PTR->give_value()!=ITEM){
			ptr=PTR;
			PTR=PTR->give_next();
		}
	
		ptr->set_address(PTR->give_next());
		LOC=PTR;
		delete PTR;
		return true;
	}
	else{
		cout<<"\n Item not found";
		return true;
	}
}

int main(void){
	char choice;
	
	int length,ITEM;
	Node START;
	Node *LOC;
	do{
		cout<<"\n\n Enter 0 to exit the program\
\n Enter 1 to input the linked list\
\n Enter 2 to delete from the linked list\
\n Enter 3 display\
\n\n Enter the choice : ";cin>>choice;

	if(choice=='0')break;
	else if(choice=='1'){
		cout<<"\n Enter the length of the linked list : ";cin>>length;
		START=Linked_list(length);
	}
	else if(choice=='2'){
		cout<<"\n Enter the item to delete : ";cin>>ITEM;
		if(Delete(START,ITEM,LOC)){
			cout<<"\n The item deleted at : "<<LOC<<endl;
			length--;
		}
		else cout<<"\n Underflow\n";
	}
	else if(choice=='3'){
		Display(START,length);
	}
	}while(choice!='0');

return 0;
}
