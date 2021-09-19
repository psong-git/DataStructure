#include "kruskal.h"

extern heap_node arr[100000];
extern int size;

/*

edge weight 정보로 heap 을 만든다.
edge 개수 = 0
while (edge 개수 != vertex 개수 - 1)
{
	heap 의 root 를 꺼낸다.(가장 weight 가 작은 edge)
	root edge weight에 연결된 vertex 2개를 체크한다.
	새로 만든 그래프에서 각 vertex 가 cycle 이 생기는지 확인한다.
	if (cycle 생김)
		cycle 이 생기면 heap 에서 꺼낸 edge 는 파기
	else
	{
		cycle 안생기면 edge 와 vertex 가 new graph 에 최종 들어간다.
		edge 개수 ++
	} 
}

*/

int  KruAlgo(ArrayGraph	*kruskal)
{
	heap_node	del;
	int				from;
	int				to;
  int       weight;

	print_heap();
  del = deleteElement();
  from = del.fromVertex;
  to = del.toVertex;
  weight = del.weight;

	addEdgewithWeightAG(kruskal, from, to, weight);
  if (isCycle(kruskal, -1, from, from) == TRUE || isCycle(kruskal, -1, to, to) == TRUE)
	{
    removeEdgeAG(kruskal, from, to);
		return (FAIL);
	}
	return (SUCCESS);
}