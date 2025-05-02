#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Board.hpp"
#include "Player.hpp"
#include "PlayingPiece/PlayingPieceFactory.hpp"
#include <deque>
using namespace std;

class TicTacToe
{   
    Board *barod;
    deque<Player> playerTurn;
    void initializeGame();
    public:

        TicTacToe();
        void startGame();
};

#endif