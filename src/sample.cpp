#include "sample.h"

IdArray base_random_walk(const Graph &graph, vertex_t start_node, int depth) {
    IdArray walk;
    walk.push_back(start_node);
    IdArray cur_node(1, start_node);
    for (int i=0; i<depth; i++) {
        d2Array succ = graph.successor(cur_node);
        if (succ[0].size() == 0) {
            break;
        }

        int index = rand() % succ[0].size();
        vertex_t next_node = succ[0][index];
        walk.push_back(next_node);
        cur_node[0] = next_node;
    }
    return walk;
}

d2Array random_walk(const Graph &graph, const IdArray &start_nodes, int depth) {
    srand((unsigned)time(NULL));  // random seed
    d2Array walks(start_nodes.size());
    for (int i=0; i<start_nodes.size(); i++) {
        walks[i] = base_random_walk(graph, start_nodes[i], depth);
    }
    return walks;

}
