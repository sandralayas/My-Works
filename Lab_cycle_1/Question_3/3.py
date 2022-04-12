# Question 3 ; payslip

def read_details():# Reads the details of the employees
  a=(input('Enter the employee name : '))
  b=int(input('Enter the code : '))
  c=float(input('Enter the basic pay : '))
  return a,b,c

def gross_salary(salary):
  if salary<10000:return salary*(1+0.05+0.025)+500 # salary<10000
  elif salary>10000 and salary<30000:return salary*(1+0.075+0.05)+2500 # salary<30000
  elif salary>30000 and salary<50000:return salary*(1+0.11+0.075)+5000 # salary<50000
  else:return salary*(1+0.25+0.11)+7000 # Others

def deduction(salary):
  if salary<10000:return salary*0.08+20 # salary<10000
  elif salary>10000 and salary<30000:return salary*0.08+60 # salary<30000
  elif salary>30000 and salary<50000:return salary*(0.11+0.11)+60 # salary<50000
  else:return salary*(0.12+0.2)+60 # Others

name,code,salary=read_details()
print('\nGross_salary : ',gross_salary(salary))
print('\nDeduction : ',deduction(salary))
print('\nNet salary :',gross_salary(salary)-deduction(salary))
