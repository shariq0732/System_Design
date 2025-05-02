#ifndef PLAYINGPIECEFACTORY_H
#define PLAYINGPIECEFACTORY_H

#include "CrossPlayingPiece.hpp"
#include "NugetPlayingPiece.hpp"
#include "DollerPlayingPiece.hpp"
#include <map>
#include <vector>
using namespace std;

class PlayingPieceFactory
{
    static map<string, bool> optionsMap;
    public:
        PlayingPieceFactory();
        static PlayingPiece* getPlayingPiece();
        static string getInputFromUser();
        static int getOptionSize();
};

#endif