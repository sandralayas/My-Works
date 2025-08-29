import numpy as np
from fractions import Fraction

print("\n				 Simplex Algorithm\n\n")


def inputArray(num):
  
  Array=[]
  print('\n Enter the numbers : ')
  for i in range(num):
    Array.append(int(input(' ')))
  return Array

constraints=[]
no_constraints=int(input('\n Enter the number of constraints : '))
no_coefficients=int(input('\n Enter the number of coefficients : '))
for i in range(no_constraints):
  print('\n Enter the constraint number '+str(i+1))
  constraints.append(inputArray(no_coefficients))
A = np.array(constraints)

print('\n Enter the resources available')
resources=inputArray(no_constraints)
b = np.array(resources)		

print('\n Enter the objective function')
objective_funtion=inputArray(no_coefficients)
c = np.array(objective_funtion)			
'''

# inputs
 
# A will contain the coefficients of the constraints
A = np.array([[1, 1, 0, 1], [2, 1, 1, 0]])
# b will contain the amount of resources
b = np.array([8, 10])          
# c will contain coefficients of objective function Z     
c = np.array([1, 1, 0, 0])
'''


cb = np.array(c[3])
B = np.array([[3], [2]])		

cb = np.vstack((cb, c[2]))	
xb = np.transpose([b])				

table = np.hstack((B, cb))			
table = np.hstack((table, xb))		

table = np.hstack((table, A))		

table = np.array(table, dtype ='float')

MIN = 0

print("\n Table at iteration = 0")
print(" B \tCB \tXB \ty1 \ty2 \ty3 \ty4")
for row in table:
	for el in row:
		print('',Fraction(str(el)).limit_denominator(100), end ='\t')
	print()
print()


reached = 0	
itr = 1
unbounded = 0
alternate = 0

while reached == 0:

	print("\n Iteration : ", end =' ')
	print(itr)
	print(" B \tCB \tXB \ty1 \ty2 \ty3 \ty4")
	for row in table:
		for el in row:
			print('',Fraction(str(el)).limit_denominator(100), end ='\t')
		print()

	i = 0
	rel_prof = []
	while i<len(A[0]):
		rel_prof.append(c[i] - np.sum(table[:, 1]*table[:, 3 + i]))
		i = i + 1

	print("\n Relative profit: ", end =" ")
	for profit in rel_prof:
		print('',Fraction(str(profit)).limit_denominator(100), end =", ")
	print()
	i = 0
	
	b_var = table[:, 0]

	while i<len(A[0]):
		j = 0
		present = 0
		while j<len(b_var):
			if int(b_var[j]) == i:
				present = 1
				break;
			j+= 1
		if present == 0:
			if rel_prof[i] == 0:
				alternate = 1
				print("\n Case of Alternate found")

		i+= 1
	print()
	flag = 0
	for profit in rel_prof:
		if profit>0:
			flag = 1
			break
		# if all relative profits <= 0
	if flag == 0:
		print("\n All profits are <= 0, optimality reached")
		reached = 1
		break

	# kth var will enter the basis
	k = rel_prof.index(max(rel_prof))
	min = 99999
	i = 0;
	r = -1
	# min ratio test (only positive values)
	while i<len(table):
		if (table[:, 2][i]>0 and table[:, 3 + k][i]>0):
			val = table[:, 2][i]/table[:, 3 + k][i]
			if val<min:
				min = val
				r = i	 # leaving variable
		i+= 1

		# if no min ratio test was performed
	if r ==-1:
		unbounded = 1
		print("\n Case of Unbounded")
		break

	print("\n Pivot element index:", end =' ')
	print('',np.array([r, 3 + k]))

	pivot = table[r][3 + k]
	print("\n Pivot element: ", end =" ")
	print('',Fraction(pivot).limit_denominator(100))
		
		# perform row operations
	# divide the pivot row with the pivot element
	table[r, 2:len(table[0])] = table[
			r, 2:len(table[0])] / pivot
			
	# do row operation on other rows
	i = 0
	while i<len(table):
		if i != r:
			table[i, 2:len(table[0])] = table[i,\
				2:len(table[0])] - table[i][3 + k] *\
				table[r, 2:len(table[0])]
		i += 1

	
	# assign the new basic variable
	table[r][0] = k
	table[r][1] = c[k]
	
	print()
	print()
	itr+= 1
	

print()

print("***************************************************************")
if unbounded == 1:
	print("\n UNBOUNDED LPP")
	exit()
if alternate == 1:
	print("\n ALTERNATE Solution")

print("\n Optimal table:")
print(" B \tCB \tXB \ty1 \ty2 \ty3 \ty4")
for row in table:
	for el in row:
		print('',Fraction(str(el)).limit_denominator(100), end ='\t')
	print()
print()
print("\n Value of Z at optimality: ", end =" ")

basis = []
i = 0
sum = 0
while i<len(table):
	sum += c[int(table[i][0])]*table[i][2]
	temp = "x"+str(int(table[i][0])+1)
	basis.append(temp)
	i+= 1
# if MIN problem make z negative
if MIN == 1:
	print('',-Fraction(str(sum)).limit_denominator(100))
else:
	print('',Fraction(str(sum)).limit_denominator(100))
print("\n Final Basis: ", end =" ")
print('',basis)

print("\n Simplex Finished")
print()
