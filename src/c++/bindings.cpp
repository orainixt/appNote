#include <pybind11/pybind11.h>
#include "fcts.cpp"  // Remplacez par le nom de votre fichier C++

void bind_my_module(pybind11::module& m) {
    m.def("get_notes", &getNotes, "Get note");
    m.def("add_notes", &addNote, "Add a note");
    m.def("search_notes", &searchNote, "Search a note");
    m.def("create_note", &createNote, "Create a note");
}