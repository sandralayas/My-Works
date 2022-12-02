/*
Question 3
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	map<int, bool> visited;
	map<int, list<int>> adj;

	void addEdge(int v, int w);

	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

int main()
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 6);
	g.addEdge(3, 7);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";

	g.DFS(2);

	return 0;
}