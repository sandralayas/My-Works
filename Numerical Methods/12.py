def func( x, y ):
	return (x + y + x * y)

def euler( x0, y, h, x ):
	temp = -0

	while x0 < x:
		temp = y
		y = y + h * func(x0, y)
		x0 = x0 + h

	print("Approximate solution at x = ", x, " is ", "%.6f"% y)


x0 = float(input('Enter the x0 value for Eulers Method: '))
y0 = float(input('Enter the y0 value for Eulers Method: '))
h = float(input('Enter the h value for Eulers Method: '))
x = float(input('Enter the x value for Eulers Method: '))

euler(x0, y0, h, x)
