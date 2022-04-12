''' Question 4 ; Happy number'''

def isHappy(num):# Function that checks if the number is happy or not
  count=100
  while count!=0:
    count-=1
    sum=0
    for i in range(num):
      a=num%10
      sum+=a*a
      num=num//10
    if sum==1:
      return True
    num=sum
  else:return False

def happy_or_sad():
  num=int(input('Enter the number : '))# Prints happy or sad
  if isHappy(num):print(num,' is a happy number')
  else:print(num,' is a sad number')

def happy_range():# Prints all the happy numbers between the given range
  lower=int(input('\nEnter the lower limit : '))
  upper=int(input('Enter the upper limit : '))
  for i in range(lower,upper+1):
    if isHappy(i):print(i,end=' ')

def many_happy():# Prints "count" number of happy numbers
  count=int(input('\n\nEnter how many numbers needed : '))
  num=1
  while count!=0:
    if isHappy(num):
      count-=1
      print(num,end=' ')
    num+=1

happy_or_sad()
happy_range()
many_happy()
