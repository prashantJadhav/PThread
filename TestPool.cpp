
#include <iostream>

#include "TestPool.h"

using namespace Pthread;
using namespace std;

TestPool::TestPool(int i):WorkerThread(i),a(i)
{
	cout<<"TestPool::Ctor"<<endl;
}

TestPool::~TestPool()
 {
	 cout<<"TestPool::Dtor"<<endl;

 }

void TestPool::run()
{
	cout<<"This is the runnable Starting Point of the thread" 
		"\n put some functions her for the thread to start ";
	sleep(2);

                //return(0);

}
