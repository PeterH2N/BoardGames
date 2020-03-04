#ifndef DATA_LAYER_H
#define DATA_LAYER_H

#include <string>
#include <vector>

namespace data
{

struct game_data
{
public:
    float rank;
    std::string title;
    float geek_rating;
    float avg_rating;
    float num_voters;
    float bay_avg;
};

class stats
{
public:
    float min;
    float max;
    float mean;
    float median;
};

std::vector<game_data> get_games_from_file();

}

#endif // DATA_LAYER_H
