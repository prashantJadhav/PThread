#include<iostream>

#include "PThread.h"


using namespace std;

namespace Pthread{
PThread::PThread()
 {
	cout<<"in CTOR"<<endl;
	pthread_mutex_init(&m_mutex,NULL);
}

PThread::~PThread()
 {
	cout<<"in DTOR"<<endl;
	pthread_mutex_destroy(&m_mutex);
 }

/*
ctor to start teh thread using pthread_creat 

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    void *(*start_routine)(void*), void *arg);
*/

PThread::PThread(void (*function)(void *),void *arg)
 {
	cout<<"PThread::PThread(args)"<<endl;
	m_callerFuncInfo *func = new m_callerFuncInfo;
//callerFuncInfo *func=new callerFuncInfo;		
	func->mFunction=function;
	func->mArg = arg;
	func->mThread = this;
	int flag=pthread_create(&m_thread,NULL,wrapperFunction,(void *)func);		

	if(flag=0)
	 {
		cout<<"Exception while ccreating the thread "<<endl;
	 }
	

	//cout<<"thread id is "<<pthread_self()<<endl;

	
 }

/*
@autor Prashant 
Wrapper function to get the structuer of calliee function into this thread

1) gets the struxcture info of teh callee function 
cals it 
*/
void * PThread::wrapperFunction(void *args)
 {
cout<<"PThread::wrapperFunctio"<<endl;	
/******copied line dunno hw this wrks */
	m_callerFuncInfo *function = (m_callerFuncInfo *)args ;

	try
	{
		cout<<"hiiiiiiiiiiiii"<<endl;
		function->mFunction(function->mArg);
	}
	catch(...)
	{
		cout<<"Exception caugth::"<<endl;
	}	
}

/*
@author:prashant

tis method i sused to wait for the thread to end before resuming the operation of the send thread
*/
void PThread::join()
 {
	//if(joinable())
	//{
	//	this->lock();
		pthread_join(m_thread,NULL);

	//}
}

/*
@author:Prashant
Method to get the id of the thread 
*/
int PThread::getID()
 {
	return m_threadID;
 }

void PThread::setID(int id)
 {
	m_thread = id ;
 }

/*
copied from tiny thread
*/

unsigned PThread::showCpuCores()
{
#if defined(_TTHREAD_WIN32_)
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  return (int) si.dwNumberOfProcessors;
#elif defined(_SC_NPROCESSORS_ONLN)
  return (int) sysconf(_SC_NPROCESSORS_ONLN);
#elif defined(_SC_NPROC_ONLN)
  return (int) sysconf(_SC_NPROC_ONLN);
#else
  // The standard requires this function to return zero if the number of
  // hardware cores could not be determined.
  return 0;
#endif
}


}//PTHread
