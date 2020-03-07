#include "graph.h"

Graph::Graph(IdArray src_ids, IdArray dst_ids, size_t num_nodes) {

    //TODO: assert src_ids.size() == dst_ids.size()
    num_edges_ = src_ids.size();
    num_nodes_ = num_nodes_;
    // outdegree_.reserve(num_nodes);
    // indegree_.reserve(num_nodes);
    vector<uint64_t> indegree(num_nodes, 0);
    vector<uint64_t> outdegree(num_nodes, 0);
    for (uint64_t i = 0; i < num_edges_; i++) {
        outdegree[src_ids[i]] += 1;
        indegree[dst_ids[i]] += 1;
    }
    outdegree_ = outdegree;
    indegree_ = indegree;

    
    // adjlist_.reserve(num_nodes);
    // edgeidlist_.reserve(num_nodes);
    // for (uint64_t i = 0; i < num_edges_; i++) {
    //     vertex_t src = src_ids[i];
    //     vertex_t dst = src_ids[i];
    //
    //     adjlist_[src].push_back(dst);
    //     edgeidlist_[src].push_back(i);
    // }

}

uint64_t Graph::num_edges() {
    return num_edges_;
}

vector<uint64_t> Graph::indegree(IdArray nodes) {
    vector<uint64_t> result;
    for (vertex_t id=0; id < nodes.size(); id++) {
        result.push_back(indegree_[nodes[id]]);
    }

    return result;
}

vector<uint64_t> Graph::outdegree(IdArray nodes) {
    vector<uint64_t> result;
    for (vertex_t id=0; id < nodes.size(); id++) {
        result.push_back(outdegree_[nodes[id]]);
    }

    return result;
}

uint64_t Graph::num_nodes() {
    return num_nodes_;
}


