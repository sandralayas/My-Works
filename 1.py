# Depth First Search

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

	node_status=[]
	for node in graph:
		node_colour_parent=[node,'white',None]
		node_status.append(node_colour_parent)
	for node in node_status:
		if node[1]=='white':
			node[1]='grey'
			_Depth_First_Search(node_status,node)

def _Depth_First_Search(node_status,start):
	
	for adj_node in node_status:pass

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

