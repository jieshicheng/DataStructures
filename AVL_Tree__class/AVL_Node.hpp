#ifndef _AVL_NODE_
#define _AVL_NODE_

#include<iostream>
#include<utility>

using namespace std;

class AVL_node{

	friend class AVL_tree;
    public:
	AVL_node() : element(0),left(nullptr),right(nullptr),bf(0) { }
	AVL_node(const int &); //
	AVL_node(const int &,AVL_node *l,AVL_node *r,int bef);//

	~AVL_node()
	{
		delete left,right;
	}
    private:
	int element;
	AVL_node *left;
	AVL_node *right;
	int bf;
};

AVL_node::AVL_node(const int &the_element) : left(nullptr),right(nullptr),bf(0)
{
	element = the_element;
}

AVL_node::AVL_node(const int &the_element,AVL_node *l,AVL_node *r,int bef)
{
	element = the_element;
	left = l;
	right = r;
	bf = bef;
}

#endif
