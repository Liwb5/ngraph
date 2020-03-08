#-*- coding: utf-8 -*-
import time
import unittest
import json
import os
import numpy as np

import ngraph as ng
import pgl

class NGraphTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        np.random.seed(1)
        edge_list = [(2, 0), (2, 1), (3, 1),(4, 0), (5, 0), 
                     (6, 0), (6, 4), (6, 5), (7, 0), (7, 1),
                     (7, 2), (7, 3), (8, 0), (9, 7)]

        src_ids = []
        dst_ids = []
        for pair in edge_list:
            src_ids.append(pair[0])
            dst_ids.append(pair[1])
            src_ids.append(pair[1])
            dst_ids.append(pair[0])
            
        num_nodes = 10
        cls.graph = ng.Graph(src_ids, dst_ids, num_nodes)
        cls.pgl_graph = pgl.graph.Graph(num_nodes, list(zip(src_ids, dst_ids)))

    def test_num_nodes(self):
        print()
        ground = 10
        self.assertEqual(self.graph.num_nodes(), ground)

    def test_num_edges(self):
        print()
        ground = 28
        self.assertEqual(self.graph.num_edges(), ground)

    def test_randomwalk_speed(self):
        print()
        num = 1000
        depth = 1000
        start_nodes = [0 for i in range(num)]
        start = time.time()
        pgl_walks = self.pgl_graph.random_walk(start_nodes, depth)
        print("pgl random walk time: %.4f s with %d start_nodes and depth==%d" 
                % (time.time() - start, num, depth))
        #  print(pgl_walks[0])

        start = time.time()
        ngraph_walks = ng.random_walk(graph=self.graph, 
                                      nodes=start_nodes, 
                                      depth=depth)
        print("ngraph random walk time: %.4f s with %d start_nodes and depth==%d" 
                % (time.time() - start, num, depth))


if __name__ == "__main__":
    unittest.main()
