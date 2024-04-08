//
// Created by JoachimWagner on 08.04.2024.
//

#pragma once

namespace atlas::games {

    class Game {

    public:
        virtual ~Game() = default;

        virtual void play() = 0;

    };

}
