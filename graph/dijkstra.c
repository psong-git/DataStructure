#include "dijkstra.h"

void	printDistance(ArrayGraph *dijkstra, int *distance, int vertexID)
{
	// printf("<< distance information >>\n");
	// printf("    0 1 2 3 4 5\n");
	printf("%d : ", vertexID);
	for (int i = 0; i < dijkstra->maxVertexCount; i++)
	{
		if (distance[i] == INT_MAX)
			printf("∞\t");
		else
			printf("%d\t", distance[i]);
	}
	printf("\n");
}

int *dijkstraInit(ArrayGraph *dijkstra, int vertexID)
{
  int *distance;
  distance = malloc(sizeof(int) * dijkstra->maxVertexCount);
  for (int i = 0; i < dijkstra->maxVertexCount; i++)
	{
		if (i == vertexID)
			distance[i] = 0;
		else
    	distance[i] = INT_MAX;
	}
    return (distance);
}

void   dijkstraAlgo(ArrayGraph *dijkstra, int *distance, int vertexID)
{
	if (dijkstra->visited[vertexID] == VISITED)
		return ;
	dijkstra->visited[vertexID] = VISITED;
  for (int i = 0; i < dijkstra->maxVertexCount; i++)
  {
    if (dijkstra->ppAdjEdge[vertexID][i] > 0)
    {
      if (distance[i] > distance[vertexID] + dijkstra->ppAdjEdge[vertexID][i])
      {
        distance[i] = distance[vertexID] + dijkstra->ppAdjEdge[vertexID][i];
      }
    }
  }
	// printDistance(dijkstra, distance);
	for (int i = 0; i < dijkstra->maxVertexCount; i++)
	{
		if (dijkstra->ppAdjEdge[vertexID][i] > 0)
      dijkstraAlgo(dijkstra, distance, i);
	}
}
