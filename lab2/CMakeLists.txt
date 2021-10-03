cmake_minimum_required(VERSION 3.16.3)
project(lab2)

set(CMAKE_CXX_STANDARD 11)


add_executable(lab2 
  main.cpp
  octagon.h octagon.cpp
  point.h point.cpp figure.h
  tbinarytree.h tbinarytree.h
)