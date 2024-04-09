//
// Created by JoachimWagner on 09.04.2024.
//

#pragma once

#include "Player.h"

namespace atlas::games::player {

    template<class BOARD, class MOVE>
    class AbstractPlayer: public Player<BOARD,MOVE> {
        std::string name;

    public:
        explicit AbstractPlayer(const std::string &name) : name(name) {}

        std::string getName() const override {
            return name;
        }
    };
}
