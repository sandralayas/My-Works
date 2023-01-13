/*
Question 5
*/

#include <stdio.h>
//#define V 6
//#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist);
}

void printSolution(int dist[][V])
{
	printf(
		"The following matrix shows the shortest distances"
		" between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int V,input;
	
	cout<<"\n Enter the size of the matrix : ";cin>>V;
	int graph[V][V];
	cout<<"\n Enter the  matrix : \n\n";
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cin>>input;
			graph[i][j]=input;
		}
	}
	
	 				//{{0, INF, INF, INF, -1, INF},
	 				//{1, 0, INF, 2, INF, INF},
					//{INF, 2, 0, INF, INF, -8},
					//{-4, INF, INF, 0, 3, INF},
					//{INF, 7, INF, INF, 0, INF},
					//{INF, 5, 10, INF, INF, 0}};

	floydWarshall(graph);
	return 0;
}
