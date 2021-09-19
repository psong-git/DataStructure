#include "prim.h"

extern heap_node arr[100000];
extern int size;

void	heap_init()
{
	for (int i = 0; i <= size; i++)
	{	
		arr[i].fromVertex = 0;
		arr[i].toVertex = 0;
		arr[i].weight = 0;
	}
	size = 0;
}

int		check_used_edge(ArrayGraph	*prim, int from, int to)
{
	if (prim->ppAdjEdge[from][to] > 0)
		return (TRUE);
	return (FALSE);
}

void	PrimAlgo(ArrayGraph	*undirected, ArrayGraph	*prim, int vertexID)
{
	heap_node	 del;
	int				from;
	int				to;
	int       weight;

	if (prim->currentVertexCount == undirected->maxVertexCount)
		return ;
	heap_init();
	
	for (int i = 0; i < prim->maxVertexCount; i++)
	{
		if (prim->pVertex[i] == USED)
			create_prim_heap(undirected, prim, i);
	}
	
	while (size)
	{
		del = deleteElement();
		from = del.fromVertex;
		to = del.toVertex;
		weight = del.weight;
		
		addVertexAG(prim, to);
		addEdgewithWeightAG(prim, from, to, weight);
		if (isCycle(prim, -1, to, to) == FALSE)
			break;
		removeEdgeAG(prim, from, to);
	}
	PrimAlgo(undirected, prim, to);
}

/*
int		check_used_edge(ArrayGraph	*prim, int fromVertexID, int toVertexID)
{
	if (prim->ppAdjEdge[fromVertexID][toVertexID] > 0)
		return (TRUE);
	return (FALSE);
}

void	PrimAlgo(ArrayGraph	*undirected, ArrayGraph	*prim)
{
	int check = 0;
	int	edge_cnt = 0;
	int	newVertexID;
	int	weight;
	int from;
	int to;
	heap_node	del;

	addVertexAG(prim, 0);
	while (edge_cnt != prim->maxVertexCount - 1)
	{
		check = 0;
		newVertexID = 0;
		//heap 초기화
		while (size > 0)
			deleteElement();
		//PrimHeap = createPrimHeap(USED 인 vertex에 연결된 edge)
		createPrimHeap(undirected, prim);
		while (check == 0)
		{
			del = deleteElement();
			weight = del.weight;
			from = del.fromVertex;
			to = del.toVertex;
			if (prim->pVertex[from] != USED)
				newVertexID = from;
			else if (prim->pVertex[to] != USED)
				newVertexID = to;
			while (check_used_edge(prim, from, to) == TRUE)
			{
				del = deleteElement();
				weight = del.weight;
				from = del.fromVertex;
				to = del.toVertex;
				if (prim->pVertex[from] != USED)
					newVertexID = from;
				else if (prim->pVertex[to] != USED)
					newVertexID = to;
			}
			//printf("newVertexID is %d\n", newVertexID);
			addVertexAG(prim, from);
			addVertexAG(prim, to);
			addEdgewithWeightAG(prim, from, to, weight);
			if (isCycle(prim, -1, del.fromVertex, del.fromVertex) == TRUE || isCycle(prim, -1, del.toVertex, del.toVertex) == TRUE)
			{
				//printf("from %d to %d edge(%d) is cycled\n", from, to, weight);
				removeEdgeAG(prim, from, to);
				if (newVertexID != 0)
					prim->pVertex[newVertexID] = NOT_USED;
			}
			else
			{
				//printf("from %d to %d edge(%d) add\n", from, to, weight);
				check = 1;
				edge_cnt++;
			}
		}
	}
}

*/