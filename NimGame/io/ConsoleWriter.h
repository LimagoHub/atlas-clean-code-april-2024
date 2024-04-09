//
// Created by JoachimWagner on 09.04.2024.
//

#pragma once

#include <iostream>
#include "Writer.h"
namespace atlas::io {
    class ConsoleWriter: public Writer{
    public:
        ~ConsoleWriter() override = default;

        void write(std::string message) const override {
            std::cout << message << std::endl;
        }
    };
}
