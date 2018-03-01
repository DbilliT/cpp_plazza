//
// IThread.hh for IThread in /home/bechad_p/rendu/cpp_plazza/project/IThread
// 
// Made by Pierre Bechade
// Login   <bechad_p@epitech.net>
// 
// Started on  Sat Apr 25 10:41:50 2015 Pierre Bechade
// Last update Sat Apr 25 11:02:40 2015 Pierre Bechade
//

#ifndef THREAD_H_
# define THREAD_H_

#include <pthread.h>

class IThreaded
{
public:
  virtual void *run(void) = 0;
  virtual ~IThreaded();
  virtual create_t = 0;
  virtual static void *proccess(void *) = 0;
};

// class Thread
// {
// public:
//   Thread(IThreaded &thread);
//   ~Thread(void);
//   void *run(void);
//   static void *proccess(void *);
// private:
//   pthread_t thread_;
//   IThreaded &threadobj_;
//   Thread &operator=(Thread const &);
// };

#endif /* !THREAD_H_ */
