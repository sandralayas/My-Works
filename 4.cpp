//Write a C++ progtram to perform operations such as compare, concatenate and
//length on String objects.

#include<iostream>
using namespace std;

class String{

    string the_string;
    int len;

    public:
    String(){}

    String(string a,int b){the_string=a;len=b;}
    
    bool operator>=(String a){
        if(len>=a.len){return true;}
        else{return false;}
    }
    String operator+(String a);

    void output(){cout<<the_string<<"\n\n";}
};

int str_length(string a){return a.length();}

String String::operator+(String a){
    a.the_string=the_string+" "+a.the_string;
    a.len=a.len+len;
    return a;
}

main(){
    cout<<"\n\n";
    cout<<"enter the first string :";
    string a,b;
    cin>>a;
    cout<<"\n\n";
    cout<<"enter the second string :";
    cin>>b;
    cout<<"\n\n";
    String string1(a,str_length(a));String string2(b,str_length(b));

    if(string2>=string1){cout<<b<<" has greater length than "<<a<<"\n\n";}
    else{cout<<a<<" has greater length than "<<b<<"\n\n";}
    cout<<"concatinated product :";

    String temp=string1+string2;

    cout<<a<<" + "<<b<<" = ";
    temp.output();
}
