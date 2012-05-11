#ifndef _MUTEX_H_
#define _MUTEX_H_


#include <pthread.h>
namespace Pthread
{
  class Mutex
  {

	private:
		pthread_mutex_t m_mutexHandle ;
	public:
		Mutex();
		~Mutex();
		void lock();
		void unlock();
		bool tryLock();

  };
}//Pthread

#endif
