/*

Thsi is a interface for the thread will be used to implement the ru method

just like the runnable interface in the java
*/

#ifndef __WORKER_THREAD_H__
#define __WORKER_THREAD_H__

namespace Pthread{

 class WorkerThread
 {
	private:
		int id;
	public:
		virtual void run()=0;
		//virtual ~WorkerThread();
		~WorkerThread()
		{
			id=0;
		}
		WorkerThread(int id):id(id)
		{
		}
		
		WorkerThread()
		{
		}

 };	
}//namespace

#endif
