/* Extraction of substring from a string*/

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

int main(void){
	char choice;
	string The_string,The_substring;
	int The_position,The_length;
	do{
		cout<<"\n 0. Exit the program\
\n 1. Enter the string\
\n 2. Find the substring\
\n\n Enter your choice : ";cin>>choice;
		if(choice=='0')break;
		else if(choice=='1'){
			cout<<"\n Enter the string : ";cin>>The_string;
		}
		else if(choice=='2'){
			cout<<"\n Enter the position of the substring : ";cin>>The_position;
			cout<<"\n Enter the length of the substring : ";cin>>The_length;
			The_substring=Substring(The_string,The_position,The_length);
			cout<<"\n The substring found is : "<<The_substring<<endl;
		}
	}while(choice!='0');
	
return 0;
}



