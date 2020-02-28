#include <vector>
#include <string>
#include <iostream>
#include "data_layer.h"
#include "presentation_layer.h"
using namespace std;

int main()
{
        vector<data::game_data> games = data::get_games_from_file();
    try
    {
        presentation::display_best(games);

        presentation::display_list_all(games);

    }
    catch(exception& e)
    {
        cerr << e.what() << endl;
    }


    return 0;
}
