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
	heap = new T [arrayLength + 1];
}

template<typename T>
const T &maxHeap<T>::top() const
{
	if( empty() )
		throw queueEmpty();
	return heap[1];
}

template<typename T>
void maxHeap<T>::pop()
{
	if( heapSize == 0 )
		throw queueEmpty();
	heap[1].~T();
	T lastelement = heap[heapSize--];
	int currNode = 1;
	int child = 2;
	while( child <= heapSize ){
		if(child < heapSize && heap[child] < heap[child + 1])
			++child;
		if(lastelement > heap[child])
			break;
		heap[currNode] = heap[child];
		currNode = child;
		child *= 2;
	}
	heap[currNode] = lastlement;
}

template<typename T>
void maxHeap<T>::push(const T &the_element)
{
	if( arrayLength == heapSize ){
		changeLength1D(heap,arrayLength + 1,2 * (arrayLength + 1));
		arrayLength = 2 * arrayLength;	
	}
	int curr = ++heapSize;
	while( curr != 1 && heap[curr / 2] < the_element ){
		heap[curr] = heap[curr / 2];
		curr = curr / 2;
	}
	heap[curr] = the_element;
}
