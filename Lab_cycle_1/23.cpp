/* Searching in a Circular Linked List*/

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
	void set_next(Node *address){
		the_address=address;
	}
	void next_node(void){
		the_address=new Node;
	}
};

Node Circular_Linked_list(int length){
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
		//ptr->set_next(&Start);
		count++;
	}
	
	Node *PTR=Start.give_next();
	while(PTR->give_next()!=NULL){
		PTR=PTR->give_next();
	}
	PTR->set_next(&Start);
	
	return Start;
}

Node* Search(Node START,int ITEM,Node *LOC){
	Node *PTR=START.give_next();
	while(PTR!=&START){
		if(ITEM==PTR->give_value()){
			LOC=PTR;
			return LOC;
		}
		else PTR=PTR->give_next();
	}
	return NULL;
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

bool Insert(Node START,int ITEM){
    if(START.give_next()==&START)return false;
    Node *PTR=START.give_next();
    Node *ptr;
    while(PTR!=&START){
	PTR=PTR->give_next();
    }
    PTR->next_node();
    ptr=PTR->give_next();
    ptr->set_value(ITEM);
    ptr->set_next(&START);
    //PTR->set_next(ptr);
    return true;
}

Node* Delete(Node START,int ITEM,Node *LOC){
	
	if(START.give_next()==&START){
		cout<<"\n Underflow\n";
		return NULL;
	}
	else{
		
		if(Search(START,ITEM,LOC)!=NULL){
			LOC=Search(START,ITEM,LOC);
		
		
			Node *PTR=START.give_next();
		
			if(PTR==LOC){
				START.set_next(LOC->give_next());
				//delete START.give_next();
				return LOC;
			}
		
			while(PTR!=&START){
				if(LOC==PTR->give_next()){
					break;
				}
				else PTR=PTR->give_next();
			}
			PTR->set_next(LOC->give_next());
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
\n Enter 1 to input the circular linked list\
\n Enter 2 to insert into the circular linked list\
\n Enter 3 to delete from the circular linked list\
\n Enter 4 display\
\n\n Enter the choice : ";cin>>choice;

    if(choice=='0')break;
    else if(choice=='1'){
        cout<<"\n Enter the length of the linked list : ";cin>>length;
        START=Circular_Linked_list(length);
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
        cout<<"\n Enter the item to delete : ";cin>>ITEM;
        LOC=Delete(START,ITEM,LOC);
        if(LOC!=NULL){
            cout<<"\n The item deleted at : "<<LOC<<endl;
            length--;
        }
    }
    else if(choice=='4'){
        Display(START,length);
    }
    }while(choice!='0');

return 0;
}

