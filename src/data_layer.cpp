#include "data_layer.h"
#include <fstream>  // filestream
#include <algorithm>

namespace data
{

std::vector<game_data> get_games_from_file()
{

    using namespace std;

    vector<game_data> games;
    string line, word;
    int current = -1;
    int next = 0;




    // Open file
    string filename = "data/top100bgg.csv";
    ifstream file(filename);
    if(!file)
    {
        throw runtime_error("Error - Couldn't open file: " + filename);
    }

    // Skip first line (titles). Then read every line after.
    getline(file, line);
    while(getline(file, line))
    {
        // Initialize current index in string and find first delimiter ";"
        current = 0;
        next = line.find(';');

        game_data current_game;

        for(int i = 0; i <= 4 ; i++ )
        {

            // Get the next word and update indices to next word
            word = line.substr(current,next-current);
            current = next+1;
            next = line.find(';',current);

            // Push current word to corresponding variable
            switch(i)
            {
            case 0:
                current_game.rank = (stoi(word));  // stoi is String TO Int
                break;
            case 1:
                current_game.title = (word);
                break;
            case 2:
                current_game.geek_rating = (stof(word)); // stof is String TO Floa
                break;
            case 3:
                current_game.avg_rating = (stof(word));
                break;
            case 4:
                current_game.num_voters = (stoi(word));
            }
        }
        //push the current game back
        games.push_back(current_game);
    }

    return games;
}

}
