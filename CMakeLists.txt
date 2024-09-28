cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project(logging VERSION 0.1.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC src/logging.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)
