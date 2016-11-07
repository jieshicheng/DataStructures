#ifndef _MAXPRIQUE_
#define _MAXPRIQUE_

#include<iostream>

using namespace std;

template<typename T> class maxPriorityQueue{

public:
	virtual ~maxPriorityQueue() { }
	virtual bool empty() const =0;
	virtual int size() const =0;
	virtual const T &top() const =0;
	virtual void pop() =0;
	virtual void push(const T &the_element) =0;
	
};

#endif
