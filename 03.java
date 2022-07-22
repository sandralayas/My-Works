import java.util.Scanner;

class Reverse {
    public static void main(String[] args) {    	//input is string
        
        int user_input,copy;            		//random variables

        Scanner input=new Scanner(System.in);
        
        System.out.print("\n Enter the number to reverse : ");
        user_input=input.nextInt();
        
		copy=user_input;
		System.out.print("\n The reversed number is : ");

		while(copy!=0){
			System.out.print(copy%10);
			copy=copy/10;
		}
		System.out.println("\n");
    }
}
