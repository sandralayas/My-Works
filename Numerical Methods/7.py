def u_cal(u, n):

	temp = u 
	for i in range(1, n):
		temp = temp * (u - i) 
	return temp 

def fact(n):
	f = 1 
	for i in range(2, n + 1):
		f *= i 
	return f 

n=int(input('Enter the number of (x,y) values: '))
x=[]
for i in range(n):
	x.append(float(input('Enter the value of x'+str(i)+'(0): ')))

y = [[0 for i in range(n)]
		for j in range(n)]
print()
for i in range(n):
	y[i][0]=(float(input('Enter the value of y'+str(i)+'(0): ')))

for i in range(1, n):
	for j in range(n - i):
		y[j][i] = y[j + 1][i - 1] - y[j][i - 1] 

for i in range(n):
	print(x[i], end = "\t") 
	for j in range(n - i):
		print(y[i][j], end = "\t") 
	print("") 

value=float(input('Enter the input value fo Newton Forward And Backward Interpolation: '))

sum = y[0][0] 
u = (value - x[0]) / (x[1] - x[0]) 
for i in range(1,n):
	sum = sum + (u_cal(u, i) * y[0][i]) / fact(i) 

print("\nValue at", value,
	"is", round(sum, 6)) 