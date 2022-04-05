/*Write a C++ program to demonstrate the concept of Multiple and Multilevel
inheritance including constructors with parameters.*/

#include<iostream>
using namespace std;

class Person{
	private:
	int adhar;

	public:
	Person(){}
	Person(int a){adhar=a;}
	
    bool check_adhar(int a){
        if(adhar==a) return true;
        return false;
    }
    void show_person(){
        cout<<"\n The Adhar card number of the person is : "<<adhar;
        cout<<"\n";
    }
};

class Health:virtual public Person{
    private:
    bool vaccination;

    public:
    Health(){}
    Health(int a,bool v):Person(a){vaccination=v;}

    void show_health(){
        if(vaccination)cout<<"\n The person is vaccinated";
        else cout<<"\n The person is not vaccinated";
        cout<<"\n";
    }
};

class Academics{
    private:
    double marks;

    public:
    Academics(){}
    Academics(double m){marks=m;}

    void show_academics(){
        cout<<"\n The score for academics the person is : "<<marks;
        cout<<"\n";
    }
};

class Details:public  Academics, public Health{
    private:
    int adhar;
    double marks;
    bool vaccination;

    public:
    Details(){}
    Details(int r,double a,bool b):Person(r),Academics(a),Health(r,b){
        adhar=r;
        marks=a;
        vaccination=b;
    }

    void show(){
        cout<<"\n The vaccination status of '"<<adhar<<"' is : ";
        if(vaccination)cout<<"Vaccinated";else cout<<"Not vaccinated";
        cout<<"\n The academics status of '"<<adhar<<"' is : "<<marks;
        cout<<"\n";
    }
};

int main(){

string choice;

int adhar,num=0,count=0,pep;double marks;bool vaccination;


Details people[100];
Details person(0,0,false);

cout<<"\n Enter the number of people : ";cin>>pep;
while(count!=pep){
    cout<<"\n Enter the Adhar number of person "<<count+1<<" : ";cin>>adhar;
    cout<<" Enter the score for academics : ";cin>>marks;
    int choice;
    cout<<" Enter whether the person is vacinated of not\
    \n 1. Vaccinated\
    \n 2. Not vaccinated\
    \n\n Enter the option : ";cin>>choice;
    if(choice==1)vaccination=true;
    else vaccination=false;

    Details temp(adhar,marks,vaccination);
    people[count]=temp;count++;
}

cout<<"\n All the details of people saved\
\n Enter the Adhar number of the person to check : ";cin>>adhar;

    do{
	
	if(choice!="5"){
    	while(true){
        	num=count;
        	while(num>=0){
        	    if(people[num].check_adhar(adhar)){
        	        person=people[num];break;
        	    }
        	    num--;
        	}
        	if(num==-1){
        	    cout<<"\n Invalid Adhar number\
        	    \n Enter the roll number again : ";cin>>adhar;
        	}
        	else break;
    	}
	}
	else choice=="4";

    cout<<" \n 0. Exit the program\
            \n 1. Display the marks for academics\
            \n 2. Display the vaccination status\
            \n 3. Display the details\
            \n 4. Check another person\
			\n 5. Enter the details of new person\
            \n\n  Enter your choice : ";cin>>choice;

    if(choice=="0")break;
    else if(choice=="1"){
        person.show_person();person.show_academics();
    }
    else if(choice=="2"){
        person.show_person();person.show_health();
    }
    else if(choice=="3"){
        person.show_person();person.show();
    }
    else if(choice=="4"){
        cout<<"\n Enter the Adhar number of the person to check : ";cin>>adhar;
    }
	else if(choice=="5"){
		int num=1;
    	cout<<"\n Enter the number of people : ";cin>>pep;
		while(num<=pep){
            cout<<"\n Enter the Adhar number of person "<<count+1<<" : ";
			cin>>adhar;
            cout<<" Enter the score for academics : ";cin>>marks;
            int choice;
            cout<<" Enter whether the person is vacinated of not\
            \n 1. Vaccinated\
            \n 2. Not vaccinated\
            \n\n Enter the option : ";cin>>choice;
            if(choice==1)vaccination=true;
            else vaccination=false;

            Details temp(adhar,marks,vaccination);
            people[count]=temp;count++;

			num++;
        }
	}
    else cout<<"\n Invalid choice !!\n";

    }while(choice!="0");
return 0;    
}

