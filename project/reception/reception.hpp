//
// reception.hpp for  in /home/calatr_m/cpp_rendu/CPP/cpp_plazza/project/reception
// 
// Made by Caltraba Mickael
// Login   <calatr_m@epitech.net>
// 
// Started on  Thu Apr 23 11:47:22 2015 Caltraba Mickael
// Last update Sun Apr 26 22:46:14 2015 Caltraba Mickael
//

#ifndef __RECEPTION_HPP__
# define __RECEPTION_HPP__

#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <locale>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp> 
#include "pizza.hpp"
#include "communication.hpp"

class Reception
{
public:
  Reception(float mult, unsigned int nbCook, unsigned int time);
  Reception();
  ~Reception();

  void		stop();
  void		run();
  void		createKitchen(unsigned int id);
  void		findKitchen();
  std::string	readCommand() const;

  void		parseLine(std::string const &line);
  void		parsePizza(std::string const &type, Pizza &pizza) const;
  void		parseSize(std::string const &size, Pizza &pizza) const;
  unsigned int	parseNumbers(std::string const &nb) const;

private:
  std::map<std::string, TypePizza>      _mapType;
  std::map<std::string, TaillePizza>    _mapSize;
  std::queue<Pizza>	 		_comand;
  std::list<std::pair<Communication, Communication> >		_fifo;

protected:  
  float					_multiplier;
  int					_nbCooks;
  int					_timeRegen;
};

#endif /* __RECEPTION_HPP__ */
