m=[\
[1,-1,2],\
[4,0,6],\
[0,1,-1]\
]

def print_matrix(m):
	print()
	for i in m:
		for j in i:
			print('',round(j,3),end=' ')
		print('\n')
	print()

def remove(m,p,q):
	matrix=[]
	count=0
	for i in m:
		if count!=p:
			row=[]
			for j in range(len(i)):
				if j!=q:
					row.append(i[j])
			matrix.append(row)
		count+=1
	return matrix

def detrminant(m):
	if len(m[0])==1:return m[0][0]
	if len(m[0])==2:
		return m[0][0]*m[1][1]-m[0][1]*m[1][0]
	else:
		ans=0
		count=0
		for i in m[0]:
			if count%2==0:
				ans+=i*detrminant(remove(m,0,count))
			else:
				ans-=i*detrminant(remove(m,0,count))
			count+=1
		return ans

def column(m,n):
	column=[]
	for i in m:
		column.append(i[n])
	return column
	
def multiply(m1,m2):
	if len(m1[0])!=len(m2):return None
	matrix=[]
	for i in m1:
		row=[]
		count=0
		while count<len(m2[0]):
			col=column(m2,count)
			ans=0
			for j in range(len(m2)):
				ans+=i[j]*col[j]
			row.append(ans);
			count+=1
		matrix.append(row)
	return matrix
		
def null_space(m):
	if len(m)<len(m[0]):diag=len(m)
	else:diag=len(m[0])
	lambd=[]
	for i in range(100):
		if len(lambd)==diag-1:break
		for j in range(diag):
			m[j][j]=m[j][j]-i
		if detrminant(m)==0:
			lambd.append(i)
		for j in range(diag):
			m[j][j]=m[j][j]+i
			
	null=[]
	for i in lambd:
		for j in range(diag):
			m[j][j]=m[j][j]-i
		
		print('',i)
		mtm=multiply(m,transpose(m))
		temp=multiply(inverse(mtm),transpose(m))
		print_matrix(temp)
		vi=multiply(temp,[[0],[0],[0]])
		null.append(vi)
		
		for j in range(diag):
			m[j][j]=m[j][j]+i
	return transpose(null)

def cofactor(m):
	cofactor=[]
	for i in range(len(m)):
		row=[]
		for j in range(len(m[i])):
			if (i+j)%2!=0:ans=detrminant(remove(m,i,j))
			else:ans=-detrminant(remove(m,i,j))
			row.append(-ans)
		cofactor.append(row)
	return cofactor

def transpose(m):
	trans=[]
	for i in range(len(m)):
		trans.append(column(m,i))
	return trans

def inverse(m):
	cof=cofactor(m)
	adj=transpose(cof)
	
	inverse=[]
	for i in adj:
		row=[]
		for j in i:
			row.append(j/detrminant(m))
		inverse.append(row)
	return inverse

print('\n The Matrix :')
print_matrix(m)

print(null_space(m))


print()
