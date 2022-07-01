import java.util.*;
class Main{
	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
	        System.out.print("Enter the length : ");
	        int l = sc.nextInt();
	        System.out.print("Enter the breadth : ");
	        int b=sc.nextInt();
	        int a=l*b;
	        System.out.print("Area of rectangle :  "); 
	        System.out.println(a); 
	        System.out.print("Enter the sidelength : ");
	        int s = sc.nextInt();
	        int area=s*s;
	        System.out.print("Area of square :  "); 
	        System.out.println(area); 
	        System.out.print("Enter the radius : ");
	        int radius=sc.nextInt();
	        double area_cir=3.14*radius*radius;
	        System.out.print("Area of circle :  "); 
	        System.out.print(area_cir); 
	
	}

}
