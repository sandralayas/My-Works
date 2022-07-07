/* Operations on a a string*/

#include<iostream>
using namespace std;

string Substring(string STR,int POS,int L){
	string SUB;
	for(int i=0;i<L;i++){
		SUB=SUB+STR[POS];
		POS++;
	}
	SUB=SUB+"\0";
	return SUB;
}

int Index(string P,int R,string T,int S){
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
	string The_string,post_substring,pre_substring,The_insertion;
	int The_sublength,The_length,The_position;
	do{
		cout<<"\n 0. Exit the program\
\n 1. Enter the string\
\n 2. Insertion\
\n 3. Deletion\
\n 4. Replacement\
\n 5. Display the string\
\n\n Enter your choice : ";cin>>choice;
		if(choice=='0')break;
		else if(choice=='1'){
			cout<<"\n Enter the string : ";cin>>The_string;
			cout<<" Enter the length of the string : ";cin>>The_length;
		}
		else if(choice=='2'){
			cout<<"\n Enter the substring : ";cin>>The_insertion;
			cout<<" Enter the length of substring : ";cin>>The_sublength;
			cout<<" Enter the position to insert : ";cin>>The_position;
			
			post_substring=Substring(The_string,The_position,The_length-The_position);
			
			cout<<The_substring<<"\n";
			
			The_string=The_string+The_insertion+post_substring+"\0";
			
		}
		else if(choice=='5'){
			cout<<"\n The string is : "<<The_string<<endl;
		}
	}while(choice!='0');
	
return 0;
}
