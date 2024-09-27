# include <iostream>
using namespace std;

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

    for(int j= 1;j<=Q;j++)
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

int main(){
    int A[14]={66,33,40,22,55,88,60,11,80,20,50,44,77,30},B[14];
    int n=14,l=1;

    MERGE_SORT(A,B,n);
    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
return 0;
}
