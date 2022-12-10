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

void Sum_Sparce(Matrix *A,Matrix *B,Matrix *S){
	int ROW,COL,k;
	
	if(A->give_element(0,0)==B->give_element(0,0)and\
	A->give_element(0,1)==B->give_element(0,1)){
	
		ROW=A->give_element(0,0);
		COL=A->give_element(0,1);
		int k=1,m=1,n=1;
		
		for(int i=0;i<ROW;i++){
			for(int j=0;j<COL;j++){
				if(A->give_element(m,0)==i and\
				A->give_element(m,1)==j and\
				B->give_element(n,0)==i and\
				B->give_element(n,1)==j){
					
					S->set_element(k,0,i);
					S->set_element(k,1,j);
					S->set_element(k,2,\
					A->give_element(m,2)+B->give_element(n,2));
					k++;m++;n++;
				}
				else if(A->give_element(m,0)==i and\
				A->give_element(m,1)==j){
					
					S->set_element(k,0,i);
					S->set_element(k,1,j);
					S->set_element(k,2,\
					A->give_element(m,2));
					k++;m++;
				}
				else if(B->give_element(n,0)==i and\
				B->give_element(n,1)==j){
					
					S->set_element(k,0,i);
					S->set_element(k,1,j);
					S->set_element(k,2,\
					B->give_element(n,2));
					k++;n++;
				}
			}
		}
	}
	else cout<<"\n Matrix Addition not possible\n";
	
	S->set_element(0,0,ROW);
	S->set_element(0,1,COL);
	S->set_element(0,2,k-1);
}

int main(void){

	// sparce
	int ROW1,COL1;
	cout<<"\n\n Enter the First Sparce matrix";
	cout<<"\n\n Enter the number of rows : ";cin>>ROW1;
	cout<<" Enter the number of columns : ";cin>>COL1;
	
	Matrix *SP_MA1;
	SP_MA1=new Matrix(ROW1,COL1);
	SP_MA1->input();
	
	int ROW2,COL2;
	cout<<"\n\n Enter the Second Sparce matrix";
	cout<<"\n\n Enter the number of rows : ";cin>>ROW2;
	cout<<" Enter the number of columns : ";cin>>COL2;
	
	Matrix *SP_MA2;
	SP_MA2=new Matrix(ROW2,COL2);
	SP_MA2->input();	

	// transpose
	int Row1=Non_zero(SP_MA1,ROW1,COL1);
	Matrix *RMO1;
	RMO1=new Matrix(Row1+1,3);
	
	int Row2=Non_zero(SP_MA2,ROW2,COL2);
	Matrix *RMO2;
	RMO2=new Matrix(Row2+1,3);
	
	// sum
	Matrix *SUM;
	SUM=new Matrix(Row2+1,3);

	char choice;
	
	do{
		cout<<"\n\n Enter 0 to exit the program\
\n Enter 1 to input Sparce matrix\
\n Enter 2 to print the sparce matrix\
\n Enter 3 to output the transpose\
\n Enter 4 to output the sum\
\n\n Enter the choice : ";cin>>choice;
		
		if(choice=='0')break;
		else if(choice=='1'){
			cout<<"\n\n Enter the First Sparce matrix";
			cout<<"\n\n Enter the number of rows : ";cin>>ROW1;
			cout<<" Enter the number of columns : ";cin>>COL1;
	
			SP_MA1=new Matrix(ROW1,COL1);
			SP_MA1->input();
	
			cout<<"\n\n Enter the Second Sparce matrix";
			cout<<"\n\n Enter the number of rows : ";cin>>ROW2;
			cout<<" Enter the number of columns : ";cin>>COL2;
	
			SP_MA2=new Matrix(ROW2,COL2);
			SP_MA2->input();
			
			int Row1=Non_zero(SP_MA1,ROW1,COL1);
			RMO1=new Matrix(Row1+1,3);
	
			int Row2=Non_zero(SP_MA2,ROW2,COL2);
			RMO2=new Matrix(Row2+1,3);
			
			SUM=new Matrix(Row2+1,3);
			
		}
		else if(choice=='2'){
			cout<<"\n The First Sparce matrix\n\n";
			SP_MA1->output();
			
			cout<<"\n The Second Sparce matrix\n\n";
			SP_MA2->output();
		}
		else if(choice=='3'){
			
			Transpose(SP_MA1,ROW1,COL1,RMO1);
			cout<<"\n The First transpose matrix\n\n";
			RMO1->output();
			
			Transpose(SP_MA2,ROW2,COL2,RMO2);
			cout<<"\n The Second transpose matrix\n\n";
			RMO2->output();
		}
		else if(choice=='4'){
			
			Sum_Sparce(RMO1,RMO2,SUM);
			cout<<"\n The Sum matrix\n\n";
			SUM->output();
			
		}
	}while(choice!='0');

return 0;
}
