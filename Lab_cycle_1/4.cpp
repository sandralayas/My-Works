//Write a C++ progtram to perform operations such as compare, concatenate and
//length on String objects.

#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

class String{

	char *the_string;
	int len;
	public:
	String(void){len=0;the_string=new char[len+1];}
	String(const char *input){
		len=strlen(input);
		the_string=new char[len+1];
		strcpy(the_string,input);
	}
	//void input(string a){String(a);}
    bool operator>(String &a){
        if(len>a.len){return true;}
        else{return false;}
    }
	bool operator<(String &a){
        if(len<a.len){return true;}
        else{return false;}
    }
    String operator+(String &a);
    char output(void){cout<<the_string;}
	~String(void){delete the_string;}
	void length(void){cout<<len;}

};

String String::operator+(String &a){
	String b;
	b.len=a.len+len;
	b.the_string=new char[b.len+1];
	strcpy(b.the_string,the_string);
	strcat(b.the_string,a.the_string);
	return b;
}

int main(void){
int user;
do{
	
	string input1,input2;
	//string *char1,*char2;
	
    cout<<"\n";
    cout<<" Enter the first string :";
    cin>>input1;
	const char *char1=input1.c_str();
	String string1(char1);
    cout<<"\n";

    cout<<" Enter the second string :";
    cin>>input2;
	const char *char2=input2.c_str();
	String string2(char2);
  
	cout<<"\n\n The length of first string : ";string1.length();
	cout<<"\n The length of second string : ";string2.length();cout<<"\n\n";

    if(string1>string2){
		cout<<"\n '";
		string1.output();
		cout<<"' has greater length than '";
		cout<<string2.output()<<"'\n\n";
	}
    else if(string1<string2){
		cout<<"\n '";
		string2.output();
		cout<<"' has greater length than '";
		cout<<string1.output()<<"'\n\n";
	}
	else{
		cout<<"\n '";
		string2.output();
		cout<<"' and '";
		cout<<string1.output()<<"' has equal length\n\n";
	}

    cout<<" Concatinated product : '";string1.output();
	cout<<"' + '";string2.output();cout<<"' = '";
	(string1+string2).output();cout<<"'\n\n";

	cout<<"\n The length of concatinated string : ";(string1+string2).length();	
	
	cout<<"\n\n Enter '0' to exit the programe : ";cin>>user;
}while(user!=0);
return 0;
}
