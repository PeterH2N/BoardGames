#include "presentation_layer.h"
#include "logic_layer.h"
#include <iostream>
#include <iomanip>

namespace presentation
{
    void display_best(const std::vector<data::game_data>& games)
    {
        std::cout << "Best game according to BGG: " << logic::best_game(games).title << std::endl;
    }

    void display(const data::game_data& game, int count,...)
    {
        std::cout << std::setprecision(0)
        << game.rank
        << [&](const data::game_data& game)
        {
            if(game.rank < 10) return "  ";
            else if(game.rank > 9 && game.rank < 100) return " ";
            else return "";
        }(game)
        << std::setprecision(2)
        << " " << game.title;

        va_list args;
        va_start(args,count);

        for (int i = 0 ; i < count ; i++)
        {
            auto name = va_arg(args, float data::game_data::*);

            std::cout
                    << [&](float data::game_data::* name)
                    {
                        if (name == &data::game_data::rank)                 return " Rank: ";
                        else if (name == &data::game_data::avg_rating)      return " Average Rating: ";
                        else if (name == &data::game_data::geek_rating)     return " Geek Rating: ";
                        else if (name == &data::game_data::bay_avg)         return " Bayesian Average: ";
                        else if (name == &data::game_data::num_voters)      return (" Number Of Voters: ");
                        else if (name == &data::game_data::title_length)    return " Title Length: ";
                        return "";
                    }(name)
                    << game.*name;
        }
    }

    void display_list(const std::vector<data::game_data> &games, int count,...)
    {
        std::cout << std::fixed;
        for (auto game : games)
        {
            va_list args;
            va_start(args,count);


            std::cout << std::setprecision(0)
            << static_cast<int>(game.rank)
            << [&](const data::game_data& game)
            {
                if(game.rank < 10) return "  ";
                else if(game.rank > 9 && game.rank < 100) return " ";
                else return "";
            }(game)
            << std::setprecision(2)
            << " " << game.title
            << [&](const std::vector<data::game_data>& games, const data::game_data& game)
               {
                std::string spaces;
                for (unsigned int i = 0 ; i < (logic::longest_title_length(games) - game.title.length()) ; i++)
                {
                    spaces += " ";
                }
                return spaces;
               }(games,game);


            for (int i = 0 ; i < count ; i++)
            {
                auto name = va_arg(args, float data::game_data::*);

                std::cout
                        << [&](float data::game_data::* name)
                        {
                            if (name == &data::game_data::rank) {std::cout<<std::setprecision(0);return " Rank: ";}
                            else if (name == &data::game_data::avg_rating){std::cout<<std::setprecision(2);return " Average Rating: ";}
                            else if (name == &data::game_data::geek_rating){std::cout<<std::setprecision(2);return " Geek Rating: ";}
                            else if (name == &data::game_data::bay_avg){std::cout<<std::setprecision(2);return " Bayesian Average: ";}
                            else if (name == &data::game_data::num_voters){std::cout<<std::setprecision(0);return " Number Of Voters: ";}
                            else if (name == &data::game_data::title_length){std::cout<<std::setprecision(0);return " Title Length: ";}
                            return "";
                        }(name)
                        << game.*name;
            }
            va_end(args);
            std::cout << std::endl;

        }



    }

    void display_list_all(const std::vector<data::game_data>& games)
    {
        std::cout << std::fixed;
        for(const auto& game : games)
        {
            std::cout << std::setprecision(0)
            << game.rank
            << [&](const data::game_data& game)
            {
                if(game.rank < 10) return "  ";
                else if(game.rank > 9 && game.rank < 100) return " ";
                else return "";
            }(game)
            << std::setprecision(2)
            << " " << game.title << make_title_space(games, game)
            << " Geek Rating: " << game.geek_rating
            << ", Avg Rating: " << game.avg_rating
            << std::setprecision(0)
            << ", Number of voters: " << game.num_voters
            << std::setprecision(2)
            << ", Bayesian Avg: " << game.bay_avg
            << std::endl;
        }
    }

    void display_stats(const std::vector<data::game_data>& games, float data::game_data::* name)
    {
        logic::stats stats = logic::get_stats(games,name);
        std::cout << "Statistics for the "
            << [&](float data::game_data::* name)
            {
                if (name == &data::game_data::rank)                 return "rank";
                else if (name == &data::game_data::avg_rating)      return "average rating";
                else if (name == &data::game_data::geek_rating)     return "geek rating";
                else if (name == &data::game_data::bay_avg)         return "Bayesian average";
                else if (name == &data::game_data::num_voters)      return "numbers of voter";
                else if (name == &data::game_data::title_length)    return "title length";
                return "";
            }(name)
        << "s of BGG's list" << std::endl;
        std::cout << "Minimum value: " << stats.min << std::endl;
        std::cout << "Maximum value: " << stats.max << std::endl;
        std::cout << "Mean value:    " << stats.mean << std::endl;
        std::cout << "Median value:  " << stats.median << std::endl;
    }


}
