/*

RADIX SORT

*/

#include<math.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(void){
	int list[3]={125,124,123},endlist[3];
	int num,last,large,count;
	bool non_zero;
	
	vector< pair <int,int> > the_pair;
	
	count=1;
	do{
		for(int i=0;i<3;i++){
			if(list[i]!=0){
				non_zero=true;
				break;
			}
			non_zero=false;
		}
		for(int i=0;i<3;i++){
			num=list[i];
			int power=(pow(10,count));
			last=num%power;
			cout<<" "<<last<<" ";
			endlist[i]=last;
		}
		for(int i=0;i<3;i++){
		    the_pair.push_back( make_pair(list[i],endlist[i]) );
		}
	
		for(int i=0;i<3;i++){
			int temp=the_pair[i].second,index;
			for(int j=0;j<3;j++){
				if(the_pair[j].second<temp){
					temp=the_pair[j].second;
					index=j;
				}
			}
			list[i]=(the_pair[index].first);
		}
		
	count++;
	}while(non_zero);
	
	for(int i=0;i<3;i++){
		cout<<list[i]<<" ";
	}

cout<<"\n Program terminated !!\n";
return 0;
}


