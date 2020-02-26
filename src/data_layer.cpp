#include "data_layer.h"
#include <fstream>  // filestream
#include <algorithm>

namespace data
{

std::vector<std::string> get_games_from_file()
{
    using namespace std;
    vector<string> games;
    vector<int> ranking;
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

        for(int i = 0; next > 0; i++ )
        {
            // Get the next word and update indices to next word
            word = line.substr(current,next-current);
            current = next+1;
            next = line.find(';',current);

            // Push current word to corresponding vector
            switch(i)
            {
            case 0:
                ranking.push_back(stoi(word));  // stoi is String TO Int
                break;
            case 1:
                games.push_back(word);
                break;
            }
        }
    }

    return games;
}

}
