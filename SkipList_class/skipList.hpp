#ifndef _SKIPLIST_
#define _SKIPLIST_

#include"dictionary.hpp"
#include"skipNode.hpp"

#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

template<typename K,typename E> class skipList : public dictionary<K,E>{

public:
	~skipList();
	skipList(K largeKey,int maxPairs,float prob);
	bool empty() const { return dSize == 0; }
	int size() const { return dSize; }
	pair<const K,E> *find(const K &) const;
	void erase(const K &);
	void insert(const pair<const K,E> &);
private:
	int level() const;
	skipNode<K,E> *search(const K &the_key) const;

	float cutOff;
	int levels;
	int dSize;
	int maxLevel;
	K tailKey;
	skipNode<K,E> *headerNode;
	skipNode<K,E> *tailNode;
	skipNode<K,E> **last;
};

#endif

template<typename K,typename E>
skipList<K,E>::~skipList()
{
	skipNode<K,E> *theNode;
	while( headerNode != tailNode ){
		theNode = headerNode->next[0];
		delete headerNode;
		headerNode = theNode;
	}
	delete tailNode;
	delete []last;
}

template<typename K,typename E>
int skipList<K,E>::level() const
{
	int lev = 0;
	while( rand() <= cutOff )
		++lev;
	return (lev <= maxLevel) ? lev : maxLevel;
}

template<typename K,typename E>
skipNode<K,E> *skipList<K,E>::search(const K &the_key) const
{
	skipNode<K,E> *beforeNode = headerNode;
	for( int i = levels; i >= 0; --i ){
		while(beforeNode->next[i]->element.first < the_key )
			beforeNode = beforeNode->next[i];
		last[i] = beforeNode;
	}
	return beforeNode->next[0];
}

template<typename K,typename E>
skipList<K,E>::skipList(K largeKey,int maxPairs,float prob)
{
	cutOff = prob * RAND_MAX;
	maxLevel = static_cast<int>(ceil(log(static_cast<float>(maxPairs)) / log(1/prob))) - 1;
	levels = 0;
	dSize = 0;
	tailKey = largeKey;

	pair<K,E> tailPair;
	tailPair.first = tailKey;
	headerNode = new skipNode<K,E>(tailPair,maxLevel + 1);
	tailNode = new skipNode<K,E>(tailPair,0);
	last = new skipNode<K,E>* [maxLevel + 1];

	for( int i = 0; i <= maxLevel; ++i ){
		headerNode->next[i] = tailNode;
	}
}

template<typename K,typename E>
pair<const K,E> *skipList<K,E>::find(const K &the_key) const
{
	if( the_key >= tailKey )
		return NULL;
	skipNode<K,E> *beforeNode = headerNode;
	for( int i = levels; i >= 0; --i ){
		while(beforeNode->next[i]->element.first < the_key)
			beforeNode = beforeNode->next[i];
	}
	if(beforeNode->next[0]->element.first == the_key)
		return &beforeNode->next[0]->element;
	return NULL;
}

template<typename K,typename E>
void skipList<K,E>::erase(const K &the_key)
{
	if( the_key >= tailKey ){
		cout<<"error parameter value"<<endl;
		return ;
	}
	skipNode<K,E> *theNode = search(the_key);
	if( theNode->element.first != the_key )
		return ;
	for( int i = 0; i <= levels && last[i]->next[i] == theNode; ++i ){
		last[i]->next[i] == theNode->next[i];
	}
	while( levels > 0 && headerNode->next[levels] == tailNode )
		--levels;
	cout<<"successful"<<endl;	
	delete theNode;
	--dSize;
}

template<typename K,typename E>
void skipList<K,E>::insert(const pair<const K,E> &the_pair)
{
	if( the_pair.first >= tailKey ){
		cout<<"error parameter value"<<endl;
		return ;
	}
	skipNode<K,E> *theNode = search(the_pair.first);
	if( theNode->element.first == the_pair.first ){
		theNode->element.second = the_pair.second;
		return ;
	}

	int theLevel = level();
	if(theLevel > levels){
		theLevel = ++levels;
		last[theLevel] = headerNode;
	}
	skipNode<K,E> *newNode = new skipNode<K,E>(the_pair,theLevel + 1);
	for( int i = 0; i <= theLevel; ++i ){
		newNode->next[i] = last[i]->next[i];
		last[i]->next[i] = newNode;
	}
	++dSize;
	return ;
}


