#include<iostream>
using namespace std;

void partition(int A[],int lower,int upper){
    int pivot=lower;
    int i=lower;
    int j=upper;

    while(i<j){
        do{
            i++;
        }while(A[i]<=A[pivot]);
        do{
            j--;
        }while(A[j]>=A[pivot]);
        if(i<j){
            //swap
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    //swap
    int temp=A[j];
    A[j]=A[pivot];
    A[pivot]=temp;
}

int main(void){
    int n;
    cout<<"\n Enter the number of elements needed in the array : ";cin>>n;
    int A[n],lower,upper;
    lower=0;upper=n;
    cout<<"Enter the initial array of numbers : ";
    for(int i=0;i<upper;i++){
        cin>>A[i];
    }
    cout<<endl;
    
    //to sort
    partition(A,lower,upper);

    cout<<"The final array of numbers : ";
    for(int i=0;i<upper;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
