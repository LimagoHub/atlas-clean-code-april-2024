//
// Created by JoachimWagner on 08.04.2024.
//

#pragma once
#include "../game/Game.h"

using namespace atlas::games;

namespace atlas::clients {
    class GameClient {

            Game & game;

    public:
        explicit GameClient(Game &game) : game(game) {}

        void run() {
            game.play();
        }
    };
}
