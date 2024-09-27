# include <iostream>
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

void MERGING(int *A,int R,int LBA,int *B,int S,int LBB,int *C,int LBC){
    int NA=LBA,NB=LBB,PTR=LBC;
    int UBA=LBA+R-1,UBB=LBB+S-1;

    while(NA<=UBA && NB<=UBB){
        if(A[NA]<B[NB]){
            C[PTR]=A[NA];
            NA=NA+1;
            PTR=PTR+1;
        }
        else{
            C[PTR]=B[NB];
            NB=NB+1;
            PTR=PTR+1;
        }
    }

    if(NA>UBA){
        for(int i=0;i<=UBB-NB;i++){
            C[PTR+i]=B[NB+i];
        }
    }
    else{
        for(int i=0;i<=UBA-NA;i++){
            C[PTR+i]=A[NA+i];
        }

    }
}

void MERGE_PASS(int *A,int N,int L,int *B){
    int Q=N/(2*L);
    int S=2*L*Q;
    int R=N-S;
    int LB;

    for(int j= 1;j<=Q;j++){
        LB=(2*j-2)*L;
        MERGING(A,L,LB,A,L,LB+L,B,LB);
    }

    if(R<=L){
        for(int k=0;k<R;k++){
            B[S+k]=A[S+k];
        }
    }
    else{
        MERGING(A,L,S,A,R-L,L+S,B,S);
    }
}

void MERGE_SORT(int *A,int *B,int N){
    int L=1;
    
    while(L<N){
        MERGE_PASS(A,N,L,B);
        MERGE_PASS(B,N,2*L,A);
        L=4*L;
    }

}

int main(void){
	
	int N1;
	cout<<"\n Enter the number of elements in the array : ";cin>>N1;
	int DATA1[N1],DATA2[N1];
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
		MERGE_SORT(DATA1,DATA2,N1);
		cout<<"\n The data is sorted\n";
	}
	else cout<<"\n Wrong Choice!!\n";
	}while(choice!='0');

cout<<"\n";
return 0;
}
