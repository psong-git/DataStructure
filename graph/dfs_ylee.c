#include <stdio.h>
#include "arraygraph.h"
#include "kruskal.h"
#include "minheap.h"


// int	isCycle(ArrayGraph *pGraph, int fromVertexID, int targetID)
// {
// 	int	cycle;

// 	for (int i = 0; i < pGraph->maxVertexCount; i++)
// 	{
// 		if (pGraph->ppAdjEdge[fromVertexID][i] > 0)
// 		{
// 			if (i == targetID)
// 				return (TRUE);
// 			cycle = isCycle(pGraph, i, targetID));
// 		}
// 	}
// 	return FALSE;
// }

// int	isCycle(ArrayGraph *pGraph, int fromVertexID, int targetID)
// {
// 	int	cycle;

// 	for (int i = 0; i < pGraph->maxVertexCount; i++)
// 	{
// 		if (pGraph->ppAdjEdge[fromVertexID][i] > 0)
// 		{
// 			if (i == targetID)
// 				return (TRUE);
// 			cycle = isCycle(pGraph, i, targetID));
// 		}
// 	}
// 	return FALSE;
// }
