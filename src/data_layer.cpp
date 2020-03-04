#include "data_layer.h"
#include <fstream>  // filestream
#include <algorithm>

namespace data
{
float game_data::return_type(std::string type)
{
    if (type == "rank")
        return rank;
    else if (type == "geek_rating")
        return geek_rating;
    else if (type == "avg_rating")
        return avg_rating;
    else if (type == "num_voters")
        return num_voters;
    else if (type == "bay_avg")
        return bay_avg;
    else
        return 0;
}

bool game_data::sort_by_rank( const game_data& g1, const game_data& g2 )
{
        return( g1.rank > g2.rank);
}

bool game_data::sort_by_geek_rating( const game_data& g1, const game_data& g2 )
{
        return( g1.geek_rating > g2.geek_rating);
}

bool game_data::sort_by_avg_rating( const game_data& g1, const game_data& g2 )
{
        return( g1.avg_rating > g2.avg_rating);
}

bool game_data::sort_by_num_voters( const game_data& g1, const game_data& g2 )
{
        return( g1.num_voters > g2.num_voters);
}

bool game_data::sort_by_bay_avg( const game_data& g1, const game_data& g2 )
{
        return( g1.bay_avg > g2.bay_avg);
}


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
