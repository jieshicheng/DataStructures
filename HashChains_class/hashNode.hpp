#ifndef _HASHNODE_
#define _HASHNODE_

#include<iostream>
#include<utility>

using namespace std;

template<typename K,typename E> class hashNode{

public:
	pair<K,E> element;
	hashNode *next;

	hashNode(const pair<K,E> &thePair) : element(thePair),next(nullptr) { }
};

#endif
