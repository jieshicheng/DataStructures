#ifndef _RBTREENODE_
#define _RBTREENODE_

#include<iostream>
#include"RedBlackTree.hpp"

using namespace std;

enum COLOR {RED,BLACK};


class TreeNode{
	friend class rbTree;
    public:
	TreeNode() : element(0),color(RED),left(nullptr),right(nullptr),parent(nullptr) { }
	TreeNode(const int &key) : element(key),color(RED),left(nullptr),right(nullptr),parent(nullptr) { }
	TreeNode(const int &key,COLOR theColor,TreeNode *l,TreeNode *r,TreeNode *p) :
			element(key),color(theColor),left(l),right(r),parent(p) { }
	~TreeNode()
	{
		delete left,right,parent;
	}

	TreeNode &operator =(TreeNode &rhs)
	{
		this->element = rhs.element;
		this->parent = rhs.parent;
		this->left = rhs.left;
		this->right = rhs.right;
		this->color = rhs.color;
		return *this;
	}
    private:
	int element;
	COLOR color;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
};

#endif
