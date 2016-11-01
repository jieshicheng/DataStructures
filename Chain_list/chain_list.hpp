#include"linear.hpp"

#include<iostream>

using namespace std;

template<typename T> class chainList : public linearList<T>{
	template<typename U> friend ostream &operator <<(ostream &os,const chainList<U> &cl);
public:
//construct function
	chainList(int initialCapacity = 10);
	chainList(const chainList<T> &);
	~chainList();

//ADT
	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T &get(int theIndex) const;
	int indexOf(const T &thelement) const;
	void erase(int theIndex);
	void insert(int theIndex,const T &ele);
	void output(ostream &os) const;
private:
	void checkIndex(int theIndex) const;
private:
	chainNode<T> *firstNode;
	int listSize;
};

template<typename T>
void chainList<T>::checkIndex(int theIndex) const
{
	if( theIndex < 0 || theIndex >= listSize )
		cout<<"error index"<<endl;
}

template<typename T>
chainList<T>::chainList(int initialCapacity)
{
	if(initialCapacity < 1)
		cout<<"must be > 0"<<endl;
	firstNode = nullptr;
	listSize = 0;
}

template<typename T>
chainList<T>::chainList(const chainList<T> &cl)
{
	listSize = cl.listSize;
	if( listSize == 0 ){
		firstNode == nullptr;
		return;
	}
	
	chainNode<T> *target = cl.firstNode;
	firstNode = new chainNode<T>(target->element);
	chainNode<T> *source = firstNode;
	target = target->next;
	next = new chainNode<T>(target->element);
	while( target != NULL ){
		target = target->next;
		source = source->next;
		source->next = new chainNode<T>(target->element);
	}
	source->next = NULL;
}

template<typename T>
chainList<T>::~chainList()
{
	chainNode<T> *Node = firstNode;
	while( Node ){
		firstNode = firstNode->next;
		delete Node;
		Node = firstNode;
	}
	listSize = 0;
}

template<typename T>
T &chainList<T>::get(int theIndex) const
{
	chainNode<T> *p = firstNode;
	for( int i = 0; i !=theIndex; ++i ){
		p = p->next;
	}
	return p->element;
}

template<typename T>
int chainList<T>::indexOf(const T &thelement) const
{
	int loc = 0;
	chainNode<T> *p = firstNode;
	while( !p && p->element != thelement ){
		p = p->next;
		++loc;
	}
	return loc;
}

template<typename T>
void chainList<T>::erase(int theIndex)
{
	chainNode<T> *p = firstNode;
	for( int i = 1; i != theIndex; ++i )
		p = p->next;
	chainNode<T> *erase = p->next;
	p->next = erase->next;
	delete erase;
	erase = nullptr;
	--listSize;
}

template<typename T>
void chainList<T>::insert(int theIndex,const T &ele)
{
	chainNode<T> *p = firstNode;
	chainNode<T> *temp = new chainNode<T>(ele);
	for(int i = 1; i != theIndex; ++i){
		p = p->next;
	}
	temp->next = p->next->next;
	p->next = temp;
	++listSize;
}

template<typename T>
void chainList<T>::output(ostream &os) const
{
	chainNode<T> *p = firstNode;
	while( !p ){
		p = p->next;
		cout<<p->element<<" ";
	}
	cout<<endl;
}

template<typename U>
ostream &operator <<(ostream &os,const chainList<U> &cl)
{
	cl.output(os);
	return os;
}
