/* Addition of two polynomials*/

#include<iostream>
using namespace std;

void Addition(int A[],int a,int B[],int b){
	int more,less,*big,*small,*sum,count;
	char op;
	
	if(a>b){
		more=a;less=b;
		big=A;small=B;
		int temp[more];sum=temp;
		
		count=0;
		while(count<more-less){
			sum[less+count]=big[less+count];
			count++;
		}
	
		for(int i=0;i<less;i++){
			sum[i]=big[i]+small[i];
		}
	
		cout<<' ';
		for(int i=more-1;i>=0;i--){
			if(sum[i]>0)op='+';
			else op=' ';
		
			if(i==more-1)cout<<sum[i]<<" x^"<<i;
			else cout<<' '<<op<<sum[i]<<" x^"<<i<<' ';
		}
		cout<<endl;
	}
	else{
		more=b;less=a;
		big=B;small=A;
		int temp[more];sum=temp;
		
		count=0;
		while(count<more-less){
			sum[less+count]=big[less+count];
			count++;
		}
	
		for(int i=0;i<less;i++){
			sum[i]=big[i]+small[i];
		}
	
		cout<<' ';
		for(int i=more-1;i>=0;i--){
			if(sum[i]>0)op='+';
			else op=' ';
		
			if(i==more-1)cout<<sum[i]<<'x'<<'^'<<i;
			else cout<<' '<<op<<' '<<sum[i]<<'x'<<'^'<<i<<' ';
		}
		cout<<endl;
	}
}

int main(void){
	char choice;
	
	int length,value,count;
	int *A,*B,a,b;

	do{
		cout<<"\n\n Enter 0 to exit the program\
\n Enter 1 to do the program\
\n\n Enter the choice : ";cin>>choice;

	if(choice=='0')break;
	else if(choice=='1'){
		cout<<"\n Enter the degree of the 1st polynomial : ";cin>>length;
		cout<<" Enter the terms of the 1st polynomial : ";
		int temp[length];
		A=temp;a=length;
		count=0;
		while(count<length){
			cin>>value;
			A[count]=value;
			count++;
		}
		
		cout<<"\n Enter the degree of the 2nd polynomial : ";cin>>length;
		cout<<" Enter the terms of the 2nd polynomial : ";
		temp[length];
		B=temp;b=length;
		count=0;
		while(count<length){
			cin>>value;
			B[count]=value;
			count++;
		}
		
		//for(int i=0;i<length;i++)cout<<A[i]<<' ';
		Addition(A,a,B,b);		
	}
	}while(choice!='0');

return 0;
}

