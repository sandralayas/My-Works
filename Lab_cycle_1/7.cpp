/*Write a C++ program to implement a class MATRIX with member functions such
as matrix_add, matrix_mult, matrix_transpose, matrix_determinant etc.*/

#include <iostream>
using namespace std;

class Matrix{
    int **p;
    int d1,d2;
    public:
    Matrix(void){}
    Matrix(int x,int y);
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
    void matrix_add(Matrix);
    void matrix_mult(Matrix);
    void matrix_transpose(void);
    void cofactor(void);
    void matrix_determinant(void);
    
    int matrix_trace(void);
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

/*
void Matrix::matrix_determinant(){
	for(int i=0;i<d1;i++){
		for(int j=0;j<d2;j++){
			
}

void Matrix::cofactor(){
	int count=0
	while count!=0;
		for(int i=0;i<d1;i++){
			for(int j=0;j<d2;j++){
				if(i!=1 && j!=count){

}
*/

int Matrix::matrix_trace(){
	int sum=0;
	for(int i=0;i<d1;i++){sum+=putelement(i,i);}
	return sum;
}
        	

int main(void){
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
    cout<<"\n\nupper triangular matix\n\n";


    A.uppertri();cout<<"\n\n";B.uppertri();
*/
    cout<<"\nTrace of first:\n";
    cout<<A.matrix_trace()<<"\n";

    cout<<"\nTrace of second:\n";
    cout<<B.matrix_trace()<<"\n";

    cout<<"\nTranspose of first:\n";
    A.matrix_transpose();

    cout<<"\nTranspose of second:\n";
    B.matrix_transpose();


    cout<<"\nAddition :\n";
    A.matrix_add(B);

    cout<<"\nMultiplication :\n";
    A.matrix_mult(B);
return 0;
}

/*
    for(int i=0;i<d1-1;i++){
        for(int k=i;k<d1;k++){
            getelement(i,k,putelement(i,k)/putelement(j,i));
        }
        i++;
        for(int j=0;j<d2;j++){
        }
        cout<<endl;
    }
*/

/*
//upper triangulsr matrix

void Matrix::uppertri(){
Matrix X(d1,d2);
    
int row=0;
for(int k=0;k<d1-1;k++){
    for(int i=0;i<d1;i++){
        int ans=(putelement(row,i)/putelement(row,row));
        X.getelement(row,i,ans);
    }

    for(int r=0;r<d1-1;r++){
        for(int i=0;i<d1;i++){
            int ans=((putelement(r,i)*putelement(row,i))-putelement(r,i));
            X.getelement(r,i,ans);
        }
    }
    row++;
}
X.output();
}
//upper triangular matrix
*/
