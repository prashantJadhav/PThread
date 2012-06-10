/********************

Class to test the Thread pool so that we can later optimize it 

starss with basic initialization
***********/

#ifndef __TEST_POOL_H__
#define __TEST_POOL_H__

#include "WorkerThreads.h"

namespace Pthread{

   class TestPool : public WorkerThread
   {
	private:
		int a;

	public:
		TestPool(int );
		~TestPool();
		void run();
	
   };

}//namespace

#endif

