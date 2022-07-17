#include<iostream>
using namespace std;

class Search{

	public:
	int Iterative(int*,int);
	int Recursive(int,int*,int);

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

int Repeat(int position, int data[], int key){
	if(data[position]==key){
		return position;
	}
	else return Repeat(position-1,data,key);
}

int Search::Recursive(int position,int data[],int key){
	return Repeat(position,data,key);
}

void Input(int DATA[], int N){
	int count=1;
	while(N>=count){
		int temp;
		cout<<"\n Enter element no."<<count<<" : ";cin>>temp;
		DATA[count-1]=temp;
		count++;
	}
}

void Print(int DATA[], int N){
	cout<<"\n The array is : ";
	int count=1;
	while(N>=count){
		cout<<DATA[count-1];
		if(count!=N)cout<<", ";
	count++;
	}
	cout<<endl;
}

//void Search::

int main(void){

	int N,key;
	cout<<"\n Enter the number of elements in the array : ";cin>>N;
	int data[N];
	Input(data,N);
	Search test;
	char choice;
	do{
		cout<<"\n 0. Exit the program\
\n 1. Display\
\n 2. Iterative Search\
\n 3. Recursive search\
\n\n Enter your choice : ";cin>>choice;

	if(choice=='0')break;
	else if(choice=='1')Print(data,N);
	else if(choice=='2'){
		cout<<"\n Enter the key to search : ";cin>>key;
		int ans=test.Iterative(data,key);
		if(ans==-1) cout<<"\n The key is not found\n";
		else cout<<"\n The key is in position "<<ans<<"\n";
	}
	else if(choice=='3'){
		cout<<"\n Enter the key to search : ";cin>>key;
		int position=test.Recursive(9,data,key);
		cout<<"\n The key is in position "<<position+1<<"\n";
	}
	else cout<<"\n Wrong Choice!!\n";
	}while(choice!='0');

cout<<"\n";
return 0;
}	

