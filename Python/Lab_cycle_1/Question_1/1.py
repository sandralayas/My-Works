# Question one ; Four digit number

number=input(' Enter the four digit number : ')

not_four=True

while not_four:
	if len(number)==4:
		if number.isalpha():
			print('\n Error\n')
			number=input(' Enter the four digit number : ')
		else:not_four=False
			
	else:
		print('\n Error\n')
		number=input(' Enter the four digit number : ')

def summing():
	sum=int(number[0])+int(number[1])+int(number[2])+\
		int(number[3])# Summing up the digits

	print('\n Sum of the digits           :',number[0],\
	'+',number[1],'+',number[2],'+',number[3],'=',sum)

def reverse():
	print('\n Reversed number             :',number[::-1])
		# Prints the reversed number

def even_odd():
	Opro=int(number[0])*int(number[2])# Product of the odd position
	Epro=int(number[1])*int(number[3])# Product of the even position
	print('\n The diffrence of products   :',number[0],'*',\
		number[2],'-',number[1],'*',number[3],'=',Opro-Epro)
		# Prints the diffrence of products

summing()
reverse()
even_odd()
