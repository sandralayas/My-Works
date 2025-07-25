/* Program to find the 3rd largest number in a given set of numbers */

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

	public static void Greatest(int list[],int count){
		int greatest=list[0],greater=list[0],great=list[0];
		int index=1;
		
		while(index!=count){
			if(list[index]>=greatest){
				great=greater;
				greater=greatest;
				greatest=list[index];
				index++;
			}else if(list[index]>=greater){
				great=greater;
				greater=list[index];
				index++;
			}else if(list[index]>=great){
				great=list[index];
				index++;
			}
		}
		System.out.print("\n The 1st greastest : ");
		System.out.println(greatest);
		System.out.print(" The 2nd greastest : ");
		System.out.println(greater);
		System.out.print(" The 3rd greastest : ");
		System.out.println(great);
	}

	public static void main(String[] args) {
		Scanner get=new Scanner(System.in);
		
		int choice;
		
		System.out.print("\n Enter the number of elments : ");
		int length=get.nextInt();
		int Array[]=new int[length];
		int count=0,number;
		System.out.print("\n Enter the numbers : ");
		while(count!=length){
			number=get.nextInt();
			Array[count]=number;
			count++;
		}
		
		do{
			
			System.out.println("\n Enter 0 to exit the program");
			System.out.println(" Enter 1 input another array");
			System.out.println(" Enter 2 display the 3rd greatest number");
			
			System.out.print("\n Enter the choice : ");
			choice=get.nextInt();
			
			if(choice==0)break;
			else if(choice==1){
				System.out.print("\n Enter the number of elments : ");
				length=get.nextInt();
				Array=new int[length];
				count=0;
				
				System.out.print("\n Enter the numbers : ");
				while(count!=length){
					number=get.nextInt();
					Array[count]=number;
					count++;
				}
			}else if(choice==2){
				Greatest(Array,length);
			}
			
		}while(choice!=0);
		System.out.println();
	}	
}





