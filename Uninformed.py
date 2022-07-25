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
	
	def print_data(self):
		print('\n The node number : ',self.number)
		print(' The node colour : ',self.colour)
		if self.parent!=None:
			print(' The parent node : ',(self.parent).give_number())
		else:print(' The Root node')
		
		if(len(self.children)!=0):
			print(' The node children are\n')
			for i in self.children:
				print('',i)#.give_number()
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
	node_count=0
	child_list=[]
	for _0_or_1 in connections:
		node_count+=1
		if _0_or_1==1:
			child_list.append(node_count)
	node.add_children(child_list)

def graph_to_nodes(graph):
	node_count=0
	nodes_list=[]
	for connections in graph:
		node_count+=1
		node=Node(node_count,'white',None,[])
		transform(connections,node)
		nodes_list.append(node)
	return nodes_list


def Depth_First_Search(nodes_list,start):

	Tree=[]
	for node in nodes_list:
		if node.give_number()==start:
			Tree.append(node)
			break

	#for node in Tree:
	if node.give_colour()=='white':
		node.set_colour('grey')
		Tree=_Depth_First_Search(Tree,node)
			
	return Tree

def _Depth_First_Search(Tree,node):
	
	for adj_node in node.give_children():
		if node.give_colour()=='white':
			node.set_colour('grey')
			node.set_parent(node)
			Tree=_Depth_First_Search(Tree,adj_node)
	node.set_colour('black')
	Tree.append(node)
	
	return Tree
	
graph=[\
[0,1,1,1,0],\
[1,0,1,0,0],\
[1,1,0,0,1],\
[1,0,0,0,0],\
[0,0,1,0,0]\
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
 7. Display the tree''')

	choice=input('\n Enter your choice : ')
	if choice=='0':
		procced=False
	elif choice=='1':
		graph=input_graph()
		nodes_list=graph_to_nodes(graph)
	elif choice=='3':
		Tree=Depth_First_Search(nodes_list,0)
	elif choice=='7':
		for node in Tree:
			node.print_data()
	else:
		print('\n Wrong option !!')

print()


'''
node1=Node(1,'white',None,[])

node1_1=Node(2,'white',node1,[])
node1_2=Node(3,'white',node1,[])

node1.add_children([node1_1,node1_2])

node1_2_1=Node(4,'white',node1_2,[])
node1_2.add_children([node1_2_1])

node1.print_data()
node1_1.print_data()
node1_2.print_data()
node1_2_1.print_data()
'''

