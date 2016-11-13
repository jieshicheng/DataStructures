#ifndef _AVL_NODE_
#define _AVL_NODE_

#include<iostream>
#include<utility>

using namespace std;

template<typename T> class AVL_node{

    public:
	AVL_node() : element(pair<int,T>()),left(nullptr),right(nullptr),bf(0) { }
	AVL_node(const T &); //
	AVL_node(const T &,AVL_node *l,AVL_node *r,int bef);//

	~AVL_node()
	{
		delete left,right;
	}
    private:
	pair<int,T> element;
	AVL_node *left;
	AVL_node *right;
	int bf;
};

template<typename T>
AVL_node<T>::AVL_node(const T &the_element) : left(nullptr),right(nullptr),bf(0)
{
	element = pair<int,T>(the_element / 17,the_element);
}

template<typename T>
AVL_node<T>::AVL_node(const T &the_element,AVL_node *l,AVL_node *r,int bef)
{
	element = pair<int,T>(the_element / 17,the_element);
	left = l;
	right = r;
	bf = bef;
}

#endif
