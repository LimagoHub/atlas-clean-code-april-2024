//
// Created by JoachimWagner on 09.04.2024.
//

#pragma once
#include <string>
namespace atlas::io {

    class Writer {
    public:
        virtual ~Writer() = default;
        virtual void write(std::string &message) const = 0;
    };
}
