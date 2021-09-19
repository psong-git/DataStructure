#include <stdio.h>
#include "arraygraph.h"
#include "kruskal.h"
#include "minheap.h"
#include "prim.h"
#include "dijkstra.h"
#include <math.h>
#include <limits.h>
#include "floyd.h"


heap_node arr[100000];
int size;

int	isCycle(ArrayGraph *kruskal, int parent, int fromVertexID, int targetID)
{
  if (parent == -1)
  {
    for (int i = 0; i < kruskal->maxVertexCount; i++)
		kruskal->visited[i] = 0;
  }
  if (kruskal->visited[fromVertexID] != 0)
    return (0);
 // printf("%d\n", fromVertexID);
	kruskal->visited[fromVertexID] = VISITED;
	for (int i = 0; i < kruskal->maxVertexCount; i++)
	{
		if (kruskal->ppAdjEdge[fromVertexID][i] > 0)
		{
			if (i != parent && i == targetID)
			{
//				printf("find cycle!! targetID : %d\n", targetID);
				return (1);
			}
			if (isCycle(kruskal, fromVertexID, i, targetID) == 1)
				return (1);
		}
	}
  return (0);
}

int main(void)
{
	ArrayGraph	*undirected;
	ArrayGraph	*kruskal;
	ArrayGraph	*prim;
    ArrayGraph	*dijkstra;
	ArrayGraph	*floyd;

	undirected = createArrayGraph(6);
	kruskal = createArrayGraph(6);
	prim = createArrayGraph(6);
    dijkstra = createArrayGraph(6);
	floyd = createArrayGraph(6);

	for (int i = 0; i < 6; i++)
    {
		addVertexAG(undirected, i);
        addVertexAG(kruskal, i);
        addVertexAG(dijkstra, i);
		addVertexAG(floyd, i);
    }

	addEdgewithWeightAG(undirected, 0, 1, 4);
	addEdgewithWeightAG(undirected, 1, 2, 2);		
	addEdgewithWeightAG(undirected, 2, 0, 3);
	addEdgewithWeightAG(undirected, 2, 3, 1);
	addEdgewithWeightAG(undirected, 3, 4, 1);
	addEdgewithWeightAG(undirected, 3, 5, 5);
	addEdgewithWeightAG(undirected, 4, 5, 6);

    addEdgewithWeightAG(dijkstra, 0, 1, 1);
	addEdgewithWeightAG(dijkstra, 1, 2, 2);		
	addEdgewithWeightAG(dijkstra, 2, 0, 4);
	addEdgewithWeightAG(dijkstra, 2, 3, 1);
	addEdgewithWeightAG(dijkstra, 3, 4, 8);
	addEdgewithWeightAG(dijkstra, 3, 5, 3);
	addEdgewithWeightAG(dijkstra, 4, 5, 4);

	addEdgewithWeightAG(floyd, 0, 1, 1);
	addEdgewithWeightAG(floyd, 1, 2, 2);		
	addEdgewithWeightAG(floyd, 2, 0, 4);
	addEdgewithWeightAG(floyd, 2, 3, 1);
	addEdgewithWeightAG(floyd, 3, 4, 8);
	addEdgewithWeightAG(floyd, 3, 5, 3);
	addEdgewithWeightAG(floyd, 4, 5, 4);

	printf("this graph is original\n");
	displayArrayGraph(undirected);
	
	//kruskal
	create_kruskal_heap(undirected);

	int	edge_cnt;
	edge_cnt = 0;
    while (edge_cnt != 5)
    {
        if (KruAlgo(kruskal) == SUCCESS)
			edge_cnt++;
    }
	printf("\nthis graph is kruskal\n");
    displayArrayGraph(kruskal);
	// isCycle(undirected, 0, 0, 0);
	
/*
	//heap 만들기


	displayArrayGraph(kruskal);
	printf("size : %d\n", size);
	for (int i = 1; i <= size; i++)
    printf("index : %d from : %d to : %d (weight : %d)\n", i, arr[i].fromVertex, arr[i].toVertex, arr[i].weight);

*/

	
	// PrimAlgo(undirected, prim);
    addVertexAG(prim, 0);
    PrimAlgo(undirected, prim, 0);
	printf("\nthis graph is prim\n");
	displayArrayGraph(prim);

	printf("\nthis graph is dijkstra\n");

	displayArrayGraph(dijkstra);

    int *distance = dijkstraInit(dijkstra, 0);
    dijkstraAlgo(dijkstra, distance, 0);
	printf("    0\t1\t2\t3\t4\t5\n");
	printf("-----------------------------\n");
	printDistance(dijkstra, distance, 0);

    // floyd
	printf("\nthis graph is floyd\n");
	displayArrayGraph(floyd);
	int	**allDistance = malloc(sizeof(int *) * floyd->maxVertexCount);
	for (int i = 0; i < floyd->maxVertexCount; i++)
		allDistance[i] = dijkstraInit(floyd, i);
	printf("    0\t1\t2\t3\t4\t5\n");
	printf("-----------------------------\n");
	floydAlgo(floyd, allDistance);

  return 0;
}