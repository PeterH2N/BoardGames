#ifndef LOGIC_LAYER_H
#define LOGIC_LAYER_H
#include "data_layer.h"
#include <iostream>
#include <vector>

namespace logic{

    class stats
    {
    public:
        float min;
        float max;
        float mean;
        float median;
    };

    data::game_data best_game(std::vector<data::game_data> objs);

    std::vector<data::game_data> reverse_copylist(const std::vector<data::game_data>& objs);

    void reverse_list(std::vector<data::game_data>& objs);

    void set_bay_avg(std::vector<data::game_data>& objs);

    void sort_list(std::vector<data::game_data>& obsj, float data::game_data::* obj_member);

    stats get_stats(std::vector<data::game_data> objs, float data::game_data::* obj_member);

    void get_title_lengths(std::vector<data::game_data>& objs);

    unsigned int longest_title_length(const std::vector<data::game_data>& obj);

    void selection_sort(std::vector<data::game_data>& objs, float data::game_data::* obj_member);

    void bubble_sort(std::vector<data::game_data>& objs, float data::game_data::* obj_member);

    void merge_sort(std::vector<data::game_data>& objs, float data::game_data::* obj_member, unsigned int left, unsigned int right);
}


#endif // LOGIC_LAYER_H
