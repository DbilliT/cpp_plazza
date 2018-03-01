//
// kitchen.cpp for kitchen in /home/bechad_p/rendu/cpp_plazza/project/kitchen
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Tue Apr  7 14:32:38 2015 Pierre Bechade
// Last update Sun Apr 26 22:40:56 2015 Caltraba Mickael
//

#include "kitchen.hpp"

Kitchen::Kitchen(unsigned int nbr, float mult, unsigned int cooks, unsigned int rege, Communication fifoIn, Communication fifoOut) :
  _in(fifoIn),
  _out(fifoOut),
  _pipe(nbr),
  _free(cooks * 2),
  _mult(mult),
  _cooks(cooks),
  _regen(rege)
{
  this->run();
}
Kitchen::~Kitchen()
{
}

void	Kitchen::run()
{
  bool			run = true;
  std::stringstream	ss;

  usleep(50000);
  while(run)
    {
      std::string		tmp(this->_in.in());
      ss << this->_free;
      if (tmp == "free")
	this->_out.out(ss.str());
      else if (this->_free > 0)
	{
	  std::cout << "Je recoi une pizza : " << tmp  << std::endl;
	  parserLine(tmp);
	}
      ss.str("");
      ss.clear();
    }
}

void	Kitchen::findProcess(Pizza pizza)
{
  (void)pizza;
  this->_free -= 1;
}

void	Kitchen::parserLine(std::string const &line)
{
  std::istringstream	clean(line);
  int			type;
  int			size;
  Pizza			pizza(Regina, S, 1);
  
  clean >> type >> size;
  std::cout << "Je fais une pizza ";
  std::cout << "de type " << type;
  pizza.setType(static_cast<TypePizza>(type));
  std::cout << " et de Size " << size << std::endl;
  std::cout << "_______________" << std::endl;
  pizza.setSize(static_cast<TaillePizza>(size));
  findProcess(pizza);
}
