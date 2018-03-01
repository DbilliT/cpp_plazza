//
// plazza.cpp for plazza in /home/bechad_p/rendu/cpp_plazza/project/plazza
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Tue Apr  7 14:20:56 2015 Pierre Bechade
// Last update Sun Apr 26 13:35:57 2015 Caltraba Mickael
//

#include "plazza.hpp"

void	Plazza::invariant_error()
{
  std::exit(EXIT_FAILURE);
}

Plazza::Restaurant::Restaurant(const int &ac, char **av)
{
  this->checkParam(ac, av);
}
Plazza::Restaurant::~Restaurant()
{
}

float	Plazza::Restaurant::getMultiplier() const {return (this->_multiplier);}
int	Plazza::Restaurant::getNbCook() const {return (this->_nbCook);}
int	Plazza::Restaurant::getRegenTime() const {return (this->_regenTime);}

void	Plazza::Restaurant::checkParam(const int &ac, char **av)
{
  if (ac != 4)
    throw std::invalid_argument("USAGE : ./plazza [MULTIPLIER] [NUMBER_COOKS] [TIME]");
  this->_multiplier = std::stod(av[1]);
  this->_nbCook = std::atoi(av[2]);
  this->_regenTime = std::atoi(av[3]);
  parseLine();
}

void	Plazza::Restaurant::parseLine() const
{
  if (this->_multiplier <= 0)
    throw std::out_of_range("USAGE : 0 < [MULTIPLICATOR].");
  else if (this->_nbCook < 1)
    throw std::out_of_range("USAGE : 1 < [COOK_PER_KITCHEN].");
  else if (this->_regenTime < 0)
    throw std::out_of_range("USAGE : 0 < [REGENERATOR_TIME_INGREDIENT].");
}

int		Plazza::main(const int &ac, char **av)
{
  std::set_terminate(invariant_error);

  try {
    Restaurant	plazza(ac, av);
    Reception	accueil(plazza.getMultiplier(), plazza.getNbCook(), plazza.getRegenTime());
 
    accueil.run();
  }
  catch (std::invalid_argument const &e) {
    std::cerr << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  catch (std::bad_alloc const &e) {
    std::cerr << "Error : Plazza bad alloc." << std::endl;
    return (EXIT_FAILURE);
  }
  catch (std::out_of_range const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  catch (std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
