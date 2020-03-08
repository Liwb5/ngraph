#ifndef __SAMPLE_H
#define __SAMPLE_H

#include <iostream>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "graph.h"
#include "sample.h"
#include "nametype.h"

using namespace std;
namespace py = pybind11;

IdArray base_random_walk(const Graph &graph, vertex_t start_node, int depth);
d2Array random_walk(const Graph &graph, const IdArray &start_nodes, int depth);

#endif /*__SAMPLE_H*/
