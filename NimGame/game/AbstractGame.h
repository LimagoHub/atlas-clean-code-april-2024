//
// Created by JoachimWagner on 09.04.2024.
//

#pragma once
#include <vector>
#include "Game.h"
#include "player/Player.h"
#include "../io/Writer.h"

namespace atlas::games {
    template<class BOARD,class MOVE>
    class AbstractGame : public Game{
        using PLAYER = atlas::games::player::Player<BOARD,MOVE>;
    public:
        explicit AbstractGame(io::Writer &writer) : writer(writer) {}

        void play() override {
            while(! isGameOver()) {
                playRound();
            }
        }

        void addPlayer(PLAYER * player) {
            players.push_back(player);
        }

        void removePlayer(PLAYER * player) {
            // TODO implement
        }
    private:
        atlas::io::Writer & writer;
        BOARD board;
        MOVE move;
        PLAYER * currentPlayer;
        std::vector<PLAYER *> players;

          void playRound() {
            for (auto player: players) {
                setCurrentPlayer(player);
                playSingleTurn();
            }
        }
        void playSingleTurn() {

            if(isGameOver()) return;
            prepare();
            executeTurn();
            terminateTurn();
        }


        void executeTurn()  {

            do {
                move = currentPlayer->doTurn(board);
            } while(playersTurnIsInvalid());
        }
        void terminateTurn( ) {// Integration
            updateScene();
            printGameOvermessageIfGameIsOver();
        }


        void printGameOvermessageIfGameIsOver() { // Operation

            if(isGameOver()){
                write( currentPlayer->getName() + " hat verloren");
            }
        }

        bool playersTurnIsInvalid() {
            if(isTurnValid()) return false ;
            write("ungueltiger zug");

            return true;
        }


        void setCurrentPlayer(PLAYER *currentPlayer) {
            AbstractGame::currentPlayer = currentPlayer;
        }


    protected:
        BOARD getBoard() const {
            return board;
        }

        void setBoard(BOARD board) {
            AbstractGame::board = board;
        }

        MOVE getMove() const {
            return move;
        }

        void setMove(MOVE move) {
            AbstractGame::move = move;
        }
        PLAYER *getCurrentPlayer() const {
            return currentPlayer;
        }

        const std::vector<PLAYER *> &getPlayers() const {
            return players;
        }

        void write(std::string message) const{
            writer.write(message);
        }
        virtual bool isGameOver() const = 0;
        virtual void updateScene() = 0;
        virtual bool isTurnValid() const  = 0;
        virtual void prepare() const {
            // Ok
        };
    };
}
