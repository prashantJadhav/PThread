#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#include <semaphore.h>

namespace Pthread {

class Semaphore
 {
	private:
		sem_t m_semaphore;


	public:
		Semaphore();
		~Semaphore();

		void wait();
		void getValue();
		void post();
};

}//pthread

#endif
