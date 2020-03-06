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

    // Open file
    string filename = "data/top100bgg.csv";
    ifstream file(filename);
    if(!file)
    {
        throw runtime_error("Error - Couldn't open file: " + filename);
    }

    // Skip first line (titles). Then read every line after.
    getline(file, line);
    while(!file.eof())
    {
        data::game_data current_game;

        getline(file, word, ';');
            current_game.rank = stoi(word);
        getline(file, current_game.title,';');

        getline(file,word,';');
            current_game.geek_rating = (stof(word));
        getline(file,word,';');
            current_game.avg_rating = (stof(word));
        getline(file,word,'\n');
            current_game.num_voters = (stoi(word));

        //push the current game back
        games.push_back(current_game);
    }

    return games;
}

}
