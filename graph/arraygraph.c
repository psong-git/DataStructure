#include "arraygraph.h"

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *graph;
	int				**ppAdjEdge;
	int				*pVertex;

	graph = malloc(sizeof(ArrayGraph));
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	ppAdjEdge = malloc(sizeof(int *) * maxVertexCount);
	for (int i = 0; i < maxVertexCount; i++)
	{
		ppAdjEdge[i] = calloc(maxVertexCount, sizeof(int));
	}
	graph->ppAdjEdge = ppAdjEdge;
	pVertex = calloc(maxVertexCount, sizeof(int));
	graph->pVertex = pVertex;
 	graph->visited = calloc(maxVertexCount, sizeof(int));
	return (graph);
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		free(pGraph->ppAdjEdge[i]);
	}
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
	printf("그래프가 삭제되었습니다.\n");
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{
	if (!pGraph)
	{
		printf("그래프를 먼저 생성해주세요\n");
		return (FALSE);
	}
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
	{
		//printf("그래프를 먼저 생성해주세요\n");
		return (FAIL);
	}
	if (pGraph->currentVertexCount == pGraph->maxVertexCount)
	{ 
		//printf("노드의 갯수가 초과되었습니다.\n");
		return (FAIL);
	}
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
	{
		//printf("노드 인덱스를 벗어났습니다.\n");
		return (FAIL);
	}
	if (pGraph->pVertex[vertexID])
	{
		//printf("중복된 노드입니다\n");
		return (FAIL);
	}
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	}
	return (FAIL);
}

// 노드의 유효성 점검
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
	{
		//printf("그래프를 먼저 생성해주세요\n");
		return (FALSE);
	}
	if (vertexID < 0 || vertexID >= pGraph->maxVertexCount)
	{
		//printf("노드 인덱스를 벗어났습니다.\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID])
		return (TRUE);
	return (FALSE);
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) == FALSE)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		removeEdgeAG(pGraph, vertexID, i);
		removeEdgeAG(pGraph, i, vertexID);
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	return (SUCCESS);
}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) && checkVertexValid(pGraph, toVertexID))
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
		return (SUCCESS);
	}
	return (FAIL);
}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph)
{
	printf("============================\n");
	printf("current graph max count : %d\n", pGraph->maxVertexCount);
	printf("current graph current count : %d\n", pGraph->currentVertexCount);
	printf("    0 1 2 3 4 5\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
        printf("%d : ", i);
		for (int j = 0; j< pGraph->maxVertexCount; j++)
		{
			if (pGraph->ppAdjEdge[i][j] != INT_MAX)
				printf("%d ", pGraph->ppAdjEdge[i][j]);
			else
				printf("∞ ");
		}
		printf("\n");
	}
	printf("============================\n\n");
}