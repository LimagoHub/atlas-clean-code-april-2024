cmake_minimum_required(VERSION 3.25)
project(VectorFillerUebung)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorFillerUebung main.cpp time/Stopwatch.h generator/Generator.h generator/NumberGenerator.h collection/VectorFactory.h client/Client.h bootstrap/Bootstrap.h)
