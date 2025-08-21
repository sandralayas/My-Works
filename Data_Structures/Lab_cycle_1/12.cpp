/* Extraction of matched pattern from a string*/

#include<iostream>
using namespace std;

int Substring(string P,int R,string T,int S){
	int K=0,MAXI=S-R+1,INDEX,count=0;
	while(K<=MAXI){
		for(int L=0;L<R;L++){
			if(P[L]!=T[K+L-1]){
				count=0;
				break;
			}
			count++;
			INDEX=K;
			if(count==R)return INDEX-1;
		}
		K++;
	}
	INDEX=-1;
	return INDEX;
}

int main(void){

	char choice;
	string The_string,The_substring;
	int The_sublength,The_length,The_index;
	do{
		cout<<"\n 0. Exit the program\
\n 1. Enter the string\
\n 2. Find the substring\
\n\n Enter your choice : ";cin>>choice;
		if(choice=='0')break;
		else if(choice=='1'){
			cout<<"\n Enter the string : ";cin>>The_string;
			cout<<" Enter the length of the string : ";cin>>The_length;
		}
		else if(choice=='2'){
			cout<<"\n Enter the substring : ";cin>>The_substring;
			cout<<" Enter the length of the substring : ";cin>>The_sublength;
			
			The_index=Substring(The_substring,The_sublength,The_string,The_length);
			cout<<"\n The substring found at index : "<<The_index<<endl;
		}
	}while(choice!='0');
	
return 0;
}
