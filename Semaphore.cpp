#include<iostream>

#include "Semaphore.h"

using namespace std;
using namespace Pthread;

Semaphore::Semaphore()
{
	sem_init(&m_semaphore,0,0);
}

Semaphore::~Semaphore()
{
	 sem_destroy(&m_semaphore);
}

void Semaphore::post()
{
	sem_post(&m_semaphore);
}

void Semaphore::wait()
{
	sem_wait(&m_semaphore);
}

void Semaphore::getValue()
{
	
}
