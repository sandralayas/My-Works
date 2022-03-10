//Write a C++ progtram to perform operations such as compare, concatenate and
//length on String objects.

#include<iostream>
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

	void input(void){cin>>the_string;}
    
    bool operator>=(String a){
        if(len>=a.len){return true;}
        else{return false;}
    }
    String operator+(String a);

    char output(void){cout<<the_string;}
};

int str_length(string a){return a.length();}

String String::operator+(String a){
	String b;
	b.len=a.len+len;
	b.the_string=new char[b.len+1];
	strcpy(b.the_string,the_string);
	strcat(b.the_string,a.the_string);
	return b;
}

int main(void){

	String string1;String string2;

    cout<<"\n\n";
    cout<<"enter the first string :";
    string1.input();
    cout<<"\n\n";
    cout<<"enter the second string :";
    string2.input(); 
    cout<<"\n\n";
    

    if(string2>=string1){string1.output();cout<<" has greater length than ";cout<<string2.output()<<"\n\n";}
    else{string2.output();cout<<" has greater length than ";cout<<string1.output()<<"\n\n";}
    cout<<"concatinated product : ";

    string1.output();cout<<" + ";string2.output();cout<<" = ";(string1+string2).output();cout<<"\n\n";
return 0;
}

