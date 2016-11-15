#ifndef _AVL_NODE_
#define _AVL_NODE_

#include<iostream>

using namespace std;

class AVL_node{

	friend class AVLTree;
    public:
	AVL_node(int key,AVL_node *l,AVL_node *r) : element(key),left(l),right(r) { }

	~AVL_node()
	{
		delete left,right;
	}
    private:
	int element;
	AVL_node *left;
	AVL_node *right;
	int height;
};


#endif
