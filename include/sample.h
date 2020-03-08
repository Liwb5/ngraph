#ifndef __SAMPLE_H
#define __SAMPLE_H

#include <iostream>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "graph.h"
#include "sample.h"
#include "nametype.h"

using namespace std;

IdArray base_random_walk(const Graph &graph, vertex_t start_node, int depth);
// d2Array random_walk(IdArray start_nodes, int depth, int thread_num=1);

#endif /*__SAMPLE_H*/
