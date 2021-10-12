cmake_minimum_required(VERSION 3.16.3)
project(lab2_test)

set(CMAKE_CXX_STANDARD 11)


add_executable(lab2_test 
  main.cpp
  tbinarytree.h tbinarytree.cpp
  tree_elem.h tree_elem.cpp
)