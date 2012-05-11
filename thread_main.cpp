#include<iostream>
#include"PThread.h"


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

	std::cout<<"The number of cores are ::"<<endl;

	PThread pt(printMsg,0);
	PThread pt1(printMsg,0);
	PThread pt2(printMsgg,0);
	std::cout<<"The number of cores are ::"<<pt.showCpuCores();
pt.join();
pt1.join();
	return 0;
}
