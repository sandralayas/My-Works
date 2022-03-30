/*Write a C++ program to overload ==, !=, <, <=, > and >= operators as
member operator functions for a vector object.*/

#include<iostream>
#include<math.h>
using namespace std;

class Vector{
    private:
    int xaxis,yaxis,zaxis;
    public:
    Vector(void){}
    Vector(double x,double y,double z){xaxis=x;yaxis=y;zaxis=z;}
    void output(void){
	char opera1=' ',opera2=' ';
	if(yaxis>=0)opera1='+';
	if(zaxis>=0)opera2='+';
	cout<<" "<<xaxis<<"i "<<opera1<<yaxis<<"j "<<opera2<<zaxis<<"k";
	}
    double magnitude(void){return sqrt(xaxis*xaxis+yaxis*yaxis+zaxis*zaxis);}

    bool operator==(Vector);
    bool operator!=(Vector);

    bool operator<(Vector);
    bool operator>(Vector);

    bool operator<=(Vector);
    bool operator>=(Vector);
};

bool Vector::operator==(Vector vector){
    if(magnitude()==vector.magnitude()){return true;}
    else{return false;}
}

bool Vector::operator!=(Vector vector){
    if(magnitude()!=vector.magnitude()){return true;}
    else{return false;}
}

bool Vector::operator<(Vector vector){
    if(magnitude()<vector.magnitude()){return true;}
    else{return false;}
}

bool Vector::operator>(Vector vector){
    if(magnitude()>vector.magnitude()){return true;}
    else{return false;}
}

bool Vector::operator<=(Vector vector){
    if(magnitude()<=vector.magnitude()){return true;}
    else{return false;}
}

bool Vector::operator>=(Vector vector){
    if(magnitude()>=vector.magnitude()){return true;}
    else{return false;}
}

int main(void){
string choice;
int a=0;

Vector vector1,vector2;
int x1,y1,z1, x2,y2,z2;

do{
if(a==0){
    
    cout<<" \n Enter the first vector : ";
    cin>>x1>>y1>>z1;
    cout<<" \n Enter the second vector : ";
    cin>>x2>>y2>>z2;
    Vector vector1(x1,y1,z1),vector2(x2,y2,z2);
    vector1.output();cout<<endl;vector2.output();cout<<endl;
a=2;
}

Vector vector1(x1,y1,z1),vector2(x2,y2,z2);

cout<<"\n\n Enter '0' to exit \
		\n 1. Check if they are equal \
		\n 2. Check if they are not equal \
		\n 3. Check if first vector is greater than second \
        \n 4. Check if second vector is greater than first \
        \n 5. Check if first vector is greater than or equal second \
        \n 6. Check if second vector is greater than or equal first \
		\n\n Enter your choice : ";cin>>choice;

if(choice=="0")break;

else if(choice=="1"){
    if(vector1==vector2){cout<<"\n They are equal\n\n";}
	else{cout<<"\n They are not equal\n\n";}
}
else if(choice=="2"){
    if(vector1!=vector2){cout<<"\n They are not equal\n\n";}
	else{cout<<"\n They are equal\n\n";}
}
else if(choice=="3"){
    if(vector1>vector2){vector1.output();cout<<" > ";vector2.output();cout<<endl;}
	else{cout<<"\n No\n\n";}
}
else if(choice=="4"){
    if(vector1<vector2){vector1.output();cout<<" < ";vector2.output();cout<<endl;}
	else{cout<<"\n No\n\n";}
}
else if(choice=="5"){
    if(vector1>=vector2){vector1.output();cout<<" >= ";vector2.output();cout<<endl;}
	else{cout<<"\n No\n\n";}
}
else if(choice=="6"){
    if(vector1<=vector2){vector1.output();cout<<" <= ";vector2.output();cout<<endl;}
	else{cout<<"\n No\n\n";}
}
else cout<<"\n Invalid choice !!\n\n";

}while(choice!="0");
return 0;
}
