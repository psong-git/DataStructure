#ifndef FLOYD_H
#define FLOYD_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "arraygraph.h"
#include "dijkstra.h"


void floydAlgo(ArrayGraph *floyd, int **distance);

#endif