//
// Created by JoachimWagner on 09.04.2024.
//

#pragma once
#include <string>
namespace atlas::games::player {
    template<class BOARD, class MOVE>
    class Player {

    public:
        virtual ~Player()= default;

        virtual std::string getName() const = 0;
        virtual MOVE doTurn(const BOARD &board) const = 0;

    };
}
