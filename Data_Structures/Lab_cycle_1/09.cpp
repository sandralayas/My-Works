/* Execution of Insertion sort in an array */

#include<iostream>
using namespace std;

void Insertion_sort(int DATA[], int N){
	int temp,k,ptr;
	for(k=1;k<N;k++)
	{
		temp=DATA[k];
		ptr=k-1;
		while(temp<DATA[ptr])
		{
			DATA[ptr+1]=DATA[ptr];
			ptr=ptr-1;
		}
		DATA[ptr+1]=temp;
	}
}

void Insert(int DATA[], int N, int K, int ITEM){
	int temp=N;
	while(temp>=K){
		DATA[temp+1]=DATA[temp];
		temp--;
	}
	DATA[K]=ITEM;
	N++;
}

int Delete(int DATA[], int N, int K, int ITEM){
	ITEM=DATA[K];
	int temp=N;
	while(temp-1>=K){
		DATA[temp]=DATA[temp+1];
		temp--;
	}
	return ITEM;
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

int main(void){

	int N;
	cout<<"\n Enter the number of elements in the array : ";cin>>N;
	int DATA[N];
	Input(DATA,N);

	char choice;
	do{
		cout<<"\n 0. Exit the program\
\n 1. Display\
\n 2. Insertion\
\n 3. Deletion\
\n 4. Insertion sort\
\n\n Enter your choice : ";cin>>choice;

	if(choice=='0')break;
	else if(choice=='1')Print(DATA,N);
	else if(choice=='2'){
		int K,ITEM;
		cout<<"\n\n Enter the item for insertion : ";cin>>ITEM;
		cout<<"\n Enter the position for insertion : ";cin>>K;
		Insert(DATA,N,K,ITEM);
		N++;
	}
	else if(choice=='3'){
		int K,ITEM;
		cout<<"\n\n Enter the position for deletion : ";cin>>K;
		ITEM=Delete(DATA,N,K,ITEM);
		N--;
		cout<<"\n\n The item deleted : "<<ITEM<<endl;
	}
	else if(choice=='4'){
		Insertion_sort(DATA,N);
		cout<<"\n The data is sorted\n";
	}
	else cout<<"\n Wrong Choice!!\n";
	}while(choice!='0');

cout<<"\n";
return 0;
}

