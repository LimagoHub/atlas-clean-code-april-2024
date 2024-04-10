//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h";
#include "../generator/impl/random/MersenneTwisterNumberGenerator.h"
#include "../collection/impl/sequential/VectorFactorySequentialImpl.h"
#include "../collection/impl/decorators//VectorFactoryBenchmarkDecorator.h"

namespace atlas::bootstrap {
    class Bootstrap {
        using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;
        using VECTOR_FACTORY_SEQUENCIAL = atlas::collection::VectorFactorySequentialImpl<int>;
        using VECTOR_FACTORY_BENCHMARK = atlas::collection::VectorFactoryBenchmarkDecorator<int>;
        using GENERATOR = std::unique_ptr<generator::Generator<int>>;
        using CLIENT = std::unique_ptr<atlas::client::Client>;


        static GENERATOR createGenerator() {
            GENERATOR generator = std::make_unique<atlas::generator::MersenneTwisterNumberGenerator>();
            return generator;
        }

        static VECTOR_FACTORY createVectorFactory(GENERATOR generator) {
            VECTOR_FACTORY result;
            result = std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(generator));
            result = std::make_unique<VECTOR_FACTORY_BENCHMARK>(std::move(result));
            return result;
        }

        static CLIENT createClient(VECTOR_FACTORY factory) {
            CLIENT client = std::make_unique<atlas::client::VectorClientImpl>(std::move(factory));
            return client;
        }



    public:
        void startApplication() {

            auto generator = createGenerator();
            auto vectorFiller = createVectorFactory(std::move(generator));
            auto client = createClient(std::move(vectorFiller));

            client->doSomethingWithLargeVector();
        }

    };
}
