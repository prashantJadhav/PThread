/*******************************************************************

@author prashant 

!st start with the tread basic to learn threads 

Then go on to develop it into a cross platfoorm tread lib liike tiny thread++


Todo :1)  start with simple posic thread s
2) addinglocks and mutex and semaphore

3) add functionality for threadpooling  my b another class or interface for pooling 

4) add implementation in windows 
5) check for checking if compileris ompatible for c++ thread
6) later on seperate the mutex clas

*/

#ifndef __PTHREAD_H__
#define __PTHREAD_H__



#include<pthread.h>
#include<signal.h>
#include<unistd.h>


namespace Pthread{


class PThread
{

	private:
		int mutex ;
		bool isLock;
		pthread_t m_thread;
		int m_threadID;

		pthread_mutex_t m_mutex;
		

	public:

		PThread();
		~PThread();

		/*******************constor***************/

		PThread(void (*func)(void *),void *arg);

		void doWork(void *ptr);
		int run(void *);//runs te thread
		int start(void *);//creats the thread
		void join();
		static void * wrapperFunction(void *);
		bool isJoinable();


		int getID();
		void setID(int );

		unsigned showCpuCores();
		
		/*
			method to lock the critical part as mutex
		*/
		inline void lock()
		{
			pthread_mutex_lock(&m_mutex);
		}	

		inline void unlock()
		{
			pthread_mutex_unlock(&m_mutex);
		}

/*
struct to contain the info 
abt caller function

pointer to the function and is argument
*/

struct callerFuncInfo
{
	void (*mFunction)(void *); ///< Pointer to the function to be executed.
  	void * mArg;               ///< Function argument for the thread function.
        PThread *mThread;          ///< Pointer to the thread object.
};

typedef callerFuncInfo m_callerFuncInfo ;

};

}//PThread

#endif //end the PTHREAD def 
