/* Execution of Merge sort in an array */

#include<iostream>
using namespace std;

void Merge(int A[],int r,int la,\
int B[],int s,int lb,\
int C[],int lc){
	int NA=la,NB=lb,PTR=0;
	while(NA<=la+r-1 and NB<=lb+s-1){
		if(A[NA]<B[NB]){
			C[PTR]=A[NA];
			NA++;PTR++;
		}
		else{
			C[PTR]=B[NB];
			NB++;PTR++;
		}
	}
	if(NA>lb+s-1){
		for(int i=0;i<lb+s-1-NB;i++){
			C[PTR+i]=B[NB+i];
		}
	}
	else{
		for(int i=0;i<la+r-1-NA;i++){
			C[PTR+i]=A[NA+i];
		}
	}
}

void Merge_pass(int A[],int n,int l,int B[]){
	int q=n/(2*l),s=2*l*q,r=n-s;
	for(int j=1;j<q;j++){
		int lb=(2*j-2)*(l);
		Merge(A,l,lb,A,l,lb+l,B,lb);
	}
	if(r<=l){
		for(int j=0;j<r;j++){
			B[s+j]=A[s+j];
			Merge(A,l,s+1,A,r-l,l+s+1,B,s+1);
		}
	}
	else Merge(A,l,s+1,A,r-l,l+s+1,B,s+1);
}

void Merge_sort(int DATA[],int N,int B[]){
	int l=1;
	while(l<N){
		Merge_pass(DATA,N,l,B);
		Merge_pass(B,N,2*l,DATA);
		l=4*l;
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
	cout<<"\n Enter the number of elements in the array : ";cin>>N1;
	int DATA1[N1],B[N1];
	Input(DATA1,N1);

	char choice;
	do{
		cout<<"\n 0. Exit the program\
\n 1. Display\
\n 2. Insertion\
\n 3. Deletion\
\n 4. Merge sort\
\n\n Enter your choice : ";cin>>choice;

	if(choice=='0')break;
	else if(choice=='1'){
		Print(DATA1,N1);
	}
	else if(choice=='2'){
		int K,ITEM;
		cout<<"\n Enter the item for insertion : ";cin>>ITEM;
		cout<<"\n Enter the position for insertion : ";cin>>K;
		Insert(DATA1,N1,K,ITEM);
		N1++;
	}
	else if(choice=='3'){
		int K,ITEM;
		cout<<"\n\n Enter the position for deletion : ";cin>>K;
		ITEM=Delete(DATA1,N1,K,ITEM);
		N1--;
		cout<<"\n\n The item deleted : "<<ITEM<<endl;
	}
	else if(choice=='4'){
		Merge_sort(DATA1,N1,B);
		cout<<"\n The data is sorted\n";
	}
	else cout<<"\n Wrong Choice!!\n";
	}while(choice!='0');

cout<<"\n";
return 0;
}
