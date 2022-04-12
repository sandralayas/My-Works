# Question one ; Four digit number

number=input(' Enter the four digit number : ')


sum=int(number[0])+int(number[1])+int(number[2])+int(number[3])# Summing up the digits

print('\n Sum of the digits           :',number[0],'+',number[1],'+',number[2],'+',number[3],'=',sum)
print('\n Reversed number             :',number[::-1])# Prints the reversed number

Opro=int(number[0])*int(number[2])# Product of the odd position
Epro=int(number[1])*int(number[3])# Product of the even position

print('\n The diffrence of products   :',number[0],'*',number[2],'-',number[1],'*',number[3],'=',Opro-Epro)# Prints the diffrence of products
