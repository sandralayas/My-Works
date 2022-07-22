/* Java programs to display alternate prime numbers */

import java.util.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Main{

	public static int[] Add(int list[],int count,int number){
		int temp[]=new int[count+1];
		for(int i=0;i<count;i++){
			temp[i]=list[i];
		}
		temp[count]=number;
		return temp;
	}

	public static void Prime_numbers(int number){
		int count=0,prime=2;
		int isprime=1;
		
		while(count!=number){
			if(prime==2){
				System.out.println(prime);prime++;count++;
			}else if(prime==3){
				System.out.println(prime);prime++;count++;
			}else{				
				for(int i=2;i<(prime/2);i++){
					
					if(prime%i==0)isprime=0;break;
				}
				if(isprime==1){
					System.out.println(prime);prime++;count++;
				}else if(isprime==0){
					isprime=1;prime++;
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner get=new Scanner(System.in);
		
		int choice;
		
		do{
			
			System.out.println("\n Enter 0 to exit the program");
			System.out.println(" Enter 1 to print alternative prime numbers");
			
			System.out.print(" Enter the choice : ");
			choice=get.nextInt();
			int count=0;
			
			if(choice==0)break;
			else if(choice==1){
				System.out.print(" Enter the number of primes needed : ");
				count=get.nextInt();
				Prime_numbers(count);
			}
			
		}while(choice!=0);
		System.out.println();
	}	
}





