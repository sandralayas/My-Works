MAX_ITER = 1000000

def func(x,degree,coff):
	answer=0
	for i in range(degree+1):
		answer+=coff[i]*(x)**i
	return answer

def regulaFalsi(a,b,degree,coff):
	if func(a,degree,coff) * func(b,degree,coff) >= 0:
		print("You have not assumed right a and b")
		return -1
	
	c = a
	
	for i in range(MAX_ITER):
		c = (a * func(b,degree,coff) - b * func(a,degree,coff))/ (func(b,degree,coff) - func(a,degree,coff))

		if func(c,degree,coff) == 0:
			break

		elif func(c,degree,coff) * func(a,degree,coff) < 0:
			b = c
		else:
			a = c
	print("The value of root is : " , '%.4f' %c)
	
degree=int(input('Enter the degree of the funtion: '))
coff=[]
for i in range(0,degree+1):
    value=float(input('Enter the coefficient of x'+str(i)+': '))
    coff.append(value)
coff=coff[::-1]
a=int(input('Enter the 1st value for False Position Method: '))
b=int(input('Enter the 2nd value for False Position Method: '))
regulaFalsi(a, b,degree,coff)