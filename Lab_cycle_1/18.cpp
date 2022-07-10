/* Operations on a Sparce matrix*/

#include<iostream>
using namespace std;

class Node{
	private:
	Node *address;
	int value;
	
	public:
	Node* give_next(void){
		return address;
	}
	
	int give_value(void){
		return value;
	}
	
};
