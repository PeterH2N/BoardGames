#include "data_layer.h"
#include <algorithm>
#include <iostream>
#include <vector>

namespace logic {

    data::game_data best_game(std::vector<data::game_data> games)
    {
        for (data::game_data game : games)
        {
            if (game.rank < 2)
                return game;
        }
        return {0,"",0,0,0,0};
    }

    std::vector<data::game_data> reverse_copylist(const std::vector<data::game_data>& games)
    {
        std::vector<data::game_data> list;
        for ( unsigned int i = 0 ; i < games.size() ; i++ )
        {
            list.push_back(games[games.size()-i-1]);
        }
        return list;
    }

    void reverse_list(std::vector<data::game_data>& games)
    {
        for (unsigned int i = 0 ; i < games.size()/2 ; i++ )
        {
            std::swap(games[i],games[games.size()-i-1]);
        }
    }

    void set_bay_avg(std::vector<data::game_data>& games)
    {
        int C = 2000;
        float m = 5.5;
        for (data::game_data& game : games)
        {
            game.bay_avg =
                    ( (C * m) + (game.avg_rating * game.num_voters) )  /
                    (C + game.num_voters);
        }
    }

    void sort_list (std::vector<data::game_data>& games, float data::game_data::* name)
    {
        std::sort(games.begin() , games.end(), [&name](const data::game_data& lhs, const data::game_data& rhs) {
            return lhs.*name < rhs.*name;
        });
    }

    data::stats get_stats(std::vector<data::game_data> games, float data::game_data::* name)
    {
        data::stats current;

        float min =  99999;
        float max = -99999;
        float mean = 0;

            sort_list(games,name);

            for (data::game_data game : games)
            {
                if (game.*name < min)
                    min = game.*name;
                if (game.*name > max)
                    max = game.*name;

                mean += game.*name;
            }

            current.min = min;
            current.max = max;
            current.mean = mean/games.size();

            //calculates mean, checks whether size of list is even or odd
            if (games.size() % 2 == 0)
            {
                //returns the average of the two middle values.
                current.median = (games[games.size() / 2].*name + games[games.size() / 2].*name) / 2;
            }
            else
            {
                //returns the middle value.
                current.median = games[ ((games.size() - 1) / 2) + 1].*name;
            }


        return current;
    }

}
