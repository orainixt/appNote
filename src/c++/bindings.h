#ifndef BINDINGS_H
#define BINDINGS_h

#include <pybind11/pybind11.h>

void bind_my_module(pybind11::module& m);

PYBIND11_MODULE(functions, m) {
    bind_my_module(m);
}

#endif