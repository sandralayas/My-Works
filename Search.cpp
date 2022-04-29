#include<iostream>
using namespace std;

class Search{

	public:
	
	void Iterative(int data[],int key);
	int Recursive(int position,int data[],int key);

	void Dove_Tailing(void);
	void Spiral(void);
};

int Search::Iterative(int data[],int key){
		bool found=false;
		int index=0;
		int position=-1;
		
		while(index<10){
			if(data[index]==key){
				found=true;
				position=index;
				break;
			}
			index++;
		}
		if(found) return position+1;
		else return -1;
}

int Search::Recursive(int position,int data[],int key){

		int repeat(int position){
			if(data[position]==key){
				return position;
			}
			else return repeat(position-1,data[],key);
		}
}

void Search::

int main(void){

	int data[10]={3,5,1,2,8,6,7,4,9,10};
	int key=3;

	Search test;

	int ans=test.Iterative(data[10],key);
	if(ans==-1) cout<<"\n The key is not found\n";
	else cout<<"\n The key is in position "<<ans<<"\n";

	int position=test.Recursive(9);
	cout<<"\n The position : "<<position+1<<"\n";

return 0;
}
