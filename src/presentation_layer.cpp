//#include "presentation_layer.h"
#include "logic_layer.h"
#include <iostream>

namespace presentation
{

void display_best(const std::vector<data::game_data>& games)
{
    std::cout << "Best game according to BGG: " << logic::best_game(games).title << std::endl;
}

void display_list_all(const std::vector<data::game_data>& games)
{
    for(const data::game_data& game : games){
        std::cout << game.rank
        << " " << game.title
        << ", Geek Rating: " << game.geek_rating
        << ", Avg Rating: " << game.avg_rating
        << ", Number of voters: " << game.num_voters
        << ", Bayesian Avg: " << game.bay_avg
        << std::endl;
    }
}
void display_list_avg(const std::vector<data::game_data>& games)
{
    for(const data::game_data& game : games){
        std::cout << game.title << " Avg Rating: " << game.avg_rating << std::endl;
    }
}

void display_list_bay_avg(const std::vector<data::game_data>& games)
{

    for(const data::game_data& game : games){
        std::cout << game.title << " Bay Avg Rating: " << game.bay_avg << std::endl;
    }
}


}
