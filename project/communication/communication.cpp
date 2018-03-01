//
// communication.cpp for communication in /home/bechad_p/rendu/cpp_plazza/project/communication
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Sat Apr 25 10:53:11 2015 Pierre Bechade
// Last update Sun Apr 26 22:45:00 2015 Caltraba Mickael
//

#include <sstream>
#include <cstring>
#include <cstdio>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "communication.hpp"

Communication::Communication(const unsigned int &nbr, std::string const &name) :
  _nbr(nbr),
  _s_in(name)
{
  mkfifo(_s_in.c_str(), S_IRWXU);
  this->_fd = open(this->_s_in.c_str(), O_RDWR | O_CREAT);
  std::cout << "Created Named Pipes " << this->_s_in<< std::endl;
}
Communication::~Communication()
{
}

std::string	Communication::getName() const {return (this->_s_in);}

std::string	Communication::in()
{
  char buff[80];
  int	ret;

  memset(buff, 0, 80);
  if ((ret = read(this->_fd, buff, 80)) < 0)
    return (NULL);
  buff[ret] = '\0';
  return (buff);
}

void	Communication::out(const std::string &message)
{
  write(this->_fd, message.c_str(), message.size());
}
