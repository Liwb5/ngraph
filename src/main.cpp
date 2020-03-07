#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <stdint.h>
#include "class.h"
#include "graph.h"


using namespace std;
namespace py = pybind11;

void print_dict(py::dict dict) {
    /* Easily interact with Python types */
    for (auto item : dict)
        std::cout << "key=" << std::string(py::str(item.first)) << ", "
                  << "value=" << std::string(py::str(item.second)) << std::endl;
}

void print_vector(const std::vector<int> &v) {
    for (auto item : v)
        std::cout << item << "\n";
}

PYBIND11_MODULE(ngraph, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: ngraph

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    py::class_<Graph>(m, "Graph")
        .def(py::init<IdArray, IdArray, uint64_t>())
        .def("num_edges", &Graph::num_edges);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
