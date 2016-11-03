#ifndef ARRAYSTACK
#define ARRAYSTACK

#include"stack.hpp"

#include<iostream>

using namespace std;

template<typename T> class arrayStack : public stack<T>{

public:
	arrayStack(int initialCapacity = 10);
	~arrayStack() { delete []stack; }
//ADT
	bool empty() const { return stackTop == -1; }
	int size() const { return stackTop + 1; }
	T &top() const
	{
		if( stackTop == -1 )
			cout<<"no element"<<endl;
		return stack[stackTop];
	}
	void pop()
	{
		if( stackTop == -1 )
			cout<<"no element"<<endl;
		stack[stackTop--].~T();
	}
	void push(const T &thelement);
private:
	T *stack;
	int stackTop;
	int stackLength;
};

template<typename T>
arrayStack<T>::arrayStack(int initialCapacity)
{
	if( initialCapacity < 0 )
		cout<<"error parameter value"<<endl;
	else{
		stack = new T[initialCapacity];
		stackTop = -1;
		stackLength = initialCapacity;
	}
}

template<typename T>
void arrayStack<T>::push(const T &thelement)
{
	if( stackTop == stackLength - 1 ){
		changeLength1D(stack,stackLength,2 * stackLength);
		stackLength *= 2;
	}
	stack[++stackTop] = thelement;
}

#endif
