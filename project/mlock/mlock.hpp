//
// lock.hpp for lock in /home/bechad_p/rendu/cpp_plazza/project/lock
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Sat Apr 25 11:20:07 2015 Pierre Bechade
// Last update Sat Apr 25 11:25:30 2015 Pierre Bechade
//

#ifndef __MLOCK_HPP__
# define __MLOCK_HPP__

#include "IMutex.hh"

class Mlock : public IMutex
{
public:
  Mlock();
  ~Mlock();
public:
  void lock();
  void unlock();
  bool trylock();
};

#endif /* __MLOCK_HPP__ */
