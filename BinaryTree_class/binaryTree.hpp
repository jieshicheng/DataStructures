#ifndef _BINARYTREE_
#define _BINARYTREE_

#include"binaryTreeNode.hpp"

#include<iostream>

using namespace std;

template<typename T> class binaryTree{

public:
	virtual ~binaryTree() { }
	virtual bool empty() const =0;
	virtual int size() const =0;
	virtual void preOrder(void (*)(binaryTreeNode<T> *)) =0;
	virtual void inOrder(void (*)(binaryTreeNode<T> *)) =0;
	virtual void postOrder(void (*)(binaryTreeNode<T> *)) =0;
};

//********************************************************************


template<typename T> class linkedBinaryTree : public binaryTree<T>{
	typedef void (*Visit)(binaryTreeNode<T> *);
public:
//construct function
	linkedBinaryTree() : root(nullptr),treeSize(0) { }
	~linkedBinaryTree() { erase(); }

//ADT
	bool empty() const { return treeSize == 0; }
	int size() const { return treeSize; }
	void preOrder(void (*theVisit)(binaryTreeNode<T> *))
			{ visit = theVisit; preOrder(root); }
	void inOrder(void (*theVisit)(binaryTreeNode<T> *))
			{ visit = theVisit; inOrder(root); }
	void postOrder(void (*theVisit)(binaryTreeNode<T> *))
			{ visit = theVisit; postOrder(root); }
	void erase()
	{
		postOrder(dispose);
		root = NULL;
		treeSize = 0;
	}

private:
	binaryTreeNode<T> *root;
	int treeSize;
	static Visit visit;	

	static void preOrder(binaryTreeNode<T> *);
	static void inOrder(binaryTreeNode<T> *);
	static void postOrder(binaryTreeNode<T> *);
	static void dispose(binaryTreeNode<T> *t) { delete t; }
};
template<typename T>
typename linkedBinaryTree<T>::visit = NULL;

#endif

template<typename T>
void linkedBinaryTree<T>::preOrder(binaryTreeNode<T> *theRoot)
{
	if( theRoot != NULL ){
		linkedBinaryTree<T>::visit(theRoot);
		preOrder(theRoot->left);
		preOrder(theRoot->right);
	}
}

template<typename T>
void linkedBinaryTree<T>::inOrder(binaryTreeNode<T> *theRoot)
{
	if( theRoot != NULL ){
		linkedBinaryTree<T>::visit(theRoot);
		inOrder(theRoot->left);
		inOrder(theRoot->right);
	}
}

template<typename T>
void linkedBinaryTree<T>::postOrder(binaryTreeNode<T> *theRoot)
{
	if( theRoot != NULL ){
		linkedBinaryTree<T>::visit(theRoot);
		postOrder(theRoot->left);
		postOrder(theRoot->right);
	}

}
