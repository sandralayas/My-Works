/* Operations on a Sparce matrix*/

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

bool Insert(Node START,int ITEM){
	if(START.give_next()==NULL)return false;
	Node *PTR=&START;
	Node *ptr;
	while(PTR!=NULL){
		ptr=PTR;
		PTR=PTR->give_next();
	}
	
	ptr->set_value(ITEM);
	ptr->next_node();
	return true;
}

int main(void){
	char choice;
	
	int length,ITEM;
	Node START;
	Node *LOC;
	do{
		cout<<"\n\n Enter 0 to exit the program\
\n Enter 1 to input the linked list\
\n Enter 2 to insert into the linked list\
\n Enter 3 display\
\n\n Enter the choice : ";cin>>choice;

	if(choice=='0')break;
	else if(choice=='1'){
		cout<<"\n Enter the length of the linked list : ";cin>>length;
		START=Linked_list(length);
	}
	else if(choice=='2'){
		cout<<"\n Enter the item to insert : ";cin>>ITEM;
		if(Insert(START,ITEM)){
			cout<<"\n The item inserted\n";
			length++;
		}
		else cout<<"\n Underflow\n";
	}
	else if(choice=='3'){
		Display(START,length);
	}
	}while(choice!='0');

return 0;
}
