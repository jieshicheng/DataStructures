#include<iostream>
#include<algorithm>
#include"linear.hpp"

using namespace std;

template<typename T> class arrayList : public linearList<T>{
	template<typename U>friend ostream &operator <<(ostream &os,const arrayList<U> &al);
public:
//construct function
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T> &);
	~arrayList() { delete []element; }
//ADT
	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T &get(int theIndex) const;
	int indexOf(const T &thelement) const;
	void erase(int theIndex);
	void insert(int theIndex,const T &ele);
	void output(ostream &os) const;
private:
	int checkIndex(int theIndex) const;
private:
	T *element;
	int arrayLength;
	int listSize;
};

template<typename T>
T &arrayList<T>::get(int theIndex) const
{
	if( checkIndex(theIndex) )
		return element[theIndex];
}

template<typename T>
int arrayList<T>::checkIndex(int theIndex) const
{
	if(theIndex < 0 || theIndex >= listSize){
		cout<<"error Index"<<endl;
		return 0;
	}
	else
		return 1;
}

template<typename T>
arrayList<T>::arrayList(int initialCapacity)
{
	if(initialCapacity < 1)
		cout<<"the parameter value error"<<endl;
	element = new T[initialCapacity];
	arrayLength = initialCapacity;
	listSize = 0;
}

template<typename T>
arrayList<T>::arrayList(const arrayList<T> &rhs)
{
	element = new T[rhs.arrayLength];
	copy(rhs.element,rhs.element + listSize,element);
	arrayLength = rhs.arrayLength;
	listSize = rhs.listSize;
}

template<typename T>
int arrayList<T>::indexOf(const T &thelement) const
{
	auto iter = find(element,element + listSize,thelement);
	auto data = iter - element;
	if( data == listSize )
		return -1;
	return data;
}

template<typename T>
void arrayList<T>::erase(int theIndex)
{
	if( checkIndex(theIndex) ){
		copy(element + theIndex + 1,element + listSize,element + theIndex);
		--listSize;
	}
}

template<typename T>
void arrayList<T>::insert(int theIndex,const T &ele)
{
	if( listSize == arrayLength ){
		changeLength1D(element,arrayLength,2 * arrayLength);
		arrayLength *= 2;
	}
	copy(element + theIndex,element + listSize,element + theIndex + 1);
	element[theIndex] = ele;
	++listSize;
}

template<typename T>
void arrayList<T>::output(ostream &os) const
{
	for( int it = 0; it != listSize; ++it )
		cout<<element[it]<<" ";
	cout<<endl;
}

template<typename U>
ostream &operator <<(ostream &os,const arrayList<U> &al)
{
	for( int it = 0; it != al.listSize; ++it )
		cout<<al.element[it];
	return os;
}
