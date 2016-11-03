#ifndef STACK
#define STACK

#include<iostream>

using namespace std;

template<typename T> class stack{

public:
	virtual ~stack() { }
	virtual bool empty() const =0;
	virtual int size() const =0;
	virtual T &top() const =0;
	virtual void pop() =0;
	virtual void push(const T &thelement) =0;
};

#endif

template<typename T>
void changeLength1D(T *&a,int oldLength,int newLength)
{
	if( newLength < 0 )
		cout<<"error"<<endl;
	T *temp = new T[newLength];
	copy(a,a + oldLength,temp);
	delete []a;
	a = temp;
}
