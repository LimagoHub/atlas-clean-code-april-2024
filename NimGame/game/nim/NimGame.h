//
// Created by JoachimWagner on 08.04.2024.
//

#pragma once
#include <iostream>

#include "../Game.h"

namespace atlas::games {
    class NimGame :public Game{
    public:
        NimGame():stones(23) {}
        ~NimGame() override = default;

        void play() override {
            while(! isGameOver()) {
                playRounds();
            }
        }


    private:
        int stones;
        int move;

        void playRounds() {
            spielerzug();
            computerzug();

        }


        void spielerzug() {

            if(isGameOver()) return;

            int move;
            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3" <<std::endl;
                std::cin >> move;
                if(move >=1 && move <=3) break;
                std::cout << "ungueltiger Zug!" << std::endl;
            }
            terminateTurn("Human");
        }

        void computerzug() {

            if(isGameOver()) return;

            constexpr int zuege[] = {3,1,1,2};


            move = zuege[stones % 4];
            std::cout << "Computer nimmt " << move << " Steine." << std::endl;

            terminateTurn("Computer");

        }

        void terminateTurn( std::string player) {// Integration
            updateScene();
            printGameOvermessageIfGameIsOver(player);
        }

        void printGameOvermessageIfGameIsOver(const std::string &player) { // Operation

            if(isGameOver()){
                std::cout << player << " hat verloren" << std::endl;
            }
        }

        void updateScene() { stones -= move; }

        bool isGameOver() {
            return stones < 1;
        }
    };



}
