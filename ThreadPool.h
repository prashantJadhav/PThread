/***********************8

this class provides the thread pool pattern implemention 

hope t wrks 

*****************************/


#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include<vector>

#include "PThread.h"
#include "WorkerThreads.h"

namespace Pthread{

  class ThreadPool : public PThread
  {

	private:
		int workerThreads;
		int m_maxThreads,m_minThread;
		//typedef std::vector<PThread *> workerThreadVec;
		typedef std::vector<WorkerThread *> workerThreadVec;
		
	public:
		ThreadPool();
		ThreadPool(int );
		~ThreadPool();
		//workerThreads m_threads;
		void run();
		void execute();
		bool allocateWork(WorkerThread *);
		void initializeThreads();		
		void get(WorkerThread *);
		
		workerThreadVec m_workerThreadsVec ;

  };
}//naemspace

#endif
