def func(x,degree,coff):
	answer=0
	for i in range(degree+1):
		answer+=coff[i]*(x)**i
	return answer

def calculate(lower_limit, upper_limit, interval_limit ):
	
	interval_size = (float(upper_limit - lower_limit) / interval_limit)
	sum = func(lower_limit,degree,coff) + func(upper_limit,degree,coff);

	for i in range(1, interval_limit ):
		if (i % 3 == 0):
			sum = sum + 2 * func((lower_limit + i * interval_size),degree,coff)
		else:
			sum = sum + 3 * func((lower_limit + i * interval_size),degree,coff)
	
	return ((float( 3 * interval_size) / 8 ) * sum )

degree=int(input('Enter the degree of the funtion: '))
coff=[]
for i in range(0,degree+1):
    value=float(input('Enter the coefficient of x'+str(i)+': '))
    coff.append(value)
coff=coff[::-1]

lower_limit = int(input('Enter the lower limit: '))
upper_limit = int(input('Enter the upper limit: '))
interval_limit = int(input('Enter the intervals: '))
integral_res = calculate(lower_limit, upper_limit, interval_limit)
print (round(integral_res, 6))
