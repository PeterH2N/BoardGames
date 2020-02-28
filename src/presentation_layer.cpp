#include "presentation_layer.h"
#include "logic_layer.h"
#include <iostream>

namespace presentation
{

void display_best(std::vector<data::game_data> games)
{
    std::cout << "Best game according to BGG: " << logic::best_game(games).title << std::endl;
}

void display_list_all(const std::vector<data::game_data>& games)
{
    for(const data::game_data& game : games){
        std::cout << game.rank << " " << game.title << " Geek Rating: " << game.geek_rating << " Avg Rating: " << game.avg_rating <<std::endl;
    }
}

}
