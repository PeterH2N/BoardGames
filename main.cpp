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

        logic::reverse_list(games);

        logic::sort_list(games,"bay_avg");

        presentation::display_list_all(games);

        presentation::display_best(games);



    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }


    return 0;
}
