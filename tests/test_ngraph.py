#-*- coding: utf-8 -*-
import time
import unittest
import json
import os
import numpy as np

import ngraph as ng

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
            
        num_nodes = 10
        cls.graph = ng.Graph(src_ids, dst_ids, num_nodes)

    def test_num_nodes(self):
        ground = 10
        self.assertEqual(self.graph.num_nodes(), ground)

    def test_num_edges(self):
        ground = 14
        self.assertEqual(self.graph.num_edges(), ground)


if __name__ == "__main__":
    unittest.main()
