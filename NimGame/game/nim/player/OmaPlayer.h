//
// Created by JoachimWagner on 09.04.2024.
//

#pragma once

#include <iostream>
#include <random>

#include "AbstractNimGamePlayer.h"
namespace atlas::games::player {
    class OmaPlayer : public AbstractNimGamePlayer{
    public:
        explicit OmaPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        int doTurn(const int &stones) const override {
            int result = std::rand() % 5 +1;
            std::cout << getName() << " nimmt " << result << " Steine." << std::endl;
            return result;
        }
    };
}
