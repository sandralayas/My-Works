/*

RADIX SORT

*/

#include<iostream>
using namespace std;

int main(void){
	int list[3]={125,124,123},endlist[3];
	int num,last,large;
	
	for(int i=0;i<3;i++){
		num=list[i];
		last=num%10;
		cout<<" "<<last<<" ";
		endlist[i]={last,i};
		
		for(int j=0;j<3;j++){
			large=j
			if(endlist[j+1]>endlist[j])
		}
	}

cout<<"\n Program terminated !!\n";
return 0;
}


