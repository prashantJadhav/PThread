/***********************8

this class provides the thread pool pattern implemention 

hope t wrks 

*****************************/


#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include<vector>

#include "PThread.h"
#include "WorkerThreads.h"
#include "Mutex.h"
#include "Semaphore.h"

namespace Pthread{

  class ThreadPool : public PThread
  {

	private:
		int workerThreads;
		int m_maxThreads,m_minThread;
		//typedef std::vector<PThread *> workerThreadVec;
		typedef std::vector<WorkerThread *> workerThreadVec;
		int incompleteWork;

		
	public:
		ThreadPool();
		ThreadPool(int );
		~ThreadPool();
		//workerThreads m_threads;
		void run();
		static void execute(void *);
		bool allocateWork(WorkerThread *);
		void initializeThreads();		
		bool get(WorkerThread **);
		void clean(int);
		
		workerThreadVec m_workerThreadsVec ;

		Mutex m_mutex;
		Semaphore *m_workSemaphore;
		sem_t threads;

  };
}//naemspace

#endif
