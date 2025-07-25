
import java.util.*;

class Main{
	public static void main(String args[]){
		try{
			Scanner get=new Scanner(System.in);
			System.out.print("\n Numerator : ");
			int A=get.nextInt();
			System.out.print(" Denominator : ");
			int B=get.nextInt();
			
			System.out.print("\n Quotient : "+(A/B)+"\n");
			//System.out.print;
		}catch(Exception X){
			System.out.println("\n Exception occured!!"+"\n "+X);
		}
	}
}
