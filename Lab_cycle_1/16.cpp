/* Saddle point of a Matrix*/

#include<iostream>
using namespace std;

class Matrix{
	int **p;
	int d1,d2;
	public:
	Matrix(void){}
	Matrix(int x,int y);
	~Matrix(void);
	
	void set_element(int i,int j,int value){
		p[i][j]=value;
	}
	int give_element(int i,int j){
		return p[i][j];
	}
	void output(void){
		for(int i=0;i<d1;i++){
			cout<<" ";
			for(int j=0;j<d2;j++){
				cout<<give_element(i,j)<<" ";
			}
			cout<<endl;
		}
	}
	void input(void){
		cout<<"\n Enter the elements row by row : \n";
		int value;
		for(int i=0;i<d1;i++){
			cout<<" ";
			for(int j=0;j<d2;j++){
				cin>>value;
				set_element(i,j,value);
			}
		}
	}
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

bool Saddle_point(Matrix *A,int row,int col){
	int big,temp,count=0;
	bool check;
	
	while(count<row){
		big=A->give_element(0,count);
		for(int i=0;i<col;i++){
			temp=A->give_element(i,count);
			if(temp>big)big=temp;
		}
		for(int i=0;i<col;i++){
			if(big==A->give_element(i,count)){
				for(int j=0;j<row;j++){
					temp=A->give_element(i,j);
					check=true;
					if(temp<big){
						check=false;
						count++;
						break;
					}
				}
				if(check){
					cout<<"\n The Saddle point is : "<<big<<endl;
					return true;
				}
			}
		}
	}
	return false;
}

int main(void){

	int ROW,COL,SADDLE;
	cout<<"\n\n Enter the Matrix";
	cout<<"\n\n Enter the number of rows : ";cin>>ROW;
	cout<<" Enter the number of columns : ";cin>>COL;
	
	Matrix *The_Matrix;
	The_Matrix=new Matrix(ROW,COL);
	The_Matrix->input();

	char choice;
	
	do{
		cout<<"\n\n Enter 0 to exit the program\
\n Enter 1 to the matrix\
\n Enter 2 to print matrix\
\n Enter 3 to output the saddle point\
\n\n Enter the choice : ";cin>>choice;
		
		if(choice=='0')break;
		else if(choice=='1'){
			cout<<"\n\n Enter the matrix";
			cout<<"\n\n Enter the number of rows : ";cin>>ROW;
			cout<<" Enter the number of columns : ";cin>>COL;
	
			The_Matrix=new Matrix(ROW,COL);
			The_Matrix->input();
			
		}
		else if(choice=='2'){
			cout<<"\n The matrix\n\n";
			The_Matrix->output();
		}
		else if(choice=='3'){
			SADDLE=Saddle_point(The_Matrix,ROW,COL);
			if(SADDLE==false){
				cout<<"\n The exists no Saddle point\n";
			}
		}
	}while(choice!='0');

return 0;
}

