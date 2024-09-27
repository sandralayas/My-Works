// Binary tree

#include<iostream>
using namespace std;


class Node{
	private:
	int the_value;
	Node *the_left_node,*the_right_node;
	
	public:
	
	Node(void){
		the_value=0;
		the_left_node=NULL;
		the_right_node=NULL;
	}
	
	// Basic funtions
	void create_left(void){
		the_left_node=new Node;
	}
	Node* give_left(void){
		return the_left_node;
	}
	
	void create_right(void){
		the_right_node=new Node;
	}
	Node* give_right(void){
		return the_right_node;
	}
	
	void insert_value(int value){
		the_value=value;
	}
	int give_value(void){
		return the_value;
	}
	// Basic funtions
};

void Tree(Node Parent){

	//these are all pointers
	Node *node=&Parent;
	Node *left=node->give_left();
	Node *right=node->give_right();
	int value;
	
	cout<<node->give_value()<<endl; //Parent node printed
	
	Node *list[];
	count=2;
	list=list+left+right;
	
	while(list!=NULL){
		for(int i=0;i<count;i++){
			node=list[i];
			
			if(node==NULL)value=0;
			else{
				value=node->give_value();
				
				left=node->give_left();
				right=node->give_right();
				list=list+left+right;
			}
			cout<<value<<'\t';
		}
		cout<<'\n';
	}
}

/*
int main(void){
	
	int list[]={-1,0,1};
	list=list+2;
	for(int i=0;i<sizeof(list);i++){
		cout<<list[i]<<endl;
	}
	
return 0;
}
*/

