//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <iostream>
#include <memory>
#include <thread>
#include "../client/impl/ClientImpl.h";
#include "../generator/impl/random/MersenneTwisterNumberGenerator.h"
#include "../collection/VectorFactoryBuilder.h"

namespace atlas::bootstrap {
    class Bootstrap {
        using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;

        using GENERATOR = std::unique_ptr<generator::Generator<int>>;
        using CLIENT = std::unique_ptr<atlas::client::Client>;


        static GENERATOR createGenerator() {
            GENERATOR generator = std::make_unique<atlas::generator::MersenneTwisterNumberGenerator>();
            return generator;
        }


        static CLIENT createClient(VECTOR_FACTORY factory) {
            CLIENT client = std::make_unique<atlas::client::VectorClientImpl>(std::move(factory));
            return client;
        }



    public:
        void startApplication() {

            auto generator = createGenerator();

            atlas::collection::VectorFactoryBuilder<int>::setBenchmark(true);
            auto vectorFiller = atlas::collection::VectorFactoryBuilder<int>::createWithGenerator(std::move(generator));
            auto client = createClient(std::move(vectorFiller));

            client->doSomethingWithLargeVector();
        }

    };
}
