#include "Player.hpp"


Player::Player() {}

Player::Player(string theName, PlayingPiece* thePlayingPiece)
{
    this->name = theName;
    this->playingPiece = thePlayingPiece;
}

Player& Player::operator=(const Player& player)
{
    this->name = player.name;
    this->playingPiece = player.playingPiece;

    return *this;
}

Player::Player(const Player& player)
{
    this->name = player.name;
    this->playingPiece = player.playingPiece;
}

Player::~Player()
{
   // delete playingPiece;
}

void Player::setPlayerName(string theName)
{
    this->name = theName;
}

void Player::setPlayingPiece(PlayingPiece *thePlayingPiece)
{
    this->playingPiece = thePlayingPiece;
}

string Player::getPlayerName()
{
    return this->name;
}

PlayingPiece* Player::getPlayingPiece()
{
    return this->playingPiece;
}
