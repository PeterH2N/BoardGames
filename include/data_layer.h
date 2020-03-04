#ifndef DATA_LAYER_H
#define DATA_LAYER_H

#include <string>
#include <vector>

namespace data
{

class game_data
{
public:
    int rank;
    std::string title;
    float geek_rating;
    float avg_rating;
    int num_voters;
    float bay_avg;

    float return_type(std::string type);

    static bool sort_by_rank( const game_data& g1, const game_data& g2 );

    static bool sort_by_geek_rating( const game_data& g1, const game_data& g2 );

    static bool sort_by_avg_rating( const game_data& g1, const game_data& g2 );

    static bool sort_by_num_voters( const game_data& g1, const game_data& g2 );

    static bool sort_by_bay_avg( const game_data& g1, const game_data& g2 );

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
