//
// kitchen.hpp for kitchen in /home/bechad_p/rendu/cpp_plazza/project/kitchen
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Tue Apr  7 14:31:32 2015 Pierre Bechade
// Last update Sun Apr 26 22:40:51 2015 Caltraba Mickael
//

#ifndef __KITCHEN_HPP__
# define __KITCHEN_HPP__

#include <unistd.h>

#include "reception.hpp"
#include "pizza.hpp"
#include "communication.hpp"

class Kitchen
{
public:
  Kitchen(unsigned int nbr, float mult, unsigned int cooks, unsigned int rege, Communication fifoIn, Communication fifoOut);
  ~Kitchen();
  void	run();
  void	findProcess(Pizza pizza);
  void	parserLine(std::string const &line);

private:
  Communication	_in;
  Communication	_out;
  unsigned int	_pipe;
  unsigned int	_free;
  float		_mult;
  unsigned int	_cooks;
  unsigned int	_regen;
};

#endif /* __KITCHEN_HPP__ */
