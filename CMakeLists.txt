cmake_minimum_required(VERSION 3.22)
project(KD_Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(QuadTreeKDTreeComparison KD_Tree main.cpp KDTree.h KDTree.cpp Vector2.h QuadTree.h Box.h)
