#include "Board.hpp"

Board::Board(int size)
{
    this->size = size;
    playingPiece = new PlayingPiece*[size];
    
    for(int i = 0; i < size; i++)
    {
        playingPiece[i] = new PlayingPiece[size];
    }
}


Board::~Board()
{
    for(int i = 0 ; i < size; i++)
    {
        delete []playingPiece[i];
    }
    delete []playingPiece;
}


void Board::addPiece(int row, int col, PlayingPiece* Piece)
{
    playingPiece[row][col] = *Piece;
}

bool Board::checkWinner(int row, int col)
{
    string piece = playingPiece[row][col].getPieceType();
    bool brow = true;
    bool bcol = true;
    bool bdiag = true;
    for(int index = 0; index < size; index++)
    {
        if(playingPiece[row][index].getPieceType() != piece)
        {
            bcol = false;
        }

        if(playingPiece[index][col].getPieceType() != piece)
        {
            brow = false;
        }

        if(row == col && playingPiece[index][index].getPieceType() != piece)
        {
            bdiag = false;
        }
    }

    if(row != col)
        bdiag = false;


    int count = 0;
    int upRow = row;
    int upCol = col;
    bool anotherDiag = true;
    while(upRow >= 0 && upCol < size)
    {
        count++;
        if(playingPiece[upRow][upCol].getPieceType() != piece)
        {
            anotherDiag = false;
        }
        upRow--;
        upCol++;
    }


    upRow = ++row;
    upCol = --col;
    while (upRow < size && upCol >= 0)
    {
        count++;
        if(playingPiece[upRow][upCol].getPieceType() != piece)
        {
            anotherDiag = false;
        }
        upRow++;
        upCol--;
    }
    
    bool considerAnotherDiag = false;
    if(count == size)
    {
        considerAnotherDiag = anotherDiag;
    }

    return brow | bcol | bdiag | considerAnotherDiag;
}

int Board::getFreeCells()
{
    int freeCellsCount = 0;
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            if(this->playingPiece[row][col].getPieceType() == "")
            {
                freeCellsCount++;
            }
        }
    }

    return freeCellsCount;
}

void Board::print()
{
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {
            string piece = playingPiece[row][col].getPieceType() == ""? " " : playingPiece[row][col].getPieceType();
            if(col == 0)
            {
                cout<< "  " << piece << " |";
            }
            else if(col == (size - 1))
            {
                cout<<"| " << piece << "  ";
            }
            else
            {
                cout<<"  " << piece<< "  ";
            }
        }
        cout<<endl;
    }
}

int Board::isCellFree(int row, int col)
{
    if(row < size && col < size)
    {
        if(this->playingPiece[row][col].getPieceType() == "")
            return 1;
        return 0;
    }
    return -1;
}