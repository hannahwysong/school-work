cmake_minimum_required(VERSION 3.30)
project(hashtable)

set(CMAKE_CXX_STANDARD 20)

add_executable(hashTableTests HashTableTests.cpp
        Hashtable.cpp)