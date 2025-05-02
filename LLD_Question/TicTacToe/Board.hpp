#ifndef BOARD_H
#define BOARD_H

#include "PlayingPiece/CrossPlayingPiece.hpp"
#include "PlayingPiece/NugetPlayingPiece.hpp"
#include "PlayingPiece/DollerPlayingPiece.hpp"
using namespace std;

class Board
{
    int size;
    PlayingPiece **playingPiece;

    public:
        Board(int size);
        void addPiece(int row, int col, PlayingPiece* Piece);
        bool checkWinner(int row, int col);
        int getFreeCells();
        void print();
        int isCellFree(int row, int col);
        ~Board();
};

#endif