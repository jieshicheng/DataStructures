#ifndef _RBTREE_
#define _RBTREE_

#include"myException.hpp"
#include"rbTreeNode.hpp"

#include<iostream>

using namespace std;

#define INF 0x7FFFFFFF

TreeNode *NULL_ptr = new TreeNode(INF,BLACK,nullptr,nullptr,nullptr);

class rbTree{
	friend class TreeNode;
    public:
	rbTree();  //
	~rbTree();  //

	int Insert(const int &key);
	int Delete(const int &key);
	TreeNode *Find(const int &key) const;
	void Print() const;  //preOrder
	int Size() { return theSize; }  //
	int maxmum() const;  //
	int minmum() const;  //
	
    private:
	void RB_Insert_FixedUp(TreeNode *node);
	void RB_Delete_FixedUp(TreeNode *node);

	void RB_Left_Rotate(TreeNode *node);
	void RB_Right_Rotate(TreeNode *node);

	void RB_Print(TreeNode *node) const; //preOrder

	void TransPlant(TreeNode *u,TreeNode *v);

	TreeNode *maxmum(TreeNode *node) const; //
	TreeNode *minmum(TreeNode *node) const; //

    private:
	TreeNode *root;
	TreeNode *empty_ptr;
	int theSize;
	
};

inline rbTree::rbTree()
{
	root = empty_ptr = NULL_ptr;
	theSize = 0;
}

inline rbTree::~rbTree()
{
	delete root;
	delete empty_ptr;
}

inline void rbTree::RB_Print(TreeNode *node) const
{
	if(node != NULL_ptr){
		RB_Print(node->left);
		cout<<node->element;
		RB_Print(node->right);
	}
}

inline void rbTree::Print() const
{
	RB_Print(root);
}

inline TreeNode *rbTree::maxmum(TreeNode *node) const
{
	while(node != NULL_ptr){
		node = node->right;
	}
	return node->parent;
}

inline int rbTree::maxmum() const
{
	return (maxmum(root))->element;
}

inline TreeNode *rbTree::minmum(TreeNode *node) const
{
	while(node != NULL_ptr){
		node = node->left;
	}
	return node->parent;
}

inline int rbTree::minmum() const
{
	return (minmum(root))->element;
}

#endif
