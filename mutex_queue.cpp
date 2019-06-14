
#include "b.h"
#include "a.h"
std::queue<int> g_q;

myQueue* myQueue::m_instance = NULL;
HANDLE single_mutex = CreateMutex(NULL,false,"");
HANDLE myQueue::m_mutex;
HANDLE myQueue::m_event;
myQueue::myQueue()
{
	myLock::initEvent(m_event);
	myLock::initMutex(m_mutex);
	std::cout << "constructor" << std::endl;
}
myQueue::~myQueue()
{
	myLock::destroyEvent(m_event);
	myLock::destroyMutex(m_mutex);
	std::cout << "deconstructor" << std::endl;
}

myQueue* myQueue::getInstance()
{
	if (m_instance == NULL)
	{
		myLock::lockMutex(single_mutex);
		if (m_instance == NULL)
		{
			m_instance = new myQueue();
		}
		myLock::unlockMutex(single_mutex);
	}
	return m_instance;
}

int myQueue::pop()
{
	//std::cout << "[ENTER]myQueue::pop" << std::this_thread::get_id() << std::endl;
	myLock::lockMutex(m_mutex);
	if (output.empty())
	{
		if (input.empty())
		{
			//both empty
			std::cout << "queue is empty, pop INT_MIN" << std::endl;
			myLock::unlockMutex(m_mutex);
			return INT_MIN;
		}
		else
		{
			while (!input.empty())
			{
				int tmp = input.top();
				output.push(tmp);
				input.pop();
			}
		}
	}
	int tmp = output.top();
	output.pop();
	std::cout << "pop " << tmp << ". thread id is:" << std::this_thread::get_id() << std::endl;
	myLock::unlockMutex(m_mutex);
	return tmp;
	
	//std::cout << "[EXIT]myQueue::pop" << std::this_thread::get_id() << std::endl;
}
bool myQueue::push(int value)
{
	//std::cout << "[ENTER]myQueue::push" << std::this_thread::get_id() << std::endl;
	myLock::lockMutex(m_mutex);
	input.push(value);
	std::cout << "push " << value << ". thread id is:" << std::this_thread::get_id()<<std::endl;
	myLock::setEvent(m_event);
	myLock::unlockMutex(m_mutex);
	return true;
	//std::cout << "[EXIT]myQueue::push" << std::this_thread::get_id() << std::endl;
}
bool myQueue::empty()
{
	//std::cout << "[ENTER]myQueue::empty" << std::this_thread::get_id() << std::endl;
	myLock::lockMutex(m_mutex);
	if (input.empty() && output.empty())
	{
		myLock::unlockMutex(m_mutex);
		return true;
	}
	myLock::unlockMutex(m_mutex);
	return false;	
	//std::cout << "[EXIT]myQueue::empty" << std::this_thread::get_id() << std::endl;
}
size_t myQueue::size()
{
	//std::cout << "[ENTER]myQueue::size" << std::this_thread::get_id() << std::endl;
	myLock::lockMutex(m_mutex);
	int len = input.size() + output.size();
	myLock::unlockMutex(m_mutex);
	return len;
	//std::cout << "[EXIT]myQueue::size" << std::this_thread::get_id() << std::endl;
}


void myQueue::threadFuncIN(int in)
{
	std::cout << "[ENTER]threadFuncIN" << std::this_thread::get_id() << std::endl;
	int val = 10;
	while (val-- > 0)
	{
		myQueue::getInstance()->push(val);
	}

	std::cout << "[EXIT]threadFuncIN" << std::this_thread::get_id() << std::endl;
}

void myQueue::threadFuncOut1(int in)
{
	std::cout << "[ENTER]threadFuncOut1" << std::this_thread::get_id() << std::endl;
	//int n = 10;
	while(myLock::waitEvent(m_event))
	{
		//myLock::waitEvent(m_event);
		//std::cout<<"pop "<<myQueue::getInstance()->pop()<<std::endl;
		myQueue::getInstance()->pop();
	} 
	std::cout << "[EXIT]threadFuncOut1" << std::this_thread::get_id() << std::endl;
}
void myQueue::threadFuncOut2(int in)
{
	std::cout << "[ENTER]threadFuncOut2." << std::this_thread::get_id() << std::endl;
	//int n = 10;
	while (myLock::waitEvent(m_event))
	{
		//myLock::waitEvent(m_event);
		//std::cout << "pop " << myQueue::getInstance()->pop() << std::endl;
		myQueue::getInstance()->pop();
	}
	std::cout << "[EXIT]threadFuncOut2" << std::this_thread::get_id() << std::endl;
}
void createThread()
{
	std::cout << "[ENTER]createThread." << "thread id is: "<<std::this_thread::get_id()<<std::endl;
	std::thread th1(myQueue::threadFuncIN,1);
	std::thread th2(myQueue::threadFuncOut1,  2);
	std::thread th3(myQueue::threadFuncOut2, 3);


	th1.join();
	th2.join();
	th3.join();
	std::cout << "[EXIT]createThread" << std::this_thread::get_id() << std::endl;
}

