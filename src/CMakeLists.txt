cmake_minimum_required(VERSION 3.12)
project(my_module)

set(CMAKE_CXX_STANDARD 11)

# Configuration de PyBind11
add_subdirectory(pybind11)

# Ajoutez le chemin vers les fichiers C++ source
include_directories(src/c++)

# Liste des fichiers C++ à compiler
set(SRC_CPP_FILES
    src/c++/my_functions.cpp
    # Ajoutez d'autres fichiers C++ au besoin
)

# Création de la bibliothèque C++
add_library(my_module_cpp ${SRC_CPP_FILES})

# Lien avec PyBind11
target_link_libraries(my_module_cpp PRIVATE pybind11::module)

# Configuration de l'extension Python
pybind11_add_module(my_module src/python/bindings.cpp)
target_link_libraries(my_module PRIVATE my_module_cpp)
