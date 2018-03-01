//
// plazza.hpp for  in /home/calatr_m/cpp_rendu/CPP/cpp_plazza/project/plazza
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Thu Apr 23 11:28:38 2015 Caltraba Mickael
// Last update Sat Apr 25 21:20:14 2015 Caltraba Mickael
//

#ifndef __PLAZZA_HH__
# define __PLAZZA_HH__

#include <iostream>
#include <bitset>
#include <string>
#include <stdexcept>
#include <cstddef>
#include <vector>

#include "kitchen.hpp"
#include "reception.hpp"
#include "pizza.hpp"

namespace Plazza {
  class Restaurant
  {
  public:
    Restaurant(const int &ac, char **av);
    ~Restaurant();

    float	getMultiplier() const;
    int		getNbCook() const;
    int		getRegenTime() const;

    void	checkParam(const int &ac, char **av);
    void	parseLine() const;

  private:
    std::vector<Kitchen*>	_kitchen;
    float			_multiplier;
    int				_nbCook;
    int				_regenTime;
  };

  int	main(const int &ac, char**av);
  void	invariant_error();
}

#endif /* __PLAZZA_HH__ */
