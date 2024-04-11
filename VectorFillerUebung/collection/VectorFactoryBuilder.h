//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <iostream>
#include "VectorFactory.h"
#include "impl/sequential/VectorFactorySequentialImpl.h"
#include "impl/parallel/VectorFactoryParallelImpl.h"
#include "impl/decorators/VectorFactoryBenchmarkDecorator.h"
#include "../generator/GeneratorBuilder.h"

namespace atlas::collection {
    template<class T>
    class VectorFactoryBuilder {

        using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;
        using VECTOR_FACTORY_SEQUENCIAL = atlas::collection::VectorFactorySequentialImpl<int>;
        using VECTOR_FACTORY_PARALLEL = atlas::collection::VectorFactoryParallelImpl<int>;
        using VECTOR_FACTORY_BENCHMARK = atlas::collection::VectorFactoryBenchmarkDecorator<int>;
        using GENERATOR_BUILDER = std::unique_ptr<generator::GeneratorBuilder<int>>;

        inline static bool benchmark{false};
        inline static size_t threadCount{1};

    public:
        static bool isBenchmark() {
            return benchmark;
        }

        static void setBenchmark(bool benchmark) {
            VectorFactoryBuilder::benchmark = benchmark;
        }

        static size_t getThreadCount() {
            return threadCount;
        }

        static void setThreadCount(size_t threadCount) {
            VectorFactoryBuilder::threadCount = threadCount;
        }

        static VECTOR_FACTORY createWithGeneratorBuilder(GENERATOR_BUILDER generatorBuilder) {
            VECTOR_FACTORY result;

            switch(threadCount) {
                case 1:
                    result = std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(generatorBuilder->create()));
                    break;
                default:
                    result = std::make_unique<VECTOR_FACTORY_PARALLEL>(std::move(generatorBuilder), threadCount);
                    break;

            }




            if(benchmark) result = std::make_unique<VECTOR_FACTORY_BENCHMARK>(std::move(result));
            return result;
        }
    };
}
