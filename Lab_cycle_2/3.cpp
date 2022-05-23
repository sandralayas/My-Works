/*Write a C++ program to overload operators like *, <<, >> using friend
function. The following overloaded operators should work for a class vector.*/

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

    friend double operator*(Vector,Vector);

    friend void operator<<(Vector&,Vector&);

    friend void operator>>(Vector&,Vector&);
};

double operator*(Vector vector1,Vector vector2){
    return (\
    vector1.xaxis*vector2.xaxis+\
    vector1.yaxis*vector2.yaxis+\
    vector1.zaxis*vector2.zaxis);
}

void operator<<(Vector &vector1,Vector &vector2){
    vector1.xaxis=vector2.xaxis;
    vector1.yaxis=vector2.yaxis;
    vector1.zaxis=vector2.zaxis;
}

void operator>>(Vector &vector1,Vector &vector2){
    vector2.xaxis=vector1.xaxis;
    vector2.yaxis=vector1.yaxis;
    vector2.zaxis=vector1.zaxis;
}


int main(void){

int x1,y1,z1, x2,y2,z2;
string exit;


    
cout<<" \n Enter the first vector : ";
cin>>x1>>y1>>z1;
cout<<" Enter the second vector : ";
cin>>x2>>y2>>z2;
    
do{

cout<<"\n---------------------------------------------------------------\n";
Vector vector1(x1,y1,z1),vector2(x2,y2,z2);
vector1.output();cout<<" : first\n";vector2.output();cout<<" : second";
cout<<"\n---------------------------------------------------------------\n";


cout<<"\n Enter '0' to exit the program\
\n Enter '1' to copy 1st to 2nd\
\n Enter '2' to copy 2nd to 1st\
\n Enter '3' to enter 1st to 2nd vectors\
\n Enter '4' for the product\
\n\n Enter your choice : ";cin>>exit;

if(exit=="1"){
    cout<<"\n first vector >> second vector"<<"\n\n";
    vector1>>vector2;
    vector1.output();cout<<" : first\n";vector2.output();cout<<" : second\n";
}
else if(exit=="2"){
    cout<<" first vector << second vector"<<"\n\n";
    vector1<<vector2;
    vector1.output();cout<<" : first\n";vector2.output();cout<<" : second\n";
}

else if(exit=="3"){
    cout<<" \n Enter the first vector : ";
    cin>>x1>>y1>>z1;
    cout<<" Enter the second vector : ";
    cin>>x2>>y2>>z2;
    Vector vector1(x1,y1,z1),vector2(x2,y2,z2);
    vector1.output();cout<<" : first\n";vector2.output();cout<<" : second\n\n";
}
else if(exit=="4")cout<<" Product : "<<(vector1*vector2)<<"\n\n";
else if(exit=="0")break;
else cout<<"\n Invalid choice\n";

}while(exit!="0");
return 0;
}
