/* Execution of Interpolation search in an array */

#include<iostream>
using namespace std;

void Interpolation_search(int DATA[], int N, int ITEM, int LOC){
	int START=0,STOP=N,POS;

	LOC=-1;
	while(START<=STOP and ITEM>=DATA[START] and ITEM<=DATA[STOP]){
		
		POS=START+((ITEM-DATA[START])*(STOP-START)/(DATA[STOP]-DATA[START]));
		
		if(DATA[POS]==ITEM){
			LOC=POS;
			cout<<"\n The item found at position : "<<LOC<<endl;
			break;
		}
		else if(ITEM>DATA[POS])START=POS+1;
		else{
			STOP=POS-1;
		}
	}
	if(LOC==-1)cout<<"\n The item not found !!\n";
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
\n 4. Interpolation search\
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
		int L,U,LOC,ITEM;
		cout<<"\n\n Enter the item for Interpolation search : ";cin>>ITEM;
		Interpolation_search(DATA,N,ITEM,LOC);
	}
	else cout<<"\n Wrong Choice!!\n";
	}while(choice!='0');

cout<<"\n";
return 0;
}
