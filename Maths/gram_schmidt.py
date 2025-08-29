'''m=[\
[1,0,0],\
[1,1,0],\
[1,1,1]\
]

for i in m:print(i,'\n')
print()
'''

def column(m,n):
	column=[]
	for i in m:
		column.append(i[n-1])
	return column

def replace(m,n,column):
	count=0
	for i in m:
		i[n-1]=column[count]
		count+=1

def projection(v,u):
	proj=[]
	num=den=0
	for i in range(len(u)):
		num+=(v[i]*u[i])
		den+=(v[i]*v[i])
	for i in v:
		proj.append((num/den)*i)
	return proj

def addition(v,u):
	summ=[]
	for i in range(len(u)):
		summ.append(v[i]+u[i])
	return summ

def substraction(v,u):
	left=[]
	for i in range(len(u)):
		left.append(v[i]-u[i])
	return left

def Gram_schmidt_process(m):
	_m=m
	n=len(m)
	for i in range(2,n+1):
		ui=column(_m,i)
		ans=[0,0,0]
		for j in range(1,i):
			vj=column(_m,j)
			ans=addition(ans,projection(vj,ui))
		vi=substraction(ui,ans)
		replace(_m,i,vi)
	return _m

def print_matrix(m):
	print()
	for i in m:
		for j in i:
			print('',round(j,3),end=' ')
		print('\n')
	print()

def read_matrix():
	matrix=[]
	row=int(input('\n Enter the row size : '))
	col=int(input('\n Enter the column size : '))
	print('\n Enter the matrix :\n')
	for i in range(row):
		row=[]
		entry=input(' ')
		for j in entry.split():
			row.append(int(j))
		matrix.append(row)
	return matrix
	
m=read_matrix()
_m=Gram_schmidt_process(m)

print('\n MATRIX : ')
print_matrix(m)

print('\n GRAM SCHMIDT PROCESS : ')
print_matrix(_m)

