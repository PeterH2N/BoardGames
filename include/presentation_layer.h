#ifndef PRESENTATION_LAYER_H
#define PRESENTATION_LAYER_H

#include "data_layer.h"
#include "logic_layer.h"

#include <vector>
#include <string>
#include <cstdarg>
#include <typeinfo>

namespace presentation
{
    void display_best(const std::vector<data::game_data>& obj);

    void display_list_all(const std::vector<data::game_data>& obj);

    void display_stats(const std::vector<data::game_data>& objs, float data::game_data::* obj_member);

    void display(const data::game_data& obj, int count,...);

    void display_list(const std::vector<data::game_data>& objs, int count,...);
}



#endif // PRESENTATION_LAYER_H
