#include "Mutex.h"
#include "Logger.h"

namespace Pthread
{
Mutex::Mutex()
{
	//initialize pthere mutex //later n first check if the object is already locked or not 

	pthread_mutex_init(&m_mutexHandle,NULL); //can send the attribute also expand it later

}

Mutex::~Mutex()
{
	//destroy pthread mutex 
	pthread_mutex_destroy(&m_mutexHandle);
}

inline void Mutex::lock()
{
	pthread_mutex_lock(&m_mutexHandle);
}

inline void Mutex::unlock()
{
	pthread_mutex_unlock(&m_mutexHandle);
}

inline bool Mutex::tryLock()
{
	pthread_mutex_trylock(&m_mutexHandle);
}

}//Pthread
