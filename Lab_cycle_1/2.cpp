/*
Question 2
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<list<int>> adj;

public:
	Graph(int V);
	void addEdge(int v, int w);

	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V, false);

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto adjecent : adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

int main()
{
	/*
		Graph g(6);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(0, 3);
		g.addEdge(1, 4);
		g.addEdge(2, 5);
		g.addEdge(2, 6);
		g.addEdge(3, 7);

		cout << "Following is Breadth First Traversal "
			 << "(starting from vertex 2) \n";
		g.BFS(0);
	*/
	int input;

	cout << "\n Enter the number of nodes : ";
	cin >> input;
	int size = input;
	Graph g(size);

	int choice;
	do
	{
		cout << "\n 1. Add an edge"
			 << "\n 2. Output BFS"
			 << "\n\n Enter your choice : ";
		cin >> input;

		choice = input;
		if (choice == 1)
		{
			int x, y;
			cout << "\n Enter the parent node : ";
			cin >> input;
			x = input;
			cout << " Enter its child node : ";
			cin >> input;
			y = input;
			g.addEdge(x, y);
		}

		if (choice == 2)
		{
			cout << "\n Enter the source node : ";
			cin >> input;
			int source = input;
			cout << "Following is Breadth First Traversal starting from vertex " << source << endl;
			g.BFS(source);
		}
	} while (choice != 2);

	cout << endl;
	return 0;
}