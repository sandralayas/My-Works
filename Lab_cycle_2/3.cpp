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
int exit;
do{
    int x1,y1,z1, x2,y2,z2;
    cout<<" \n\n Enter the first vector : ";
    cin>>x1>>y1>>z1;
    cout<<" \n\n Enter the second vector : ";
    cin>>x2>>y2>>z2;
    Vector vector1(x1,y1,z1),vector2(x2,y2,z2);
    vector1.output();cout<<" : first\n";vector2.output();cout<<" : second\n\n";

    cout<<" Product : "<<(vector1*vector2)<<"\n\n";

    cout<<" first vector << second vector"<<"\n";
    vector1<<vector2;
    vector1.output();cout<<" : first\n";vector2.output();cout<<" : second\n";

    cout<<" first vector >> second vector"<<"\n\n";
    vector1>>vector2;
    vector1.output();cout<<" : first\n";vector2.output();cout<<" : second\n";

    cout<<"\n\n";
cout<<"\n Enter '0' to exit the program : ";cin>>exit;
}while(exit);
return 0;
}
