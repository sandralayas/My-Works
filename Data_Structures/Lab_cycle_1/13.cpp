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

string Cut(string sub,int l_sub,string main,int l_main){
	
	string LEFT,RIGHT;
	int index=Index(sub,l_sub,main,l_main);	
	LEFT=Substring(main,0,index);
	RIGHT=Substring(main,index+l_sub,l_main-index);
	
	return LEFT+RIGHT+"\0";
}

/*
int main(void){
	cout<<Cut("e",1,"ae",2)<<endl;
	//cout<<Index("laya",4,"Sandralaya",10)<<endl;

return 0;
}
*/	

int main(void){

	char choice;
	string The_string;
	int The_sublength,The_length,The_position;
	do{
		cout<<"\n\n 0. Exit the program\
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
			string post_substring,pre_substring,The_insertion;
		
			cout<<"\n Enter the substring : ";cin>>The_insertion;
			cout<<" Enter the length of substring : ";cin>>The_sublength;
			cout<<" Enter the position to insert : ";cin>>The_position;
			
			post_substring=Substring(The_string,The_position,The_length-The_position);
			
			pre_substring=Cut(post_substring,\
			The_length-The_position,The_string,The_length);
			
			
			The_string=pre_substring+The_insertion+post_substring+"\0";
			The_length=The_length+The_sublength;
			cout<<"\n The substring inserted";
			
		}
		else if(choice=='3'){
			string The_deletion;
		
			cout<<"\n Enter the substring : ";cin>>The_deletion;
			cout<<" Enter the length of substring : ";cin>>The_sublength;
			
			int index=Index(The_deletion,The_sublength,The_string,The_length);
			if(index==-1){
				cout<<"\n The substring not found";
			}
			else{
				The_string=Cut(The_deletion,The_sublength,The_string,The_length);
				cout<<"\n The substring deleted";
				The_length=The_length-The_sublength;
			}
		}
		else if(choice=='4'){
			string The_deletion;
		
			cout<<"\n Enter the substring to replace : ";cin>>The_deletion;
			cout<<" Enter the length of substring : ";cin>>The_sublength;
			
			int index=Index(The_deletion,The_sublength,The_string,The_length);
			if(index==-1){
				cout<<"\n The substring not found";
			}
			else{			
				string post_substring,pre_substring,The_insertion,remaining;
				int remaining_l;

				remaining=Cut(The_deletion,The_sublength,The_string,The_length);
				remaining_l=The_length-The_sublength+1;
		
				cout<<"\n Enter the new substring : ";cin>>The_insertion;
				The_position=index;
			
				post_substring=Substring(remaining,The_position,\
				The_length-The_sublength-index+1);
			
				pre_substring=Cut(post_substring,The_length-The_sublength-index+1\
				,remaining,remaining_l);
			
				The_string=pre_substring+The_insertion+post_substring+"\0";
				cout<<"\n The substring replaced";
			}
		}
		else if(choice=='5'){
			cout<<"\n The string is : "<<The_string<<endl;
		}
	}while(choice!='0');
	
return 0;
}


