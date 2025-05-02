#include "TicTacToe.hpp"

TicTacToe::TicTacToe()
{
    initializeGame();
}

void TicTacToe::initializeGame()
{
    cout<<"****************** Welcome to TicTacToe Game ******************" << endl;
    cout<<"Game initalization steps"<<endl;
    cout<<"Enter Game board size" <<endl;
    int n;
    cin>>n;
    this->barod = new Board(n);
    int playersN;
    cout<<"Enter Number of Players..." << endl;
    cin>>playersN;

    while(playersN--)
    {
        cout<<"Enter the Player Name" << endl;
        string playerName;
        cin>>playerName;
        PlayingPiece* piece = PlayingPieceFactory::getPlayingPiece();
        if(piece == nullptr)
        {
            cout<<"Number player can only be equall to total options available for the piece: " << PlayingPieceFactory::getOptionSize() << endl;
            delete this->barod;
            exit(0);
        }
        Player player(playerName, piece);
        this->playerTurn.push_back(player);
        cout<<"done adding"<<endl;
    } 
}

void TicTacToe::startGame()
{
    cout<<"starting Game" << endl;
    while(true)
    {
        Player player = this->playerTurn.front();
        this->playerTurn.pop_front(); 
        if(this->barod->getFreeCells() == 0)
        {
            cout<<"Game is a tie" << endl;
            return;
        }
        this->barod->print();
        cout<<"Player Tunr: " << player.getPlayerName() << endl;
        cout<< "Enter the row & col to fill in block " <<endl;
        int row, col;
        cin>>row>>col;

        int inputValidation = this->barod->isCellFree(row, col);
        if(inputValidation == 0)
        {

            cout<<"Entered input allready contains a piece enter the for box that is empty" << endl;
            this->playerTurn.push_front(player);
            continue;
        } 
        else if(inputValidation == -1)
        {
            cout<<"Entered input is outside the board Try again..." << endl;
            this->playerTurn.push_front(player);
            continue;
        }

        this->barod->addPiece(row, col, player.getPlayingPiece());  

        if(this-> barod->checkWinner(row, col))
        {
            cout<<"Player: "<< player.getPlayerName() <<" has won the game" << endl;
            this->barod->print();
            return;
        }

        this->playerTurn.push_back(player);
    }
}