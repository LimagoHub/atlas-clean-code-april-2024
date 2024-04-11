//
// Created by JoachimWagner on 11.04.2024.
//

#pragma once
#include <memory>
#include "../../AbstractVectorFactory.h"
#include "../../../generator/GeneratorBuilder.h"
namespace atlas::collection {
    template<class T>
    class VectorFactoryParallelImpl : public AbstractVectorFactory<T>{
        using VECTOR = std::unique_ptr<std::vector<T> >;
        using GENERATOR_BUILDER =  std::unique_ptr<generator::GeneratorBuilder<T>>;
        GENERATOR_BUILDER generatorBuilder_;
        size_t threadCount;

    public:
        VectorFactoryParallelImpl(const GENERATOR_BUILDER generatorBuilder, size_t threadCount) : generatorBuilder_(
                std::move(generatorBuilder)), threadCount(threadCount) {}

    protected:
        auto fill_array() -> void override {

        }
    };
}
