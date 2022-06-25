/* Execution of Insertion sort in an array */

// INCOMPLETE

#include<iostream>
using namespace std;

void Merge_array(int A[],int r,int B[],int s,int C[]){
	int NA=1,NB=1,PTR=1;
	
	while(NA<=r and NB<=s){
		if(A[NA]<B[NB]){
			C[PTR]=A[NA];
			NA++;PTR++;
		}
		else{
			C[PTR]=B[NB];
			NB++;PTR++;
		}
	}
	if(NA>r){
		for(int i=0;i<s-NB;i++){
			C[PTR+i]=B[NB+i];
		}
	}
	else{
		for(int i=0;i<r-NA;i++){
			C[PTR+i]=B[NA+i];
		}
	}
}

void Bubble_sort(int DATA[], int N){
	int k,j,temp;
	
	for(k=0;k<N;k++){
		for(j=0;j<N-k;j++){
			if(DATA[j]>DATA[j+1]){
				temp=DATA[j];
				DATA[j]=DATA[j+1];
				DATA[j+1]=temp;
			}
		}
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
	
	int N1;
	cout<<"\n Enter the number of elements in the first array : ";cin>>N1;
	int DATA1[N1];
	Input(DATA1,N1);
	Bubble_sort(DATA1,N1);
	
	int N2;
	cout<<"\n Enter the number of elements in the second array : ";cin>>N2;
	int DATA2[N2];
	Input(DATA2,N2);
	Bubble_sort(DATA2,N2);

	char choice;
	do{
		cout<<"\n 0. Exit the program\
\n 1. Display\
\n 2. Insertion\
\n 3. Deletion\
\n 4. Merge\
\n\n Enter your choice : ";cin>>choice;

	if(choice=='0')break;
	else if(choice=='1'){
		do{
		cout<<"\n\n Enter 1 to insert into the first array\
\n Enter 1 to insert into the second array\
\n\n Enter your choice : ";cin>>choice;
		if(choice=='1'){
			int N=N1;
			int DATA[N1];
			DATA=DATA1;
		}
		else if(choice=='2'){
			int N=N2;
			int DATA[N2];
			DATA=DATA2;
		}
		}while(choice!='1' or choice!='2');
		Print(DATA,N);
	}
	else if(choice=='2'){
		int K,ITEM,choice,N;
		do{
		cout<<"\n\n Enter 1 to insert into the first array\
\n Enter 1 to insert into the second array\
\n\n Enter your choice : ";cin>>choice;
		if(choice=='1'){
			int N=N1;
			int DATA[N1];
			DATA=DATA1;
		}
		else if(choice=='2'){
			int N=N2;
			int DATA[N2];
			DATA=DATA2;
		}
		}while(choice!='1' or choice!='2');
		cout<<"\n Enter the item for insertion : ";cin>>ITEM;
		cout<<"\n Enter the position for insertion : ";cin>>K;
		Insert(DATA,N,K,ITEM);
		N++;
	}
	else if(choice=='3'){
		int K,ITEM,choice;
		do{
		cout<<"\n\n Enter 1 to insert into the first array\
\n Enter 1 to insert into the second array\
\n\n Enter your choice : ";cin>>choice;
		if(choice=='1'){
			int N=N1;
			int DATA[N1];
			DATA=DATA1;
		}
		else if(choice=='2'){
			int N=N2;
			int DATA[N2];
			DATA=DATA2;
		}
		}while(choice!='1' or choice!='2');
		cout<<"\n\n Enter the position for deletion : ";cin>>K;
		ITEM=Delete(DATA,N,K,ITEM);
		N--;
		cout<<"\n\n The item deleted : "<<ITEM<<endl;
	}
	else if(choice=='4'){
		int DATA[N1+N2];
		Merge_array(DATA1,N1,DATA2,N2,DATA);
		cout<<"\n The merged data is\n";
		Print(DATA,N1+N2);
	}
	else cout<<"\n Wrong Choice!!\n";
	}while(choice!='0');

cout<<"\n";
return 0;
}

