//
// Created by JoachimWagner on 08.04.2024.
//

#pragma once
#include <iostream>

#include "../Game.h"

namespace atlas::games {
    class NimGame :public Game{
    public:
        NimGame():stones(23), gameover(false) {}
        ~NimGame() override = default;

        void play() override {
            while(! gameover) {
                executeTurns();
            }
        }


    private:
        int stones;
        bool gameover;
        void executeTurns() {
            spielerzug();
            computerzug();

        }


        void spielerzug() {
            int move;
            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3" <<std::endl;
                std::cin >> move;
                if(move >=1 && move <=3) break;
                std::cout << "ungueltiger Zug!" << std::endl;
            }
            stones -= move;
        }

        void computerzug() {
            constexpr int zuege[] = {3,1,1,2};
            int move;

            if(stones < 1) {
                std::cout << "Du Looser!" << std::endl;
                gameover = true;
                return;
            }

            if(stones == 1) {
                std::cout << "Du hast nur Glueck gehabt" << std::endl;
                gameover = true;
                return;
            }

            move = zuege[stones % 4];
            std::cout << "Computer nimmt " << move << " Steine." << std::endl;
            stones -= move;
        }
    };



}
