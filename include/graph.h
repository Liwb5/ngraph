#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;
typedef uint64_t vertex_t;
typedef vector<vertex_t> IdArray;

class Graph {
    public:
        Graph() {};
        Graph(IdArray src_ids, IdArray dst_ids, uint64_t num_nodes);

        ~Graph() {};

        uint64_t num_edges();
        uint64_t num_nodes();
        vector<uint64_t> indegree(IdArray nodes);
        vector<uint64_t> outdegree(IdArray nodes);

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
        vector<vector<vertex_t>> adjlist_;
        vector<vector<vertex_t>> edgeidlist_;

};
