'''Write a program to create a parent class, 3DShapes, with methods
printVolume() and printArea(), which prints the Volume and Area,
respectively. Create classes Cylinder and Sphere by inheriting
3DShapes class. Using these child classes, calculate and print the
volume and area of a cylinder and sphere.'''

class _3DShapes:
    
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
            print('\n The area is : ', 2*(box.side2*box.height+\
                      box.side1*box.height+\
                      box.side2*box.side1))
        
        elif box.height!=None:print('\n The area is : ', 2*box.side1*(2*box.height+box.side1))
        
        elif box.side1!=None:print('\n The area is : ', 6*(box.side1*box.side1))

    def volume(box):
        if box.side2!=None:print('\n The volume is : ', box.side1*box.side2*box.height)
        
        elif box.height!=None:print('\n The volume is : ', box.side1*box.height*box.side1)
        
        elif box.side1!=None:print('\n The volume is : ', box.side1*box.side1*box.side1)

def area_vol(box,the_list):

   while(True):
       side1=the_list[0]
       side2=the_list[1]
       height=the_list[2]
       if len(the_list)==4:radius=the_list[3]
       print('''
    0. Return to program
    1. Area
    2. Volume
    ''')
       choice=input('\n Enter your choice : ')
       if choice=='0':break
       elif choice=='1':box.area()
       elif choice=='2':box.volume()
       else:print('\n Wrong opt \n')

class _Cylinder(_3DShapes):
    
    def __init__(box,side1,side2,height,radius):
        box.radius=radius
        _3DShapes.__init__(box,side1,side2,height)
        
    def area(box):
        print('\n The area is : ', 2*(3.14159265359)*box.radius*box.height+\
                2*(3.14159265359)*box.radius*box.radius)

    def volume(box):
        print('\n The volume is : ', (3.14159265359)*box.radius*box.radius*box.height)
                
class _Sphere(_3DShapes):
    
    def __init__(box,side1,side2,height,radius):
        box.radius=radius
        _3DShapes.__init__(box,side1,side2,height)
        
    def area(box):
        if box.radius!=None:
            print('\n The area is : ', 4*(3.14159265359)*box.radius*box.radius)
                
    def volume(box):
        print('\n The volume is : ', (4/3)*(3.14159265359)*box.radius*box.radius*box.radius)

while(True):

    print('''
    0. Exit program
    1. Cube
    2. Square prism
    3. Rectangular prism
    4. Cylinder
    5. Sphere
    ''')
    choice=input('\n Enter your choice : ')
    if choice=='0':break
    elif choice=='1':
        side=float(input('\n Enter the side length of the cube : '))
        cube=_3DShapes(side,None,None)
        area_vol(cube,[side,None,None,None])

    elif choice=='2':
        side=float(input('\n Enter the side of square prism : '))
        height=float(input('\n Enter the height of the prism : '))
        sq_prism=_3DShapes(side,None,height)
        area_vol(sq_prism,[side,None,height,None])
        
    elif choice=='3':
        length=float(input('\n Enter the length of rectangle prism : '))
        breadth=float(input('\n Enter the breadth of the prism : '))
        height=float(input('\n Enter the height of the prism : '))
        rec_prism=_3DShapes(length,breadth,height)
        area_vol(rec_prism,[length,breadth,height,None])

    elif choice=='4':
        radius=float(input('\n Enter the radius of the cylinder : '))
        height=float(input('\n Enter the height of the cylinder : '))
        cylinder=_Cylinder(None,None,height,radius)
        area_vol(cylinder,[None,None,height,radius])

    elif choice=='5':
        radius=float(input('\n Enter the radius of the sphere : '))
        sphere=_Sphere(None,None,None,radius)
        area_vol(sphere,[None,None,None,radius])
    else:print('\n Wrong opt \n')
