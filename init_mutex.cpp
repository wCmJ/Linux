
#include"a.h"

myLock::myLock()
{
	//intitMutex(mutex);

}
myLock::~myLock()
{
	//intitMutex(mutex);

}
bool myLock::initMutex(HANDLE& mutex)
{
	mutex = CreateMutex(NULL, false, "");
	return true;
}

bool myLock::lockMutex(HANDLE& mutex)
{
	WaitForSingleObject(mutex, INFINITE);
	return true;
}
bool myLock::unlockMutex(HANDLE& mutex)
{
	ReleaseMutex(mutex);
	return true;
}

bool myLock::destroyMutex(HANDLE& mutex)
{
	CloseHandle(mutex);
	return true;
}

bool myLock::initEvent(HANDLE &event)
{
	event = CreateEvent(NULL, false, false, "");
	return true;
}

bool myLock::setEvent(HANDLE& event)
{
	SetEvent(event);
	return true;
}

bool myLock::resetEvent(HANDLE& event)
{
	ResetEvent(event);
	return true;
}

bool myLock::waitEvent(HANDLE& event)
{
	WaitForSingleObject(event, INFINITE);
	return true;
}

bool myLock::destroyEvent(HANDLE& event)
{
	CloseHandle(event);
	return true;
}




