#include "minheap.h"

extern heap_node arr[100000];
extern int size;

void	print_heap(void)
{
	for (int i = 1; i <= size; i++)
		printf("%d ", arr[i].weight);
	printf("\n");
}

// 노드 추가될 때 일어나는 부모노드 자식노드 교환
void	p_recursive(int index)
{
	heap_node tmp;

	if (arr[index/2].weight > arr[index].weight && index != 1)
	{
		tmp = arr[index/2];
		arr[index/2] = arr[index];
		arr[index] = tmp;
		p_recursive(index/2);
	}
}

//heap 에 int x 노드 추가
void	insertElement(int weight, int fromVertex, int toVertex)
{
	heap_node	newNode;

	newNode.weight = weight;
	newNode.fromVertex = fromVertex;
	newNode.toVertex = toVertex;
	arr[++size] = newNode;
	p_recursive(size);
}

// 노드 삭제될 때 일어나는 부모노드 자식노드 교환
void	exchange(int parent, int child)
{
	heap_node tmp;

	if (arr[parent].weight > arr[child].weight && arr[child].weight != 0)
	{
		tmp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = tmp;
	}
}

// 노드 삭제할 때 노드 체크(왼, 오)하고 필요하면 부모노드 자식노드 교환(exchange)
void	m_recursive(int index)
{
	int leftChild = arr[index * 2].weight;
	int rightChild = arr[index * 2 + 1].weight;
	int nextIndex;
	
  if (size == 2)
  {
      exchange(1,2);
  }
	if (!(index <= size))
		return ;
	if (leftChild <= rightChild)
		nextIndex = index * 2;
	else
		nextIndex = index * 2 + 1;
	if (arr[index].weight > arr[nextIndex].weight)
	{
		exchange(index, nextIndex);
		m_recursive(nextIndex);
	}
}

// 루트 노드 삭제하고 m_recursive 돌려서 힙 맞추기, 삭제된 루트 노드 값 반환
heap_node		deleteElement(void)
{
	heap_node maxKey;

	maxKey.weight = 0;
	maxKey.fromVertex = 0;
	maxKey.toVertex = 0;
	if (size == 0)
		return (maxKey);
	maxKey = arr[1];
	arr[1] = arr[size];
	arr[size].weight = 0;
	arr[size].fromVertex = 0;
	arr[size].toVertex = 0;
	size--;
	m_recursive(1);
	return (maxKey);
}

void  create_kruskal_heap(ArrayGraph *undirected)
{
  for (int y = 0; y < undirected->maxVertexCount; y++)
  {
    for (int x = y; x < undirected->maxVertexCount; x++)
    {
      if (undirected->ppAdjEdge[y][x] > 0)
        insertElement(undirected->ppAdjEdge[y][x], y, x);
    }
  }
}

// void  create_prim_heap(ArrayGraph *undirected, int VertexID)
// {
// 	int y = VertexID;
	
// 	for (int x = y; x < undirected->maxVertexCount; x++)
// 	{
// 		if (undirected->ppAdjEdge[y][x] > 0)
// 			insertElement(undirected->ppAdjEdge[y][x], y, x);
// 	}
// }

void  create_prim_heap(ArrayGraph *undirected, ArrayGraph *prim, int VertexID)
{
	int y = VertexID;
	
	for (int x = 0; x < undirected->maxVertexCount; x++)
	{
		if (undirected->ppAdjEdge[y][x] > 0)
			if (check_used_edge(prim, y, x) == FALSE)
				insertElement(undirected->ppAdjEdge[y][x], y, x);
	}
}

/*
int		main(void)
{
	int N;
	int key;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &key);
		if (key == 0) {
			printf("%d\n", deleteElement());
		}
		else insertElement(key);
	}
	return (0);
}
*/