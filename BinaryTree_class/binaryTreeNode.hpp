#ifndef _TREENODE_
#define _TREENODE_

#include<iostream>

using namespace std;

template<typename T> class binaryTreeNode{

public:
	T element;
	binaryTreeNode<T> *left;
	binaryTreeNode<T> *right;

	binaryTreeNode() : left(nullptr),right(nullptr) { }
	binaryTreeNode(const T &the_value) : element(the_value),left(nullptr),right(nullptr) { }
	binaryTreeNode(const T &value,binaryTreeNode<T> *lf,binaryTreeNode<T> *rt) :
			element(value),left(lf),right(rt) { }
};

#endif

