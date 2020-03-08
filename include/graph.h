#ifndef __GRAPH_H
#define __GRAPH_H

#include <iostream>
#include <vector>
#include <stdint.h>
#include "nametype.h"

using namespace std;
// typedef uint64_t vertex_t;
// typedef vector<vertex_t> IdArray;
// typedef vector<vector<vertex_t>> d2Array;

class Graph {
    public:
        Graph() {};
        Graph(IdArray src_ids, IdArray dst_ids, uint64_t num_nodes);

        ~Graph() {};

        uint64_t num_edges() const;
        uint64_t num_nodes() const;
        vector<uint64_t> indegree(IdArray nodes) const;
        vector<uint64_t> outdegree(IdArray nodes) const;
        d2Array successor(IdArray nodes) const;
        d2Array predecessor(IdArray nodes) const;


        // struct EdgeList {
        //     vector<vertex_t> succ;
        //     vector<uint64_t> edge_id;
        // };
        // typedef vector<vertex_t, uint64_t> AdjacencyList;
        // AdjacencyList adjlist_;

        uint64_t num_edges_;
        uint64_t num_nodes_;
        vector<uint64_t> indegree_;
        vector<uint64_t> outdegree_;
        d2Array successors_;
        d2Array succ_eids_;
        d2Array predecessors_;
        d2Array pred_eids_;

};

#endif /*__GRAPH_H*/
