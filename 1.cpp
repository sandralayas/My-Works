/* Inserting and deleting and element from an array */

#include<iostream>
using namespace std;

void Insert(int DATA[], int N, int K, int ITEM){
	int temp=N;
	while(temp>=K){
		DATA[temp+1]=DATA[temp];
		temp--;
	}
	DATA[K]=ITEM;
	N++;
}

void Delete(int D){}

int main(void){
	
	int N;
	cout<<"\n Enter the number of elements in the array : ";cin>>N;
	int DATA[N];
	int count=1;
	while(N>=count){
		int temp;
		cout<<"\n Enter element no."<<count<<" : ";cin>>temp;
		DATA[count-1]=temp;
		count++;
	}

	cout<<"\n The array is : ";
	{
		count=1;
		while(N>=count){
			cout<<DATA[count-1];
			if(count!=N)cout<<", ";
		count++;
		}
	}

	int K,ITEM;
	cout<<"\n\n Enter the position for insertion : ";cin>>K;
	cout<<"\n Enter the item for insertion : ";cin>>ITEM;
	Insert(DATA,N,K,ITEM);

	cout<<"\n The array is : ";
	{
		count=1;
		while(N>=count){
			cout<<DATA[count-1];
			if(count!=N)cout<<", ";
		count++;
		}
	}

cout<<"\n";
return 0;
}
