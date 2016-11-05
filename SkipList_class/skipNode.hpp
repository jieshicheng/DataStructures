#ifndef _SKIPNODE_
#define _SKIPNODE_

#include<iostream>
#include<utility>

using namespace std;

template<typename K,typename E> class skipNode{
public:
	typedef pair<const K,E> pairType;

	pairType element;
	skipNode<K,E> **next;
	
	skipNode(const pairType &thePair,int size) : element(thePair)
	{
		next = new skipNode<K,E>* [size];
	}
	~skipNode() = default;
};

#endif
