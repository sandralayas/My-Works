/*Write a C++ program to demonstrate the order of execution of constructors &
destructors.*/

#include <iostream>
using namespace std;

class Matrix{
    int **p;
    int d1,d2;
    public:
    Matrix(int x,int y);
    void getelement(int i,int j,int value){
        p[i][j]=value;
    }
    int putelement(int i,int j){
        return p[i][j];
    }
    ~Matrix(void);
};

Matrix::~Matrix(void){
    for(int i=0;i<d1;i++){
        delete p[i];
    }
    delete p;
    cout<<"\nMemory relesed !!\n";
}

Matrix::Matrix(int x,int y){
    d1=x;
    d2=y;
    p=new int *[d1];
    for(int i=0;i<d1;i++){
        p[i]=new int [d2];
    }
    cout<<"\nMemory created !!\n";
}

int main(void){
    int m,n;
    cout<<"Enter the size of matrix : \n";
    cin>>m>>n;
    Matrix A(m,n);
    cout<<"Enter the elements row by row : \n";
    int value;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>value;
            A.getelement(i,j,value);
        }
    }
    cout<<"Entered matrix :\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<A.putelement(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<"Transpose matrix :\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<A.putelement(j,i)<<" ";
        }
        cout<<endl;
    }
return 0;
}
