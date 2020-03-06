#ifndef DATA_LAYER_H
#define DATA_LAYER_H

#include <string>
#include <vector>

namespace data
{

class game_data
{
public:
    float rank;
    std::string title;
    float geek_rating;
    float avg_rating;
    float num_voters;
    float bay_avg;
    float title_length;
};



std::vector<game_data> get_games_from_file();

}

#endif // DATA_LAYER_H
