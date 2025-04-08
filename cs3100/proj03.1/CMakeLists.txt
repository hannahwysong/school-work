cmake_minimum_required(VERSION 3.30)
project(Project3.1_MultiSets)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project3.2_MultiSets MultiSetTests.cpp
        MultiSet.cpp MultiSet.h
        AVLTree.cpp AVLTree.h)