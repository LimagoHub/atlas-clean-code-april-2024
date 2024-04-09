//
// Created by JoachimWagner on 09.04.2024.
//

#pragma once


#include <iostream>
#include "AbstractNimGamePlayer.h"
namespace atlas::games::player {
    class ComputerPlayer : public AbstractNimGamePlayer{
        inline static const int zuege[] = {3,1,1,2};
    public:
        explicit ComputerPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        [[nodiscard]] int doTurn(const int &stones) const override {


            const auto result = zuege[stones % 4];
            std::cout << getName() << " nimmt " << result << " Steine." << std::endl;
            return result;
        }
    };
}
