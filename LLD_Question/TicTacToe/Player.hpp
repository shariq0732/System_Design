#ifndef PLAYER_H
#define PLAYER_H

#include "PlayingPiece/PlayingPieceFactory.hpp"

class Player
{
    string name;
    PlayingPiece* playingPiece;
    public:
        Player();
        Player& operator=(const Player&);
        Player(const Player&);
        Player(string theName, PlayingPiece* thePlayingPiece);
        void setPlayerName(string theName);
        void setPlayingPiece(PlayingPiece *thePlayingPiece);
        string getPlayerName();
        PlayingPiece* getPlayingPiece();

        ~Player();
};  

#endif