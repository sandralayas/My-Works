# Depth First Search

class Node:

	
	def __init__(self,number,colour,parent):
		self.number=number
		self.colour=colour
		self.parent=parent
		nodes.append(self)

	def give_node(self,required):
		for node in nodes:
			if node.number==required:
				return node

def input_graph():
	nodes=int(input('\n Enter the number of nodes : '))
	
	graph=[]
	for each_node in range(nodes):
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

def Depth_First_Search(graph,start):

	nodes=[]
	node_number=0
	for node in graph:
		Node create_node
		create_node(node_number,'white',None)

		nodes.append(create_node)

		node_number+=1

	for node in nodes:
		if node.colour=='white':
			node.colour='grey'
			_Depth_First_Search(nodes,node)

def _Depth_First_Search(graph,nodes,start):
	
	for adj_node in nodes:pass

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
 6. Biconditional search''')

	choice=input('\n Enter your choice : ')
	if choice=='0':
		procced=False
	elif choice=='1':
		graph=input_graph()
	else:
		print('\n Worng option !!')

print()


