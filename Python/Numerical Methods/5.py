def seidel(a, x ,b):
	n = len(a)
	for j in range(0, n):
		d = b[j]				
		for i in range(0, n):	
			if(j != i):
				d-=a[j][i] * x[i]	
		x[j] = d / a[j][j]	
	return x	
			
n = int(input('Enter number of rows of the matrix: '))							
a = []							
b = []
x=[]
for i in range(n):			
    x.append(0)						
a = []

for i in range(n):
    values=(input()).split()
    row=[]
    for i in values:
        row.append(float(i))
	
    a.append(row)

values=(input('Enter the matrix B')).split()
b=[]
for i in values:
    b.append(float(i))

for i in range(0, 25):			
	x = seidel(a, x, b)
	print(x)					

