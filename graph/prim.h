#ifndef PRIM_H
#define PRIM_H

#include <stdio.h>
#include "arraygraph.h"
#include "kruskal.h"
#include "minheap.h"

void	heap_init();
int		check_used_edge(ArrayGraph	*prim, int from, int to);
void	PrimAlgo(ArrayGraph	*undirected, ArrayGraph	*prim, int vertexID);

#endif

