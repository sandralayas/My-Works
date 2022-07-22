import java.util.Scanner;

class Addition {
    public static void main(String[] args) {    //input is string
        
        int variable1,variable2,sum;            //random variables
        
        Scanner input=new Scanner(System.in);
        
        System.out.print("\n Enter the first variable : ");
        variable1=input.nextInt();
        
        System.out.print("\n Enter the second variable : ");
        variable2=input.nextInt();
        
        sum=variable1+variable2;
        System.out.print("\n The sum is : ");
        System.out.println(sum);                //print the sum
    }
}
