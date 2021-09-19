#ifndef DIJKSTRA_H
# define DIJKSTRA_H


#include <stdio.h>
#include "arraygraph.h"
#include "kruskal.h"
#include "minheap.h"
#include "prim.h"

void	printDistance(ArrayGraph *dijkstra, int *distance, int vertexID);
int *dijkstraInit(ArrayGraph *dijkstra, int vertexID);
void   dijkstraAlgo(ArrayGraph *dijkstra, int *distance, int vertexID);


#endif