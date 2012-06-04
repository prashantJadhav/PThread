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
        std::cout<<"ThreadPool::ThreadPool"<<endl;

//	m_maxThreads = tmp;
 }


void ThreadPool::initializeThreads()
 {
	for(int i =0 ; i<=m_maxThreads;i++)
	 {
		//PThread thread(&ThreadPool::execute,0); //execute will be the startign point of the thread 
		//i think here should be the code to collect the object in vectore
		
	 }
 }

/*documentation
default method to run 
makes yse of a workertrhesClass interface wwhic uplenebts this meth
)(*/
void ThreadPool::run()
 {
	std::cout<<"ThreadPool::run"<<endl;
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

	//m_workerThreadsVec.push(&workerThread);

	return true ;
	
 }

/*
	documentation
 @author prashant 
 Thsi function is uesd by the threads in the pool to get/fetch the work when their time comes 
*/

void ThreadPool::get(WorkerThread *workerThread)
 {
	std::cout<<"ThreadPool::get"<<endl;
 }
//}
