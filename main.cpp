#include <iostream>
#include "data_layer.h"
#include "presentation_layer.h"
#include "logic_layer.h"
using namespace std;

int main()
{
        vector<data::game_data> games = data::get_games_from_file();

    try
    {
        logic::set_bay_avg(games);

        logic::get_title_lengths(games);

        logic::sort_list(games, &data::game_data::title_length);

        presentation::display_best(games);

        presentation::display_stats(games, &data::game_data::bay_avg);

        presentation::display_list(games,3,&data::game_data::bay_avg, &data::game_data::avg_rating, &data::game_data::num_voters);
    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}
