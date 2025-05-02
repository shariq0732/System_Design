#include "PlayingPiece.hpp"

PlayingPiece::PlayingPiece()
{
    this->pieceType = "";
}

PlayingPiece::PlayingPiece(string pieceType): pieceType(pieceType) {}

void PlayingPiece::setPieceType(string thePieceType)
{
    this->pieceType = pieceType;
}

string PlayingPiece::getPieceType()
{
    return this->pieceType;
}