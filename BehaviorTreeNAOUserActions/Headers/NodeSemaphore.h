#ifndef NODESEMAPHORE_H
#define NODESEMAPHORE_H

#include <mutex>
#include <condition_variable>

class NodeSemaphore
{
private:
    int Value;
	std::mutex Mutex;
	std::condition_variable ConditionVariable;
public:
    NodeSemaphore(int InitialValue);
    ~NodeSemaphore();
	void Wait();
	void Signal();
};

#endif
