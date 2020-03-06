#include "data_layer.h"
#include "logic_layer.h"
#include <algorithm>
#include <iostream>
#include <vector>

namespace logic {

    data::game_data best_game(std::vector<data::game_data> games)
    {
        for (auto game : games)
        {
            if (game.rank < 2)
                return game;
        }
        return {0,"",0,0,0,0,0};
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
        if (games.size() % 2 == 0)
        {
            for (unsigned int i = 0 ; i < games.size()/2 ; i++ )
            {
               std::swap(games[i],games[games.size()-i-1]);
            }
        }
        else
        {
            for (unsigned int i = 0 ; i < (games.size()-1)/2 ; i++ )
            {
               std::swap(games[i],games[games.size()-i-1]);
            }
        }
    }

    void set_bay_avg(std::vector<data::game_data>& games)
    {
        int C = 2000;
        float m = 5.5;
        for (auto& game : games)
        {
            game.bay_avg =
                    ( (C * m) + (game.avg_rating * game.num_voters) )  /
                    (C + game.num_voters);
        }
    }

    void sort_list (std::vector<data::game_data>& games, float data::game_data::* name)
    {

        std::sort(games.begin() , games.end(), [&](const data::game_data& lhs, const data::game_data& rhs) {
            return lhs.*name < rhs.*name;
        }
        );
    }

    unsigned int longest_title_length(const std::vector<data::game_data>& games)
    {
        unsigned int max = 0;
        for (auto game : games)
        {
            if (game.title.length() > max)
                max = game.title.length();
        }
        return max;
    }

    stats get_stats(std::vector<data::game_data> games, float data::game_data::* name)
    {
        stats current;

        float min =  99999;
        float max = -99999;
        float mean = 0;

            sort_list(games,name);

            for (auto game : games)
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

    void get_title_lengths(std::vector<data::game_data>& games)
    {
        for (auto& game : games)
        {
            game.title_length = game.title.length();
        }
    }

    void selection_sort(std::vector<data::game_data>& games, float data::game_data::* name)
    {
        unsigned int n = games.size();

        for (unsigned int i = 0 ; i < n-1 ; i++)
        {
            unsigned int index_min = i;

            for (unsigned int k = i+1 ; k < n ; k++)
            {
                if (games[k].*name < games[index_min].*name)
                {
                    index_min = k;
                }
            }
            std::swap(games[index_min],games[i]);
        }
    }

    void bubble_sort(std::vector<data::game_data>& games, float data::game_data::* name)
    {
        unsigned int n = games.size();

        bool didSwap = true;

        while(didSwap)
        {
            didSwap = false;

            for (unsigned int k = 0 ; k < n-1 ; k++)
            {
                if(games[k+1].*name < games[k].*name)
                {
                    didSwap = true;

                    std::swap(games[k],games[k+1]);
                }
            }
        }
    }

    void merge_sort(std::vector<data::game_data>& games, float data::game_data::* name, unsigned int left, unsigned int right)
    {
        if (right - left < 2)
        {
            if (games[left].*name > games[right].*name)
            {
                std::swap(games[left],games[right]);
                return;
            }
        }
        unsigned int middle = (left+right)/2;
        merge_sort(games,name,left,middle);
        middle++;
        merge_sort(games,name,middle,right);

        std::vector<data::game_data> sorted = games;

        unsigned int i = left;

        unsigned int k = middle;

        for (unsigned int n = left ; n < right ; n++)
        {
            if ((games[i].*name < games[k].*name or k > right) and i < middle)
            {
                sorted[n] = games[k];
                k++;
            }
            else
            {
                sorted[n] = games[i];
                i++;
            }
        }
        games = sorted;
    }

}
