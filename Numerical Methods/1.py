def func(x,degree,coff):
	answer=0
	for i in range(degree+1):
		answer+=coff[i]*(x)**i
	return answer

def bisection(a,b,degree,coff):

	if (func(a,degree,coff) * func(b,degree,coff) >= 0):
		print("You have not assumed right a and b\n")
		return

	c = a
	while ((b-a) >= 0.01):

		# Find middle point
		c = (a+b)/2

		# Check if middle point is root
		if (func(c,degree,coff) == 0.0):
			break

		# Decide the side to repeat the steps
		if (func(c,degree,coff)*func(a,degree,coff) < 0):
			b = c
		else:
			a = c
			
	print("The value of root is : ","%.4f"%c)

degree=int(input('Enter the degree of the funtion: '))
coff=[]
for i in range(0,degree+1):
    value=float(input('Enter the coefficient of x'+str(i)+': '))
    coff.append(value)
coff=coff[::-1]
a=int(input('Enter the 1st value for Bisection Method: '))
b=int(input('Enter the 2nd value for Bisection Method: '))
bisection(a, b,degree,coff)