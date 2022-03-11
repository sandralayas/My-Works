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
int exit;
do{
    int x1,y1,z1, x2,y2,z2;
    cout<<" \n Enter the first vector : ";
    cin>>x1>>y1>>z1;
    cout<<" \n Enter the second vector : ";
    cin>>x2>>y2>>z2;
    Vector vector1(x1,y1,z1),vector2(x2,y2,z2);
    vector1.output();cout<<endl;vector2.output();cout<<endl;

    if(vector1==vector2){cout<<"\n They are equal\n\n";}
    if(vector1!=vector2){cout<<"\n They are not equal\n\n";}
    if(vector1>vector2){vector1.output();cout<<" > ";vector2.output();cout<<endl;}
    if(vector1<vector2){vector1.output();cout<<" < ";vector2.output();cout<<endl;}
    if(vector1>=vector2){vector1.output();cout<<" >= ";vector2.output();cout<<endl;}
    if(vector1<=vector2){vector1.output();cout<<" <= ";vector2.output();cout<<endl;}
    cout<<"\n\n";
cout<<"\n Enter '0' to exit the program : ";cin>>exit;
}while(exit);
return 0;
}
