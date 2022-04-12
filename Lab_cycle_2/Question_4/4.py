'''Write a program to create a class Box with data members length,
breadth, height, area, and volume. Provider constructor that enables
initialization with one parameter (for cube), two parameters (for
square prism) three parameters (rectangular prism). Also, provide
functions to calculate area and volume.

Create a list of N boxes with random measurements and print the
details of the box with maximum volume: area ratio.'''

import random

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
	side1=the_list[0]
	if len(the_list)==2:side2=the_list[1]
	if len(the_list)==3:height=the_list[2]
	return box.area(),box.volume()
   

num=int(input('\n Enter the number of trials needed : '))
count=0
x=50  
ratios=[]

print('\n Length\t Breadth Height\t Area / Volume')
while(count!=num):
	count+=1
	
	length=random.randrange(1,x,1)
	breadth=random.randrange(1,x,1)
	height=random.randrange(1,x,1)	
	rec_prism=Box(length,breadth,height)
	area,vol=area_vol(rec_prism,[length,breadth,height])
	ratio=area/vol
	ratios.append([[length,breadth,height],ratio])
	print('\n',length,'\t',breadth,'\t',height,'\t',ratio)

def call_area(ratios):return ratios[1]
ratios.sort(key=call_area)

maximum=ratios.pop()
length=maximum[0][0]
breadth=maximum[0][1]
height=maximum[0][2]

ratio=maximum[1]
	
print('\n The box with the maximum ratio\n\n Length\t Breadth Height\t Area / Volume')
print('\n',length,'\t',breadth,'\t',height,'\t',ratio)




