cmake_minimum_required(VERSION 3.18)
project(
  RestMyCase
  VERSION 1.0.0
  LANGUAGES CXX)
add_library(RestMyCase INTERFACE)
target_sources(RestMyCase INTERFACE "RestMyCase/rest_my_case.hpp")
target_include_directories(RestMyCase INTERFACE ".")
target_compile_features(RestMyCase INTERFACE cxx_std_20)
