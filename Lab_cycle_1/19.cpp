/* Insertion from a Linked List*/

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

bool Insert(Node START,int ITEM){
    if(START.give_next()==NULL)return false;
    Node *PTR=START.give_next();
    Node *ptr;
    while(PTR!=NULL){
        ptr=PTR;
        PTR=PTR->give_next();
    }
    
    ptr->set_value(ITEM);
    ptr->next_node();
    return true;
}
/*
bool Insert(Node START,int ITEM){

    if(START.give_next()==NULL)return false;
    Node *PTR=START.give_next();
    Node *ptr,*temp;
    temp->next_node();
    
    bool done=false;
    while(PTR!=NULL){
        ptr=PTR;//cout<<ptr->give_value()<<endl;
        PTR=(PTR->give_next());//cout<<PTR->give_value()<<endl;
        if(not done){
		    if(PTR->give_value()>ITEM or PTR==NULL){
		        ptr->set_address(temp);
		        
		        temp->set_value(ITEM);
		        temp->set_address(PTR);
		        done=true;
		    }
		}
    }
    return true;
}
*/

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

