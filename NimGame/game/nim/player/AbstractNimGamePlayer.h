//
// Created by JoachimWagner on 09.04.2024.
//

#pragma once

#include "../../player/AbstractPlayer.h"

namespace atlas::games::player {

    class AbstractNimGamePlayer : public AbstractPlayer<int, int> {


    public:
        AbstractNimGamePlayer(const std::string &name) : AbstractPlayer(name) {}
    };
}
