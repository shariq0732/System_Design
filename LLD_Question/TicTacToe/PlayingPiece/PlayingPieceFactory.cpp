#include "PlayingPieceFactory.hpp"


map<string, bool> PlayingPieceFactory::optionsMap;

PlayingPieceFactory::PlayingPieceFactory(){
    vector<string> options = {"X", "$", "O"};

    for(auto it : options)
    {
        this->optionsMap[it] = true;
    }
}

string PlayingPieceFactory::getInputFromUser()
{
    string choosenOption = "";
    while(true)
    {
        cout<< "Enter the option from avialble option..." << endl;
        int optionCounter = 0;
        for(auto it : optionsMap)
        {
            if(it.second == true)
            {
                cout<<optionCounter++ << " " << it.first << endl;
            }
        }

        if(optionCounter == 0)
        {
            cout<<"All the option has been used there is no option available" << endl;
            return "";
        }

        string option;
        cin>> option;

        if(optionsMap.find(option) == optionsMap.end())
        {
            cout<< "Invalied Option" << endl;
            cout<< "Enter a valied option from the option's list" << endl << endl;
            continue;
        }
        else
        {
            optionsMap[option] = false;
            choosenOption = option;
            break;
        }
    }
    return choosenOption;
}

PlayingPiece* PlayingPieceFactory::getPlayingPiece()
{
    static PlayingPieceFactory factory;
    string userInput = getInputFromUser();
    PlayingPiece *playingPiece = nullptr;
    
    if("X" == userInput)
    {
        playingPiece = new CrossPlayingPiece();
    }
    else if("O" == userInput)
    {
        playingPiece = new NugetPlayingPiece();
    }
    else if("$" == userInput)
    {
        playingPiece = new DollerPlayingPiece();
    }
    
    return playingPiece;
}

int PlayingPieceFactory::getOptionSize()
{
    return optionsMap.size();
}