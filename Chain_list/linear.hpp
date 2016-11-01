#ifndef LINEAR
#define LINEAR

#include<iostream>

using namespace std;

template<typename T> class linearList{

public:
	virtual ~linearList() { }
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T &get(int theIndex) const = 0;
	virtual int indexOf(const T &thelement) const = 0;
	virtual void erase(int theIndex) = 0;
	virtual void insert(int theIndex,const T &ele) = 0;
	virtual void output(ostream &os) const = 0;
};

template<typename T> class chainNode{
public:
	T element;
	chainNode<T> *next;

	chainNode() = default;
	chainNode(const T &ele) : element(ele) { }
	chainNode(const T &ele,chainNode<T> *nex) : element(ele),next(nex) { }
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

