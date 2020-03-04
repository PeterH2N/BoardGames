#include <vector>
#include <string>
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

        logic::sort_list(games, &data::game_data::rank);

        presentation::display_list_bay_avg(games);

        presentation::display_best(games);

        presentation::display_stats(logic::get_stats(games, &data::game_data::bay_avg), "Bayesian Average");



    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }


    return 0;
}
