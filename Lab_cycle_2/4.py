'''Write a program to create a class Box with data members length,
breadth, height, area, and volume. Provider constructor that enables
initialization with one parameter (for cube), two parameters (for
square prism) three parameters (rectangular prism). Also, provide
functions to calculate area and volume.
Create a list of N boxes with random measurements and print the
details of the box with maximum volume: area ratio.'''

class Box:
    
    def __init__(box,side1):
        box.side1=side1
        
    def __init__(box,side1,height):
        box.side1=side1
        box.height=height

    def __init__(box,side1,side2,height):
        box.side1=side1
        box.side2=side2
        box.height=height

    def area(box):
        if box.side2!=None:
            return 2*(box.side2*box.height+\
                      box.side1*box.height+\
                      box.side2*box.side1)
        
        elif box.height!=None:return 2*box.side1*(2*box.height+box.side1)
        
        elif box.side1!=None:return 6*(box.side1*box.side1)

    def volume(box):
        if box.side2!=None:return box.side1*box.side2*box.height
        
        elif box.height!=None:return box.side1*box.height*box.side1
        
        elif box.side1!=None:return box.side1*box.side1*box.side1

def area_vol(box,the_list):

   while(True):
       what=len(the_list)
       if what==1:
           side1=the_list[0]
       elif what==2:
           side1=the_list[0]
           height=the_list[1]
       elif what==3:
           side1=the_list[0]
           side2=the_list[1]
           height=the_list[2]
       print('''
    0. Return to program
    1. Area
    2. Volume
    ''')
       choice=input('\n Enter your choice : ')
       if choice=='0':break
       elif choice=='1':print('\n The area is : ',box.area())
       elif choice=='2':print('\n The volume is : ',box.volume())
       else:print('\n Wrong opt \n')
        

while(True):

    print('''
    0. Exit program
    1. Cube
    2. Square prism
    3. Rectangular prism
    ''')
    choice=input('\n Enter your choice : ')
    if choice=='0':break
    elif choice=='1':
        side=float(input('\n Enter the side length of the cube : '))
        cube=Box(side,None,None)
        area_vol(cube,[side])

    elif choice=='2':
        side=float(input('\n Enter the side of square prism : '))
        height=float(input('\n Enter the height of the prism : '))
        sq_prism=Box(side,None,height)
        area_vol(sq_prism,[side,height])
        
    elif choice=='3':
        length=float(input('\n Enter the length of rectangle prism : '))
        breadth=float(input('\n Enter the breadth of the prism : '))
        height=float(input('\n Enter the height of the prism : '))
        rec_prism=Box(length,breadth,height)
        area_vol(rec_prism,[length,breadth,height])
    else:print('\n Wrong opt \n')
