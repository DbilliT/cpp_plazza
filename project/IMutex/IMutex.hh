//
// IMutex.hh for IMutex in /home/bechad_p/rendu/cpp_plazza/project/IMutex
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Thu Apr 23 12:09:35 2015 Pierre Bechade
// Last update Sun Apr 26 22:30:12 2015 Caltraba Mickael
//

#ifndef __IMUTEX_HH__
# define __IMUTEX_HH__

class IMutex {
public:
  virtual void lock(void) = 0;
  virtual void unlock(void) = 0;
  virtual bool trylock(void) = 0;
};

#endif /* __IMUTEX_HH_ */
