//
// Created by JoachimWagner on 08.04.2024.
//

#pragma once
#include <vector>

#include "../AbstractGame.h"

#include "../../io/Writer.h"

namespace atlas::games {
    class NimGame :public AbstractGame<int,int>{



    public:
        explicit NimGame(io::Writer &writer) : AbstractGame(writer) {
            setBoard(23);
        }

        ~NimGame() override = default;

    protected:
        bool isGameOver()  const override{
            return getBoard() < 1 || getPlayers().empty();
        }

        void updateScene() override{ setBoard(getBoard() - getMove()) ;}



        bool isTurnValid() const override{
            return getMove() >= 1 && getMove() <= 3;
        }

        void prepare() const override {
            write(getCurrentPlayer()->getName() + " ist am Zug.");
        }
    };



}
