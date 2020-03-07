#include "graph.h"

Graph::Graph(IdArray src_ids, IdArray dst_ids, size_t num_nodes) {

    //TODO: assert src_ids.size() == dst_ids.size()
    num_edges_ = src_ids.size();
    num_nodes_ = num_nodes;

    vector<uint64_t> indegree(num_nodes, 0);
    vector<uint64_t> outdegree(num_nodes, 0);
    d2Array successors(num_nodes);
    d2Array succ_eids(num_nodes);
    d2Array predecessors(num_nodes);
    d2Array pred_eids(num_nodes);

    for (uint64_t i = 0; i < num_edges_; i++) {
        outdegree[src_ids[i]] += 1;
        indegree[dst_ids[i]] += 1;

        vertex_t src = src_ids[i];
        vertex_t dst = dst_ids[i];

        successors[src].push_back(dst);
        succ_eids[src].push_back(i);

        predecessors[dst].push_back(src);
        pred_eids[dst].push_back(i);
    }

    outdegree_ = outdegree;
    indegree_ = indegree;
    successors_ = successors;
    succ_eids_ = succ_eids;
    predecessors_ = predecessors;
    pred_eids_ = pred_eids;

    
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

d2Array Graph::successor(IdArray nodes) {
    d2Array result;
    for (vertex_t id=0; id < nodes.size(); id++) {
        result.push_back(successors_[nodes[id]]);
    }
    return result;
}

d2Array Graph::predecessor(IdArray nodes) {
    d2Array result;
    for (vertex_t id=0; id < nodes.size(); id++) {
        result.push_back(predecessors_[nodes[id]]);
    }
    return result;
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

uint64_t Graph::num_edges() {
    return num_edges_;
}

uint64_t Graph::num_nodes() {
    return num_nodes_;
}

