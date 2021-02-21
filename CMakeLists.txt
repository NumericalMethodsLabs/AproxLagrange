cmake_minimum_required(VERSION 3.17)
project(AproxLagrange)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} AproxLagrange.cpp AproxLagrange.h)