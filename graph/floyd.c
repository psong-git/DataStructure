#include "floyd.h"

void floydAlgo(ArrayGraph *floyd, int **distance)
{
    for (int i = 0; i < floyd->maxVertexCount; i++)
    {
    	dijkstraAlgo(floyd, distance[i], i);
		printDistance(floyd, distance[i], i);
		for (int j=0; j < floyd->maxVertexCount; j++)
			floyd->visited[j] = NOT_VISITED;
    }
}