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
    void matrix_add(Matrix*);
    void matrix_mult(Matrix*);
    void matrix_transpose(void);
    void cofactor(void);
    void matrix_determinant(void);
    
    int matrix_trace(void);
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

void Matrix::matrix_add(Matrix *a){
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<putelement(i,j)+a->putelement(i,j)<<" ";
        }
        cout<<endl;
    }
}

void Matrix::matrix_mult(Matrix *a){
	int sq;
    if(d1<=d2)sq=d1;else sq=d2;
    for(int i=0;i<d1;i++){
        for(int j=0;j<a->d2;j++){
            int ans=0;
            for(int k=0;k<sq;k++){
                ans=ans+(putelement(i,k)*a->putelement(k,j));
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}

void Matrix::matrix_transpose(){
Matrix transpose(d2,d1);
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++)
            transpose.getelement(j,i,putelement(i,j));
    }

    for(int i=0;i<transpose.d1;i++){
        for(int j=0;j<transpose.d2;j++)
            cout<<transpose.putelement(i,j)<<" ";

        cout<<endl;
    }
}

int Matrix::matrix_trace(){
	int sum=0;
	for(int i=0;i<d1;i++){sum+=putelement(i,i);}
	return sum;
}
        	
int main(void){
int exit,user;
Matrix *A,*B;
do{
    int m1,n1,m2,n2;

    cout<<"\n 1. Trace";
    cout<<"\n 2. Transpose";
    cout<<"\n 3. Addition";
    cout<<"\n 4. Multiplication";
    cout<<"\n\n Enter your choice : ";cin>>user;


    cout<<"\nEnter the size of the first matrix : \n";
    cin>>m1>>n1;
    A=new Matrix(m1,n1);
    A->input();
    cout<<"\nEntered first matrix :\n";
    A->output();

if(user==3 or user==4){

    cout<<"\nEnter the size of the second matrix : \n";
    cin>>m2>>n2;
    B=new Matrix(m2,n2);
    B->input();
    cout<<"\nEntered second matrix :\n";
    B->output();
}

switch(user){

	case 1:
//trace
    
    if(m1==n1){
    cout<<"\nTrace of first:\n";
    cout<<A->matrix_trace()<<"\n";
    }
    else{cout<<"\nTrace not possible\n";}

	break;

	case 2:
//transpose
    
    cout<<"\nTranspose of first:\n";
    A->matrix_transpose();

	break;

	case 3:
//addition

    if(m1==m2 && n1==n2){
    cout<<"\nAddition :\n";
    A->matrix_add(B);
    }
    else{cout<<"\nAddition not possible\n";}

	break;

	case 4:
//Mutiplication

    if(n1!=m2){cout<<"\nMultiplication not possible\n";}
    else{
    cout<<"\nMultiplication :\n";
    A->matrix_mult(B);
    }

	break;

	default:break;
}
cout<<"\n Enter '0' to stop the program : ";cin>>exit;
}while(exit!=0);

return 0;
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
    cout<<"\n\nupper triangular matix\n\n";


    A.uppertri();cout<<"\n\n";B.uppertri();

    for(int i=0;i<d1-1;i++){
        for(int k=i;k<d1;k++){
            getelement(i,k,putelement(i,k)/putelement(j,i));
        }
        i++;
        for(int j=0;j<d2;j++){
        }
        cout<<endl;
    }

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
