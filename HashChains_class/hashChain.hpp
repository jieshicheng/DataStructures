#ifndef _HASHCHAIN_
#define _HASHCHAIN_

#include"hashNode.hpp"
#include"myException.hpp"

#include<iostream>
#include<utility>
#include<climits>

using namespace std;

template<typename K,typename E> class hashChain{

public:
	hashChain(int theDivisor = 11,int size = 11);
	~hashChain() { delete []last; }

	bool empty() const { return dSize == 0; }
	int size() const { return dSize; }
	pair<K,E> find(const K &) const;
	void insert(const pair<K,E> &);

private:
	hashNode<K,E> **last;
	int dSize;
	int divisor;
};

#endif

template<typename K,typename E>
hashChain<K,E>::hashChain(int theDivisor,int size)
{
	divisor = theDivisor;
	dSize = 0;

	hashNode<K,E> *p = new hashNode<K,E>(pair<K,E>(INT_MAX,0));
	last = new hashNode<K,E>* [size];
	for(int i = 0; i != size; ++i)
		last[i] = p;
}

template<typename K,typename E>
pair<K,E> hashChain<K,E>::find(const K &theKey) const
{
	int i = theKey % divisor;
	if(last[i] != NULL){
		hashNode<K,E> *p = last[i]->next;
		while(p && p->element.first != theKey)
			p = p->next;
		if(p != NULL)
			return pair<K,E>(p->element);
		else
			return hashChainNofind();
	}
	else
		return hashChainNofind();
}

template<typename K,typename E>
void hashChain<K,E>::insert(const pair<K,E> &thePair)
{
	int i = thePair.first % divisor;
	hashNode<K,E> *p = last[i];
	while(p->next)
		p = p->next;
	p->next = new hashNode<K,E>(thePair);
	++dSize;
}
