#ifndef _AVL_
#define _AVL_

#include"AVL_Node.hpp"

#include<iostream>

using namespace std;

class AVL_tree{

    public:
	AVL_tree() : root(nullptr),nodeSize(0) { }
	AVL_tree(AVL_node *the_root,int theSize) : root(the_root),nodeSize(theSize) { }
	
	~AVL_tree() { delete root; }

	bool empty() const { return nodeSize == 0; }
	int size() const { return nodeSize; }
	void insert(const int &);
	void erase(const int &);
	AVL_node *find(const int &);

    private:
	AVL_node *root;
	int nodeSize;
};

AVL_node *AVL_tree::find(const int &value)
{
	if(empty())
		throw AVLtreeEmpty("AVL tree is empty");
	
	AVL_node *p = root;
	while(p->element != value){
		if(value > p->element)
			p = p->right;
		else
			p = p->left;
	}

	return p;
}

void AVL_tree::insert(const int &key)
{
	if( !find(key) )
		return;

	AVL_node *p = new AVL_node(key);
	p->bf = 0;

	if(empty())
		root = p;
}

void AVL_tree::erase(const int &key)
{
}

#endif
