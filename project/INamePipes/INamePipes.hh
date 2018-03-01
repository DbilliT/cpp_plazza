//
// INamePipes.hh for INamePipe in /home/bechad_p/rendu/cpp_plazza/project/INamePipes
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Sat Apr 25 10:36:22 2015 Pierre Bechade
// Last update Sun Apr 26 22:30:24 2015 Caltraba Mickael
//

#ifndef __INamePipes_HH__
# define __INamePipes_HH__

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <fcntl.h>

class INamePipes
{
public:
  virtual void out(const std::string &message) = 0;
  virtual std::string in() = 0;
};

#endif /* __INamePipes_HH__ */
