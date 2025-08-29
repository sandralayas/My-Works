def func(x,degree1,coff1):
	answer=0
	for i in range(degree1+1):
		answer+=coff1[i]*(x)**i
	return answer

def derivFunc(x,degree2,coff2):
	answer=0
	for i in range(degree2+1):
		answer+=coff2[i]*(x)**i
	return answer

def newtonRaphson(x,degree1,coff1,degree2,coff2):
	h = func(x,degree1,coff1) / derivFunc(x,degree2,coff2)
	while abs(h) >= 0.0001:
		h = func(x,degree1,coff1)/derivFunc(x,degree2,coff2)
		
		# x(i+1) = x(i) - f(x) / f'(x)
		x = x - h
	
	print("The value of the root is : ",
							"%.4f"% x)

degree1=int(input('Enter the degree of the funtion: '))
coff1=[]
for i in range(0,degree1+1):
    value=float(input('Enter the coefficient of x'+str(i)+': '))
    coff1.append(value)

degree2=int(input('Enter the degree of the funtion: '))
coff2=[]
for j in range(0,degree2+1):
    value=float(input('Enter the coefficient of x'+str(j)+': '))
    coff2.append(value)

x0=int(input('Enter the value for Newton Raphson Method: '))

print(coff1,coff2)
newtonRaphson(x0,degree1,coff1,degree2,coff2)