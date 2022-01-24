#include <iostream>
#include <math.h>
#include <string.h>
#include <sstream>
using namespace std;

main()
{
    cout<<"\nEnter the number of test cases :";
    int z;
    int c=0;
    int y;
    cin>>z;
    int a[z];
    cout<<"\nEnter "<<z<<" numbers having less than 10 digits :\n";
    for(int j=0;j<z;j++){
        cin>>a[j];
    }
    int x=0;
    for(int i=0;i<z;i++){
        x=a[i];
        ostringstream str;
        str<<x;
        string d = str.str();
        y=d.length()-1;
        while(x!=0){
            int b=x%10;
            c=c+b*(pow(10,y));
            x=floor(x/10);
            y=y-1;
        }
        cout<<"  \n";
        if(c==a[i]){
            cout<<a[i]<<" is palindrome\n";
        }
        else{
            cout<<a[i]<<" is not palindrome\n\n";
        }
    c=0;
    }
}