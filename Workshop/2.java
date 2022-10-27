import javax.swing.*;
class Main{
	public static void main(String args[]){
		MyFrame f=new MyFrame();
	}
}

class MyFrame{
	JFrame f;
	JLabel l;
	MyFrame(){
		f=new JFrame("My Window");
		f.setSize(200,200);

		l=new JLabel("Message");
		//l.setSize(50,50);
		f.add(l);
		f.setVisible(true);
	}
}
