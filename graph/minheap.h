#ifndef _MIN_HEAP_
# define _MIN_HEAP_

#include <stdio.h>
#include "arraygraph.h"
#include "kruskal.h"
#include "prim.h"

typedef struct s_node
{
	int weight;
	int fromVertex;
	int toVertex;
}             heap_node;

// static heap_node arr[100000];
// static int size;

int	isCycle(ArrayGraph *graph, int parent, int fromVertexID, int targetID);

void	print_heap(void);

// 노드 추가될 때 일어나는 부모노드 자식노드 교환
void	p_recursive(int index);

//heap 에 int x 노드 추가
void	insertElement(int weight, int fromVertex, int toVertex);

// 노드 삭제될 때 일어나는 부모노드 자식노드 교환
void	exchange(int parent, int child);
// 노드 삭제할 때 노드 체크(왼, 오)하고 필요하면 부모노드 자식노드 교환(exchange)
void	m_recursive(int index);

// 루트 노드 삭제하고 m_recursive 돌려서 힙 맞추기, 삭제된 루트 노드 값 반환
heap_node		deleteElement();

void  create_kruskal_heap(ArrayGraph *undirected);
void  create_prim_heap(ArrayGraph *undirected, ArrayGraph *prim, int VertexID);
#endif