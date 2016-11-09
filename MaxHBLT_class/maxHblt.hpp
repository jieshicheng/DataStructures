#ifndef _MAXHBLT_
#define _MAXHBLT_

#include<iostream>
#include<utility>
#include"arrayQueue.hpp"

using namespace std;

template<typename T> class HbltNode{

public:
	HbltNode() : element(pair<int,T>()),left(nullptr),right(nullptr) { }
	HbltNode(const pair<int,T> &the_element) : element(the_element),left(nullptr),right(nullptr) { }
	HbltNode(const pair<int,T> &the_element,HbltNode *l,HbltNode *r) : element(the_element),left(l),right(r) { }
	~HbltNode() { delete left,right; }
private:
	pair<int,T> element;
	HbltNode *left;
	HbltNode *right;
};

template<typename T> class maxHblt{

public:
	maxHblt() : root(nullptr),treeSize(0) { }
	maxHblt(const maxHblt<T> &theHblt); //
	~maxHblt() { delete root; }

	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	T top() const { return root->element.second; }
	void push(const T &value);
	void pop();
	void initialze(T *array,int theSize);
	void meld(maxHblt<T> &y);
	void clear();
private:
	void meld(HbltNode<T> *x,HbltNode<T> *y);
	void erase(HbltNode<T> *);

	HbltNode<T> *root;
	int treeSize;
};

template<typename T>
void maxHblt<T>::meld(HbltNode<T> *x,HbltNode<T> *y)
{
	if( y == NULL )
		return;
	if( x == NULL ){
		x = y;
		return;
	}
	if( x->element.second < y->element.second ){
		HbltNode<T> *temp = x;
		x = y;
		y = temp;
	}
	meld(x->right,y);
	if( x->left == NULL ){
		x->left = x->right;
		x->right = nullptr;
		x->element.first = 1;
	}
	else{
		if( x->left->element.first < x->right->element.first ){
			HbltNode<T> *temp = x->left;
			x->left = x->right;
			x->right = temp;
		}
		x->element.first = x->right->element.first + 1;
	}
}

template<typename T>
void maxHblt<T>::meld(maxHblt<T> &y)
{
	meld(this->root,y.root);
	treeSize += y.treeSize;
	y.root = nullptr;
	y.treeSize = 0;
}

template<typename T>
void maxHblt<T>::push(const T &value)
{
	HbltNode<T> *data = new HbltNode<T>(pair<int,T>(1,value));
	meld(root,data);
	++treeSize;
}

template<typename T>
void maxHblt<T>::pop()
{
	if( empty() )
		throw maxHbltEmpty();
	HbltNode<T> *data = root;
	meld(root->right,root->left);
	--treeSize;
	root = root->right;
	delete data;
	data = nullptr;
}

template<typename T>
void maxHblt<T>::erase(HbltNode<T> *p)
{
	if( p != NULL ){
		erase(p->right);
		HbltNode<T> *temp = p;
		erase(p->left);
		delete p;
		--treeSize;
	}
}

template<typename T>
void maxHblt<T>::clear()
{
	erase(root);
}

template<typename T>
void maxHblt<T>::initialze(T *array,int theSize)
{
	arrayQueue<HbltNode<T>*> q(theSize);
	clear();

	for( int i = 0; i != theSize - 1; ++i )
		q.push(new HbltNode<T>(1,array[i]));
	for( int i = 0; i != theSize; ++i ){
		HbltNode<T> *b = q.front();
		q.pop();
		HbltNode<T> *c = q.front();
		q.pop();
		meld(b,c);
		q.push(b);
	}
	if(theSize > 0)
		root = q.front();
	treeSize = theSize;
}

template<typename T>
maxHblt<T>::maxHblt(const maxHblt<T> &theHblt)
{
	
}

#endif
