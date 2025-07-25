import java.util.Scanner;

class Even_Odd {
    public static void main(String[] args) {
        
        int user_input;

        Scanner input=new Scanner(System.in);
        
        System.out.print("\n Enter the number to check : ");
        user_input=input.nextInt();
        
		if(user_input%2==0)System.out.print("\n The number is even");
		else System.out.print("\n The number is odd");

		System.out.println("\n");
    }
}
