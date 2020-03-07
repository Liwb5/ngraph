#include "graph.h"

Graph::Graph(IdArray src_ids, IdArray dst_ids, size_t num_nodes) {

    // this->AddVertices(num_nodes)
    num_edges_ = src_ids.size();
    num_nodes_ = num_nodes_;
    //TODO: assert src_ids.size() == dst_ids.size()
    for (uint64_t i = 0; i < num_edges_; i++) {
        outdegree_[src_ids[i]] += 1;
        indegree_[dst_ids[i]] += 1;
    }

    
    adjlist_.reserve(num_nodes);
    edgeidlist_.reserve(num_nodes);
    for (uint64_t i = 0; i < num_edges_; i++) {
        vertex_t src = src_ids[i];
        vertex_t dst = src_ids[i];

        adjlist_[src].push_back(dst);
        edgeidlist_[src].push_back(i);
    }

}

uint64_t Graph::num_edges() {
    return num_edges_;
}

uint64_t Graph::num_nodes() {
    return num_nodes_;
}


