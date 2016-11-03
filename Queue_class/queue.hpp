#ifndef QUEUE
#define QUEUE

#include<iostream>

using namespace std;

template<typename T> class queue{

public:
	virtual ~queue() { }
	virtual bool empty() const =0;
	virtual int size() const =0;
	virtual T &front() const =0;
	virtual T &back() const =0;
	virtual void pop() =0;
	virtual void push(const T &the_element) =0;
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
