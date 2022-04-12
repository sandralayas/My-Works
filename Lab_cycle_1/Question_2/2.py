# Question 2 ; Area of a triangle

import math

def read_side():# Funtion to read the sides of the triangles
  a=int(input('Enter the first side : '))
  b=int(input('Enter the second side : '))
  c=int(input('Enter the third side : '))
  return a,b,c

def area(a,b,c):# Calculates the area of the triangle
  s=(a+b+c)//2
  return math.sqrt(s*(s-a)*(s-b)*(s-c))

print(' The first triangle :')# Reads and prints the 1st triangle
a,b,c=read_side()
t1=area(a,b,c)
print(t1,'\n')

print(' The second triangle :\n')# Reads and prints the 2st triangle
x,y,z=read_side()
t2=area(x,y,z)
print(t2,'\n')

print(' Total area = ',t1+t2)# Total area
print('\n Persentage of t1 = ',t1/(t1+t2)*100,'%')# % of 1st triangle
print('\n Persentage of t2 = ',t2/(t1+t2)*100,'%')# % of 2st triangle


