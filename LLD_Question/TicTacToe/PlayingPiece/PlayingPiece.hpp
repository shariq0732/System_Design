#ifndef PLAYINGPIECE_H
#define PLAYINGPIECE_H

#include <iostream>
#include <string>
using namespace std;

class PlayingPiece
{
    string pieceType;
    
    public:
        PlayingPiece();
        PlayingPiece(string pieceType);
        void setPieceType(string thePieceType);
        string getPieceType();
};

#endif