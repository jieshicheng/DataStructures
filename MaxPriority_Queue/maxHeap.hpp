#ifndef _MAXHEAP_
#define _MAXHEAP_

#include<iostream>

#include"maxPriorityQueue.hpp"
#include"myException.hpp"

using namespace std;

template<typename T> class maxHeap : public maxPriorityQueue<T>{

public:
	maxHeap(int newLength = 10);//
	~maxHeap() { delete []heap; }
	
//ADT
	bool empty() const { return heapSize == 0; }
	int size() const { return heapSize; }
	const T &top() const; //
	void pop();//
	void push(const T &the_element);//
private:
	int arrayLength;
	int heapSize;
	T *heap;

};

template<typename T>
maxHeap<T>::maxHeap(int newLength)
{
	arrayLength = newLength;
	heapSize = 0;
	heap = new T [arrayLength];
}

template<typename T>
const T &maxHeap<T>::top() const
{
	
}

template<typename T>
void maxHeap<T>::pop()
{
	
}

template<typename T>
void maxHeap<T>::push(const T &the_element)
{
	
}
