//
// communication.hpp for communication in /home/bechad_p/rendu/cpp_plazza/project/communication
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Sat Apr 25 10:46:53 2015 Pierre Bechade
// Last update Sun Apr 26 22:44:50 2015 Caltraba Mickael
//

#ifndef __COMMUNICATION_HH__
# define __COMMUNICATION_HH__

#include "INamePipes.hh"

class Communication : public INamePipes
{
public:
  Communication(const unsigned int &nbr, std::string const &name);
  ~Communication();
  void		out(const std::string &message);
  std::string	getName() const;
  std::string	in();
  void		createPipes();

private:
  int		_nbr;
  std::string	_s_in;
  int		_fd;
};

#endif /* __COMMUNICATION_HH__ */
