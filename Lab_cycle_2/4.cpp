/*Write a C++ program for developing a matrix class which can handle integer
matrices of different dimensions. Also overload the operator for addition and
multiplication of matrices. Use double pointers in your program to dynamically
allocate memory for the matrices.*/

#include <iostream>
using namespace std;

class Matrix{
    int **p;
    int d1,d2;
    public:
    Matrix(void){}
    Matrix(int x,int y);
    ~Matrix(void);
    void getelement(int i,int j,int value){
        p[i][j]=value;
    }
    int putelement(int i,int j){
        return p[i][j];
    }
    void output(void){
        for(int i=0;i<d1;i++){
            for(int j=0;j<d2;j++){
                cout<<putelement(i,j)<<" ";
            }
            cout<<endl;
        }
    }
    void input(void){
        cout<<"Enter the elements row by row : \n";
        int value;
        for(int i=0;i<d1;i++){
            for(int j=0;j<d2;j++){
                cin>>value;
                getelement(i,j,value);
            }
        }
    }
    void operator+(Matrix&);
    void operator*(Matrix&);
};

Matrix::~Matrix(void){
    for(int i=0;i<d1;i++){
        delete p[i];
    }
    delete p;
    //cout<<"\nMemory relesed !!\n";
}

Matrix::Matrix(int x,int y){
    d1=x;
    d2=y;
    p=new int *[d1];
    for(int i=0;i<d1;i++){
        p[i]=new int [d2];
    }
}

void Matrix::operator+(Matrix &a){
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<putelement(i,j)+a.putelement(i,j)<<" ";
        }
        cout<<endl;
    }
}

void Matrix::operator*(Matrix &a){
    int sq;
    if(d1<=d2)sq=d1;else sq=d2;
    for(int i=0;i<d1;i++){
        for(int j=0;j<a.d2;j++){
            int ans=0;
            for(int k=0;k<sq;k++){
                ans=ans+(putelement(i,k)*a.putelement(k,j));
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}
        	
int main(void){
int exit,user;
//Matrix *A,*B;
do{
    int m1,n1,m2,n2;

    cout<<"\nEnter the size of the first matrix : \n";
    cin>>m1>>n1;
    Matrix A(m1,n1);
    A.input();
    cout<<"\nEntered first matrix :\n";
    A.output();

    cout<<"\nEnter the size of the second matrix : \n";
    cin>>m2>>n2;
    Matrix B(m2,n2);
    B.input();
    cout<<"\nEntered second matrix :\n";
    B.output();

int repeat=1;
while(repeat==1){

    cout<<"\n 1. Addition";
    cout<<"\n 2. Multiplication";
    cout<<"\n\n Enter your choice : ";cin>>user;

switch(user){

	case 1:
//addition

    if(m1==m2 && n1==n2){
    cout<<"\nAddition :\n";
    A+B;
    }
    else{cout<<"\nAddition not possible\n";}

	break;

	case 2:
//Mutiplication

    if(n2==m1){
    cout<<"\nMultiplication :\n";
    A*B;
    }
    else{cout<<"\nMultiplication not possible\n";}

	break;

	default:break;
}
cout<<"\n Enter '1' to continue with the same input : ";cin>>repeat;
}

cout<<"\n Enter '0' to stop the program : ";cin>>exit;
}while(exit!=0);

return 0;
}

