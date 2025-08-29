# Python code for simpson's 1 / 3 rule
import math

# Function to calculate f(x)
def func(x,degree,coff):
	answer=0
	for i in range(degree+1):
		answer+=coff[i]*(x)**i
	return answer

# Function for approximate integral
def simpsons_( ll, ul, n ):

	# Calculating the value of h
	h = ( ul - ll )/n

	# List for storing value of x and f(x)
	x = list()
	fx = list()
	
	# Calculating values of x and f(x)
	i = 0
	while i<= n:
		x.append(ll + i * h)
		fx.append(func(x[i],degree,coff))
		i += 1

	# Calculating result
	res = 0
	i = 0
	while i<= n:
		if i == 0 or i == n:
			res+= fx[i]
		elif i % 2 != 0:
			res+= 4 * fx[i]
		else:
			res+= 2 * fx[i]
		i+= 1
	res = res * (h / 3)
	print("%.6f"% res)

degree=int(input('Enter the degree of the funtion: '))
coff=[]
for i in range(0,degree+1):
    value=float(input('Enter the coefficient of x'+str(i)+': '))
    coff.append(value)
coff=coff[::-1]

lower_limit = int(input('Enter the lower limit: '))# 4 # Lower limit
upper_limit = int(input('Enter the upper limit: '))#5.2 # Upper limit
n = int(input('Enter the intervals: '))#6 # Number of interval
simpsons_(lower_limit, upper_limit, n)