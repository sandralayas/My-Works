# Depth First Search

class Node:


	def __init__(self,number,colour,parent,children):
		self.number=number
		self.colour=colour
		self.parent=parent
		self.children=children

	def give_number(self):
		return self.number
	
	def give_colour(self):
		return self.colour
	
	def give_parent(self):
		return self.parent
	
	def give_children(self):
		return self.children

	def print_data(self,root):
		print('\n The node number : ',self.number)
		print(' The node colour : ',self.colour)
		if self.parent!=None:
			print(' The parent node : ',(self.parent).give_number())
		else:print(' The Root node')
	
		empty=False
	
		if(len(self.children)==0):empty=True
		for i in self.children:
			if i==root and len(self.children)==1:empty=True
		
		if not empty:
			print(' The node children are\n')
			for i in self.children:
				if i!=root:print('',i)
		else:print(' No children nodes')

	def add_children(self,list_):
		for i in list_:
			(self.children).append(i)
	
	def set_colour(self,colour):
		self.colour=colour
	
	def set_parent(self,parent):
		self.parent=parent
	

def input_graph():
	nodes=int(input('\n Enter the number of nodes : '))

	graph=[]
	for each_node in range(nodes):#1,nodes+1
		connections=[]
		for to_nodes in range(nodes):
			print('',each_node,'-->',to_nodes)
			_0_or_1=int(input(' Enter one if their is a connection \
else enter zero : '))
			connections.append(_0_or_1)
		graph.append(connections)
	print('\n The entered graph :-')
	for i in graph:
		print(' ',end='')
		for j in i:
			print(j,end=' ')
		print()

	return graph	

def transform(connections,node):
	node_count=-1
	child_list=[]
	for _0_or_1 in connections:
		node_count+=1
		if _0_or_1==1:
			child_list.append(node_count)
	node.add_children(child_list)

def graph_to_nodes(graph):
	node_count=-1
	nodes_list=[]
	for connections in graph:
		node_count+=1
		node=Node(node_count,'white',None,[])
		transform(connections,node)
		nodes_list.append(node)
	return nodes_list

def listing(_list):
	
	temp=[]
	for i in _list:
		if i not in temp:temp.append(i)
	return temp

#BREADTH FIRST
def Breadth_First_Search(nodes_list,start):
	Tree=[]
	
	queue=[]
	for node in nodes_list:
		if node.give_number()==start:
			Tree.append(node)
			queue.append(node)
			break
			
	while len(queue)!=0:
		
		the_node=queue[0]
		del queue[0]
		for adj_node in the_node.give_children():
			#print('\n here\n')
			for node in nodes_list:
				if node.give_number()==adj_node:break
				
			if node.give_colour()=='white':
				#print('\n here\n')
				
				node.set_colour('grey')
				node.set_parent(the_node)
				Tree.append(node)
				queue.append(node)
				
		the_node.set_colour('black')
		
	return Tree
		

# DEPTH FIRST
def Depth_First_Search(nodes_list,start):

	Tree=[]
	for node in nodes_list:
		if node.give_number()==start:
			Tree.append(node)
			
			break

	for i in Tree:
		if i.give_colour()=='white':
			i.set_colour('grey')
			Tree=_Depth_First_Search(Tree,i)
		
	return listing(Tree)

def _Depth_First_Search(Tree,the_node):

	for adj_node in the_node.give_children():

		for node in nodes_list:
			if node.give_number()==adj_node:break

		if node.give_colour()=='white':
			node.set_colour('grey')
			node.set_parent(the_node)
			Tree.append(node)
			Tree=_Depth_First_Search(Tree,node)
	the_node.set_colour('black')
	Tree.append(the_node)

	return Tree
	
# UNIFORM COST
def Uniform_Cost_Search(nodes_list,start):
	
	pass

	
# DEPTH LIMIT
def Depth_Limit_Search(nodes_list,start,NODE,maxd,path):
	for node in nodes_list:
		if node.give_number()==start:break
	
	path.append(node)
	
	if NODE==node.give_number(): return True
	elif maxd<=0:return False
	
	for adj_node in node.give_children():

		for node in nodes_list:
			if node.give_number()==adj_node:break
			
		if Depth_Limit_Search(nodes_list,start,NODE,maxd,path)==True:
			return path
		else:
			for i in path:
				if i==node:
					del i
					break
	return False

# ITERATIVE DEEPENING
def Iterative_Deepening_Search(nodes_list,start,NODE,maxd):
	for i in range(1,maxd+1):
		path=[]
		if Depth_Limit_Search(nodes_list,start,NODE,maxd,path)==True:
			return True
	return False


'''
graph=[\
[0,1,1,1,0],\
[1,0,1,0,0],\
[1,1,0,0,1],\
[1,0,0,0,0],\
[0,0,1,0,0]\
]
'''
graph=[\
[0,1,1,0],\
[0,0,1,0],\
[1,0,0,1],\
[0,0,0,1]\
]

nodes_list=graph_to_nodes(graph)

procced=True


while procced:
	print('''
	M  E  N  U
       ````````````
 0. Exit the program
 1. Enter a graph
 2. Breadth First Search
 3. Depth First Search
 4. Uniform Cost Search
 5. Iterative Deepening Depth First Search
 6. Biconditional search
 7. Display the tree
 8. Display the graph''')

	choice=input('\n Enter your choice : ')
	if choice=='0':
		procced=False
	elif choice=='1':
		graph=input_graph()
		nodes_list=graph_to_nodes(graph)
	elif choice=='2':
		Root=int(input('\n Enter the root node : '))
		Tree=Breadth_First_Search(nodes_list,Root)
	elif choice=='3':
		Root=int(input('\n Enter the root node : '))
		Tree=Depth_First_Search(nodes_list,Root)
	elif choice=='5':
		Root=int(input('\n Enter the root node : '))
		NODE=int(input('\n Enter the node to search : '))
		
		maxd=3
		
		if Iterative_Deepening_Search(nodes_list,Root,NODE,maxd):print('\n The node found')
		else:print('\n The node not found')
	elif choice=='7':
		if type(Tree)!=type([]) or len(Tree)==0:print('\n No tree exists\n')
		else:
			for node in Tree:
				node.print_data(Root)
	elif choice=='8':
		header=[]
		for i in range(len(graph)):header.append(i+1)
		print('\n  ',header,'\n')
		for i in range(len(graph)):
			print('',1+i,graph[i])
	else:
		print('\n Wrong option !!')

print()



