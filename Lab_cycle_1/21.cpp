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
	int count=0;
	int value;
	
	Node Start;
	Node *ptr;

	Start.next_node();
	ptr=Start.give_next();
	
	cout<<"\n Enter the values : ";
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
	
	cout<<"\n The linked list : ";
	ptr=Start.give_next();
	
	while(length>0){
		cout<<ptr->give_value()<<' ';
		ptr=ptr->give_next();
		length--;
	}
}

Node* Search(Node START,int ITEM,Node *LOC){
	Node *PTR=START.give_next();
	while(PTR!=NULL){
		if(ITEM==PTR->give_value()){
			LOC=PTR;
			return LOC;
		}
		else PTR=PTR->give_next();
	}
	return NULL;
}


Node* Delete(Node START,int ITEM,Node *LOC){
	
	if(START.give_next()==NULL){
		cout<<"\n Underflow\n";
		return NULL;
	}
	else{
		
		if(Search(START,ITEM,LOC)!=NULL){
			LOC=Search(START,ITEM,LOC);
		
		
			Node *PTR=START.give_next();
		
			if(PTR==LOC){
				START.set_address(LOC->give_next());
				//delete START.give_next();
				return LOC;
			}
		
			while(PTR!=NULL){
				if(LOC==PTR->give_next()){
					break;
				}
				else PTR=PTR->give_next();
			}
			PTR->set_address(LOC->give_next());
			LOC=PTR->give_next();
			delete PTR->give_next();
			return LOC;
		}
		else{
			cout<<"\n Item not found";
			return NULL;
		}
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
		LOC=Delete(START,ITEM,LOC);
		if(LOC!=NULL){
			cout<<"\n The item deleted at : "<<LOC<<endl;
			length--;
		}
	}
	else if(choice=='3'){
		Display(START,length);
	}
	}while(choice!='0');

return 0;
}

