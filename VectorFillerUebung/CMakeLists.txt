cmake_minimum_required(VERSION 3.25)
project(VectorFillerUebung)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorFillerUebung main.cpp time/Stopwatch.h generator/Generator.h generator/IntGenerator.h collection/VectorFactory.h client/Client.h bootstrap/Bootstrap.h time/impl/StopwatchImpl.h generator/impl/random/MersenneTwisterNumberGenerator.h collection/AbstractVectorFactory.h collection/impl/sequential/VectorFactorySequentialImpl.h collection/impl/decorators/AbstractVectorFactoryDecorator.h collection/impl/decorators/VectorFactoryBenchmarkDecorator.h collection/VectorFactoryBuilder.h client/impl/ClientImpl.h generator/impl/random/MersenneTwisterNumberGeneratorFactory.h generator/GeneratorBuilder.h collection/impl/parallel/VectorFactoryParallelImpl.h)
