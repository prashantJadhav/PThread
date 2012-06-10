#include<iostream>

#include"PThread.h"
#include "ThreadPool.h"
#include "FileOperations.h"
#include "Mutex.h"
#include "TestPool.h"


using namespace std;
using namespace Pthread ;

void printMsg(void *args)
 {
	std::cout<<"In print Msg"<<endl;
}

void printMsgg(void* args)
 {
	std::cout<<"In print Msg"<<args<<endl;
}

int main()
{

Mutex mu;
	std::cout<<"The number of cores are ::"<<endl;

	PThread pt(printMsg,0);
	PThread pt1(printMsg,0);
	PThread pt2(printMsgg,0);
	std::cout<<"The number of cores are ::"<<pt.showCpuCores();
pt.join();
pt1.join();

	cout<<"************************pTesssting thread pool ************************"<<endl;

	ThreadPool *tp=new ThreadPool(5);

	tp->initializeThreads();

	for(unsigned int i=0;i<10;i++)
	{
		TestPool *worker = new TestPool(2);
	
		tp->allocateWork(worker);

	}

	// destroyPool(int maxPollSecs)
        // Before actually destroying the ThreadPool, this function checks if all the pending work is completed.
        // If the work is still not done, then it will check again after maxPollSecs
        // The default value for maxPollSecs is 2 seconds.
        // And ofcourse the user is supposed to adjust it for his needs.
        
    tp->clean(2);

  //  time_t t2=time(NULL);
    //cout << t2-t1 << " seconds elapsed\n" << endl;
        delete tp;

	
	cout<<"************************Tesssting thread Write************************"<<endl;

	try
 	{

	cout<<"************************Tesssting thread Write************************"<<endl;
//	      FileOperations fo;

		// PThread pt(fo.print2File);
		 //PThread pt(FileOperations::print2File,0);
		 //PThread pt(reaad,(void *)&fo);

/*		fo.setReportFile("tank");

		fo.setHtmlBuffer("hi how r u \n m fine thnk u \n <b>nd kkool</b>");

		 PThread pt(FileOperations::print2File,(void *)&fo);
		 //PThread pt(FileOperations::readFile,(void *)&fo);
		
		fo.setHtmlBuffer("hello Mamam mia \n nd the date is \n i dunno wht to write ");

		 PThread pt2(FileOperations::print2File,(void *)&fo);
		pt.join();
		pt2.join();

*/	
	}
	catch(exception& e)
	{
		cout<<"xcepton="<<e.what()<<endl;
	}
	catch(...)
	{
	cout<<"Xceptino whi FO"<<endl;
	}
	return 0;
}
