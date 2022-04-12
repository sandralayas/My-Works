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
  print('\n Checks whether a number is happy or not\n')
  num=int(input(' Enter the number : '))# Prints happy or sad
  if isHappy(num):print('',num,' is a happy number')
  else:print('',num,' is a sad number')

def happy_range():# Prints all the happy numbers between the given range
  print('\n Prints all the happy numbers between the range\n')
  lower=int(input(' Enter the lower limit : '))
  upper=int(input(' Enter the upper limit : '))
  for i in range(lower,upper+1):
    if isHappy(i):print('',i,end=' ')

def many_happy():# Prints "count" number of happy numbers
  print('\n\n Prints these many happy numbers\n')
  count=int(input(' Enter how many numbers needed : '))
  num=1
  while count!=0:
    if isHappy(num):
      count-=1
      print('',num,end=' ')
    num+=1
  print('\n')

happy_or_sad()
happy_range()
many_happy()

