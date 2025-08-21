/* Operations on a Sparce matrix*/

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

int Non_zero(Matrix *A,int row,int col){
	int count=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(A->give_element(i,j)!=0)count++;
		}
	}
	return count;
}

void Transpose(Matrix *SP_MA,int ROW,int COL,Matrix *RMO){
	int k=1;
	RMO->set_element(0,0,ROW);
	RMO->set_element(0,1,COL);
	
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			if(SP_MA->give_element(i,j)!=0){
				RMO->set_element(k,0,i);
				RMO->set_element(k,1,j);
				RMO->set_element(k,2,SP_MA->give_element(i,j));
				k++;
			}
		}
	}
	RMO->set_element(0,2,k-1);
}

int main(void){
	int ROW,COL;
	cout<<"\n\n Enter the Sparce matrix";
	cout<<"\n\n Enter the number of rows : ";cin>>ROW;
	cout<<" Enter the number of columns : ";cin>>COL;
	
	Matrix *SP_MA;
	SP_MA=new Matrix(ROW,COL);
	SP_MA->input();
	
	int Row=Non_zero(SP_MA,ROW,COL);
	Matrix *RMO;
	RMO=new Matrix(Row+1,3);	

	char choice;
	
	do{
		cout<<"\n\n Enter 0 to exit the program\
\n Enter 1 to input Sparce matrix\
\n Enter 2 to print the sparce matrix\
\n Enter 3 to output the transpose\
\n\n Enter the choice : ";cin>>choice;
		
		if(choice=='0')break;
		else if(choice=='1'){
			cout<<"\n\n Enter the Sparce matrix";
			cout<<"\n Enter the number of rows : ";cin>>ROW;
			cout<<"\n Enter the number of columns : ";cin>>COL;
	
			SP_MA=new Matrix(ROW,COL);
			SP_MA->input();
		}
		else if(choice=='2'){
			cout<<"\n The Sparce matrix\n\n";
			SP_MA->output();
		}
		else if(choice=='3'){
			
			Transpose(SP_MA,ROW,COL,RMO);
			RMO->output();
		}
	}while(choice!='0');

return 0;
}
