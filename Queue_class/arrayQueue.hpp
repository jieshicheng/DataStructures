#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

#include"queue.hpp"

#include<iostream>

using namespace std;

template<typename T> class arrayQueue : public queue<T>{

public:
	~arrayQueue() { delete []queue; }
	arrayQueue(int initialCapacity = 10);

//ADT
	bool empty() const { return queueFront == queueBack; }
	int size() const;
	T &front() const { return queue[queueFront]; }
	T &back() const { return queue[queueBack - 1]; }
	void pop();
	void push(const T &the_element);
private:
	int arrayLength;
	int queueFront;
	int queueBack;
	T *queue;
};

#endif

template<typename T> inline
int arrayQueue<T>::size() const
{
	if( queueFront > queueBack )
		return queueBack - queueFront;
	else if( queueFront == queueBack )
		return 0;
	else
		return arrayLength - queueFront + queueBack;
}

template<typename T> inline
arrayQueue<T>::arrayQueue(int initialCapacity)
{
	if(initialCapacity < 1)
		cout<<"error parameter value"<<endl;
	arrayLength = initialCapacity;
	queueFront = queueBack = 0;
	queue = new T[initialCapacity];
}

template<typename T> inline
void arrayQueue<T>::pop()
{
	if( empty() )
		cout<<"queue is empty"<<endl;
	else
		if( queueFront == arrayLength - 1 ){
			queue[queueFront].~T();
			queueFront = 0;
		}
		else{
			queue[queueFront++].~T();
		}
}

template<typename T> inline
void arrayQueue<T>::push(const T &the_element)
{
	if( queueBack == arrayLength - 1 ){
		queue[queueBack] = the_element;
		queueBack = 0;
	}
	else{
		queue[queueBack++] = the_element;
	}
}
