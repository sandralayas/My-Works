# Depth First Search

def input_graph():
	nodes=int(input('\n Enter the number of nodes : '))
	
	graph=[]
	for each_node in range(nodes):
		connections=[]
		for to_nodes in range(nodes):
			print('',each_node,'-->',to_nodes)
			_0_or_1=int(input(' Enter one if ther is a connection \
else enter zero : '))
			connections.append(_0_or_1)
		graph.append(connections)
	print('\n The entered graph :-')
	for i in graph:
		for j in i:
			print(j,end=' ')
		print()
			
input_graph()

print()
