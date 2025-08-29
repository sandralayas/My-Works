
m=[\
[1,0,0],\
[1,1,0],\
[1,1,1]\
]

def print_matrix(m):
	print()
	for i in m:
		for j in i:
			print('',round(j,3),end=' ')
		print('\n')
	print()

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
	
def norm(v):
	summ=0
	for i in v:
		summ+=i**2
	return summ**0.5

def transpose(m):
	trans=[]
	for i in range(len(m)):
		trans.append(column(m,i))
	return trans

def scale(u,v):
	summ=0
	for i in range(len(u)):
		summ+=(v[i]*u[i])
	return round(summ,3)

def R(m,Q):
	r=[]
	for i in range(1,len(m)+1):
		qi=column(Q,i)
		row=[]
		for j in range(i,len(m)+1):
			uj=column(m,j)
			row.append(scale(uj,qi))
		r.append(row)	
	
	for i in range(1,len(m)+1):
		for j in range(1,i):
			r[i-1]=[0]+r[i-1]
	return r

def Q(m):
	temp=[]
	for i in range(len(m[0])):
		ni=norm(column(m,i+1))
		row=[]
		for j in (column(m,i+1)):
			row.append(j/ni)
		temp.append(row)
	x=transpose(temp)
	x.append(x.pop(0))
	return x

print_matrix(m)

m=Gram_schmidt_process(m)
print_matrix(m)	
Q=Q(m)
print_matrix(Q)

m=[\
[1,0,0],\
[1,1,0],\
[1,1,1]\
]


R=R(m,Q)
print_matrix(R)

	
