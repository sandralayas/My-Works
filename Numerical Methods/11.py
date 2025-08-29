def func(x,degree,coff):
	answer=0
	for i in range(degree+1):
		answer+=coff[i]*(x)**i
	return answer
def trapezoidal (a, b, n,degree,coff):
	h = (b - a) / n
	s = (func(a,degree,coff) + func(b,degree,coff))
	i = 1
	while i < n:
		s += 2 * func((a + i * h),degree,coff)
		i += 1
	return ((h / 2) * s)

degree=int(input('Enter the degree of the funtion: '))
coff=[]
for i in range(0,degree+1):
    value=float(input('Enter the coefficient of x'+str(i)+': '))
    coff.append(value)
coff=coff[::-1]
x0=int(input('Enter the upper limit: '))
xn=int(input('Enter the lower limit: '))
n=int(input('Enter the intervals: '))

print ("Value of integral is ",
	"%.4f"%trapezoidal(x0, xn, n,degree,coff))
