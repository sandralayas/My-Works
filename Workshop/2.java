import javax.swing.*;
import java.awt.event.*;

class Main{
	public static void main(String args[]){
		MyFrame f=new MyFrame();
	}
}

class MyFrame implements ActionListener{

//Class menbers
	//Attributes
	JFrame f;				//containers
	JLabel l1,l2,l3,l4;			//components
	JPanel p;
	JButton b1,b2;
	JTextField tf;
	JPasswordField pf;
	
	
	//Functions
	MyFrame(){
		f=new JFrame("My Window");
		l1=new JLabel("Username : ");l2=new JLabel("Password : ");l3=new JLabel("Login");l4=new JLabel("Cancel");
		p=new JPanel();
		b1=new JButton("");b2=new JButton("");
		tf=new JTextField();
		pf=new JPasswordField();
		
		f.setSize(200,200);
		p.setLayout(null);
		l1.setBounds(20,20,100,20);l2.setBounds(20,40,100,20);l3.setBounds(20,60,100,20);l4.setBounds(120,60,100,20);
		b1.setBounds(80,60,30,20);b2.setBounds(170,60,30,20);
		tf.setBounds(110,20,100,20);
		pf.setBounds(110,40,100,20);
		
		b1.addActionListener(this);b2.addActionListener(this);
		
		f.add(p);
		p.add(l1);p.add(l2);p.add(l3);p.add(l4);
		p.add(b1);p.add(b2);
		p.add(tf);
		p.add(pf);
		
		f.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==b1){
			String A,B;
			A=tf.getText();
			B=new String (pf.getPassword());
			
			if(A.equals("abcd")&&B.equals("123")){
				JOptionPane.showMessageDialog(null,"You clicked B1","Window",1);
			}
			else{
				JOptionPane.showMessageDialog(null,"Not logged in","Window",3);
			}
			
		}
		
		else if(e.getSource()==b2){
			System.exit(0);
		}
	}
}
