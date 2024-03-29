/********************/

#include<iostream>

#include "ThreadPool.h"

using namespace std;
using namespace Pthread;
//namespace Pthread{


ThreadPool::ThreadPool()
 {
	std::cout<<"ThreadPool::ThreadPool"<<endl;
 }

ThreadPool::ThreadPool(int tmp):m_maxThreads(tmp)
 {
        std::cout<<"ThreadPool11::ThreadPool"<<endl;
	m_mutex.lock();
	incompleteWork = 0;


	if(tmp < 1)
		m_maxThreads=1;

//	m_maxThreads = tmp;

	cout<<"initial size of vector is "<<m_workerThreadsVec.size();

	sem_init(&threads,0,m_maxThreads);
	m_workSemaphore=new Semaphore();
	m_workerThreadsVec.resize(m_maxThreads,NULL);
	m_mutex.unlock();

 }


ThreadPool::~ThreadPool()
{
	cout<<"ThreadPool::DTOR"<<endl;
}


/*@author prashant
This function is used to initialize the treas to maximum tread tht we specified for the pool 
*/

void ThreadPool::initializeThreads()
 {

	cout<<"ThreadPool::initializeThread"<<endl;
	for(int i =0 ; i<=m_maxThreads;i++)
	 {
		PThread thread(ThreadPool::execute,(void *) this ); //execute will be the startign point of the thread 
		//i think here should be the code to collect the object in vectore
		//thread.join();
		
	 }
 }

/*documentation
default method to run 
makes yse of a workertrhesClass interface wwhic uplenebts this meth
)(*/
void ThreadPool::run()
 {
	std::cout<<"*********************ThreadPool::run"<<endl;
	//do some execution here
 }


/*
 documentation
@author prashant
 This funtion assigne a work ie function code to the worker thread 
makes the queu of the owrker threads 
*/
bool ThreadPool::allocateWork(WorkerThread *workerThread)
 {
	std::cout<<"ThreadPool::assignWork"<<endl;

	//mutex hild
	//ubutakuze que
	//relea e mutex

	m_mutex.lock();
	incompleteWork++;
	 m_mutex.unlock();
	int val;
	sem_getvalue(&threads,&val);
	cout<<"niiiiiiiiiiiiiiiiiiiiiceeeeeeeee="<<val<<endl;
	sem_wait(&threads);
	m_mutex.lock();
	//sem_post(&threads); //wrking
	//m_workerThreadsVec.push_back(&workerThread);
	m_workerThreadsVec.push_back(workerThread);
	cout<<"PPPkool="<<m_workerThreadsVec.size();
	m_workSemaphore->post();
	m_mutex.unlock();
	return true ;
	
 }

/*
	documentation
 @author prashant 
 Thsi function is uesd by the threads in the pool to get/fetch the work when their time comes 
*/

bool ThreadPool::get(WorkerThread **workerThread)
 {
	std::cout<<"ThreadPool::get"<<endl;

	//sem_wait(&threads);

	m_workSemaphore->wait();	
int val;
        sem_getvalue(&threads,&val);
        cout<<"RPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPniiiiiceeeeeeeee="<<val<<endl;

	//sem_post(&threads);
	std::cout<<"****************************************************kooool************************"<<endl;
	m_mutex.lock();
	//if(!m_workerThreadsVec.empty())
	 //{
		//m_workerThreadsVec.back()->run();
		WorkerThread *worker = m_workerThreadsVec.back();//returns the last element
		 m_workerThreadsVec.pop_back();
	//}
	cout<<"kool="<<m_workerThreadsVec.size();

	//worker->run();

	*workerThread=worker;
	sem_post(&threads);
	m_mutex.unlock();

	return true;
 }


/* documentation

@author prashant

 Thsi is a static function used as teh starting point of thread execution 

This function is used to called the run method of the worker Thread 

sequence is like 

1) fetch teh Worker object 
2) call teh run method to do the work 
*/

void ThreadPool::execute(void *args)
 {
	cout<<"ThreadPool::execute"<<endl;

	cout<<"\nThread ID: "<<PThread::getID()<<endl;

	WorkerThread *worker = NULL;

	while(((ThreadPool *)args)->get(&worker))
	{

		((ThreadPool *)args)->m_mutex.lock();
		if(worker)
		{
			cout<<"]n]nsdfsdfsdfsdfsdfsfsfsf"<<endl;

			//sleep(20);
			worker->run();
			//delete worker ;
			worker = NULL;
		}

		((ThreadPool *)args)->incompleteWork--;


		((ThreadPool *)args)->m_mutex.unlock();
	}
 }

void ThreadPool::clean(int maxPollSecs)
 {
	while( incompleteWork>0 )
        {
                cout << "Work is still incomplete=" << incompleteWork << endl;
                sleep(maxPollSecs);
        }
        cout << "All Done!! Wow! That was a lot of work!" << endl;
 //       sem_destroy(&availableWork);
        sem_destroy(&threads);
	delete m_workSemaphore;
//        pthread_mutex_destroy(&mutexSync);
//        pthread_mutex_destroy(&mutexWorkCompletion);

 
 }
//}
