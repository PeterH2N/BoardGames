#ifndef LOGIC_LAYER_H
#define LOGIC_LAYER_H
#include "data_layer.h"
#include <iostream>
#include <vector>

namespace logic{

    data::game_data best_game(std::vector<data::game_data> obj);

    std::vector<data::game_data> reverse_copylist(const std::vector<data::game_data>& obj);

    void reverse_list(std::vector<data::game_data>& obj);

    void set_bay_avg(std::vector<data::game_data>& obj);

    void sort_list(std::vector<data::game_data>& obj, float data::game_data::* input_member);

    data::stats get_stats(std::vector<data::game_data> obj, float data::game_data::* input_member);
}


#endif // LOGIC_LAYER_H
