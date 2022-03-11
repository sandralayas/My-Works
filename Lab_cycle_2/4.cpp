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
    Matrix(){}
    Matrix(int x,int y);
    void getelement(int i,int j,float value){
        p[i][j]=value;
    }
    int putelement(int i,int j){
        return p[i][j];
    }
    void output(){
        for(int i=0;i<d1;i++){
            for(int j=0;j<d2;j++){
                cout<<putelement(i,j)<<" ";
            }
            cout<<endl;
        }
    }
    void input(){
        cout<<"Enter the elements row by row : \n";
        int value;
        for(int i=0;i<d1;i++){
            for(int j=0;j<d2;j++){
                cin>>value;
                getelement(i,j,value);
            }
        }
    }
    void matrix_add(Matrix);
    void matrix_mult(Matrix);
    void matrix_transpose();
    void matrix_cofactor();
    void matrix_determinant();
};

Matrix::Matrix(int x,int y){
    d1=x;
    d2=y;
    p=new int *[d1];
    for(int i=0;i<d1;i++){
        p[i]=new int [d2];
    }
}

void Matrix::matrix_add(Matrix a){
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<putelement(i,j)+a.putelement(i,j)<<" ";
        }
        cout<<endl;
    }
}

void Matrix::matrix_mult(Matrix a){
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            int ans=0;
            for(int k=0;k<d1;k++){
                ans=ans+(putelement(i,k)*a.putelement(k,j));
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}

void Matrix::matrix_transpose(){
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<putelement(j,i)<<" ";
        }
        cout<<endl;
    }
}

void Matrix::matrix_determinant(){}

main(){
    int m,n;
    cout<<"\nEnter the size of the first matrix : \n";
    cin>>m>>n;
    Matrix A(m,n);
    A.input();
    cout<<"\nEnter the size of the second matrix : \n";
    cin>>m>>n;
    Matrix B(m,n);
    B.input();
    cout<<"\nEntered first matrix :\n";
    A.output();
    cout<<"\nEntered second matrix :\n";
    B.output();
    
/*
    cout<<"\nTranspose of first:\n";
    A.matrix_transpose();

    cout<<"\nTranspose of second:\n";
    B.matrix_transpose();


    cout<<"\nAddition :\n";
    A.matrix_add(B);

    cout<<"\nMultiplication :\n";
    A.matrix_mult(B);
*/
    cout<<"\n\nupper triangular matix\n\n";
    A.uppertri();cout<<"\n\n";B.uppertri();
}
