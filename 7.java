/* write a program to create a 'Student' class

1 roll no
2 name
3 sub1
4 sub2
5 sub3
6 total marks */

import java.util.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Main{

	public class Student{
		private int roll_no,mark1,mark2,mark3;
		private String name;
		/*
		public Student(){
			set_roll(0);
			set_name("z");
			set_marks(0,0,0);
		}
		
		public Student(int roll_no,String name,int mark1,int mark2,int mark3){
			set_roll(roll_no);
			set_name(name);
			set_marks(mark1,mark2,mark3);
		}
		*/
		public void set_roll(int roll_no){
			this.roll_no=roll_no;
		}
		public int get_roll(){
			return roll_no;
		}
	
		public void set_name(String name){
			this.name=name;
		}
		public String get_name(){
			return name;
		}
	
		public void set_marks(int mark1,int mark2,int mark3){
			this.mark1=mark1;
			this.mark2=mark2;
			this.mark3=mark3;
		}
		public void get_marks(){
			System.out.println(mark1);
			System.out.println(mark2);
			System.out.println(mark3);
		}
	
		public int total(){
			if(mark1<50){
				return 0;
			}
			else if(mark2<50){
				return 0;
			}
			else if(mark3<50){
				return 0;
			}
			return mark1+mark2+mark3;
		}
	}


	public static Student[] Add(Student list[],int count,Student student){
		Student temp[]=new Student[count+1];
		for(int i=0;i<count;i++){
			temp[i]=list[i];
		}
		temp[count]=student;
		return temp;
	}
	
	private static void Read_details(Student list[],int count){
		Scanner get=new Scanner(System.in);
		
		Student student;
		
		System.out.println(" Enter the student's roll number : ");
		int roll=get.nextInt();
		
		System.out.println(" Enter the student's name : ");
		String name=get.nextLine();
		
		System.out.println(" Enter the marks for 1st subject : ");
		int mark1=get.nextInt();
		
		System.out.println(" Enter the marks for 2nd subject : ");
		int mark2=get.nextInt();
		
		System.out.println(" Enter the marks for 3rd subject : ");
		int mark3=get.nextInt();
		
		//Student student=new Student();
		student.set_roll(roll);
		student.set_name(name);
		student.set_marks(mark1,mark2,mark3);
		list=Add(list,count,student);
	}

	public static void main(String[] args) {
		Scanner get=new Scanner(System.in);
		
		int choice;
		
		do{
			
			System.out.println(" Enter 0 to exit the program");
			System.out.println(" Enter 1 to add a student to the list");
			System.out.println(" Enter 2 to display the details of the student");
			System.out.println(" Enter 3 to calculate the total marks of a student");
			
			System.out.println(" Enter the choice : ");
			choice=get.nextInt();
			
			//List<Student> list = new ArrayList<>(Arrays.asList());
			Student list[];
			int count=0;
			
			if(choice==0)break;
			else if(choice==1){
				Read_details(list,count);
				count++;
			}
			else if(choice==2){
				System.out.println(" Enter the student's roll number : ");
				int roll=get.nextInt();
				
				for(int i=0;i<count;i++){
					if(list[i].get_roll()==roll){
						System.out.println(list[i].get_roll());
						System.out.println(list[i].get_name());
						list[i].get_marks();
					}
				}
			}
			else if(choice==2){
				System.out.println(" Enter the student's roll number : ");
				int roll=get.nextInt();
				
				for(int i=0;i<count;i++){
					if(list[i].get_roll()==roll){
						System.out.print("\n The total marks is : ");
						System.out.println(list[i].total());
					}
				}
			}
		}while(choice!=0);
		System.out.println();
	}	
}



