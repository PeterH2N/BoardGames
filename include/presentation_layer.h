#ifndef PRESENTATION_LAYER_H
#define PRESENTATION_LAYER_H

#include "data_layer.h"

#include <vector>
#include <string>

namespace presentation
{
void display_best(const std::vector<data::game_data>& input);

void display_list_all(const std::vector<data::game_data>& input);

void display_list_avg(const std::vector<data::game_data>& input);

void display_list_bay_avg(const std::vector<data::game_data>& input);
}



#endif // PRESENTATION_LAYER_H
