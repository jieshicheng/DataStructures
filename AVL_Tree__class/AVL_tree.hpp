#ifndef _AVLT_
#define _AVLT_

#include<iostream>
#include<cmath>

#include"myException.hpp"
#include"AVL_Node.hpp"

using namespace std;

class AVLTree{
	friend class AVL_node;
    public:
	AVLTree(): root(nullptr) { }
	~AVLTree() 
	{
		destory();
	}

	void preOrder() const;
	void InOrder() const;
	void postOrder() const;

	void destory();
	
	void insert(const int &key);
	void remove(const int &key);
	
	AVL_node *search_recurse(const int &key) const;
	
	int minmum() const;
	int maxmum() const;

	int height() const;
    private:
	void preOrder(AVL_node *node) const;
	void inOrder(AVL_node *node) const;
	void postOrder(AVL_node *node) const;

	void destory(AVL_node* &node);

	AVL_node *insert(AVL_node* &node,const int &key);
	AVL_node *remove(AVL_node* &node,const int &key);

	AVL_node *minmum(AVL_node *node) const;
	AVL_node *maxmum(AVL_node *node) const;

	AVL_node *search_recurse(AVL_node *node,const int &key) const;

	AVL_node *leftRotation(AVL_node *node);
	AVL_node *rightRotation(AVL_node *node);
	AVL_node *leftRightRotation(AVL_node *node);
	AVL_node *rightLeftRotation(AVL_node *node);

	int height(AVL_node *node) const;
    private:
	AVL_node *root;
};

inline int AVLTree::height(AVL_node *node) const
{
	if(node != NULL)
		return node->height;
	return 0;
}

inline int AVLTree::height() const
{
	return height(root);
}

AVL_node *AVLTree::leftRotation(AVL_node *node)
{
	AVL_node *L = node->right;
	node->right = L->left;
	L->left = node;

	node->height = max(height(node->left),height(node->right)) + 1;
	L->height = max(height(L->left),height(L->right)) + 1;

	return L;
}

AVL_node *AVLTree::rightRotation(AVL_node *node)
{
	AVL_node *R = node->left;
	node->left = R->right;
	R->right = node;

	node->height = max(height(node->left),height(node->right)) + 1;
	R->height = max(height(R->left),height(R->right)) + 1;
}

AVL_node *AVLTree::leftRightRotation(AVL_node *node)
{
	node->left = leftRotation(node->left);
	return rightRotation(node);
}

AVL_node *AVLTree::rightLeftRotation(AVL_node *node)
{
	node->right = rightRotation(node->right);
	return leftRotation(node);
}

AVL_node *AVLTree::insert(AVL_node* &node,const int &key)
{
	if(node == NULL){
		node = new AVL_node(key,nullptr,nullptr);
	}
	else if(key > node->element){
		node->right = insert(node->right,key);
		if(height(node->right) - height(node->left) == 2){
			if(key > node->right->element)
				node = leftRotation(node);
			else if(key < node->right->element)
				node = rightLeftRotation(node);
		}

	}
	else if(key < node->element){
		node->left = insert(node->left,key);
		if(height(node->left) - height(node->right) == 2){
			if(key < node->left->element)
				node = rightRotation(node);
			else if(key > node->left->element)
				node = leftRightRotation(node);
		}
	}
	node->height = max(height(node->left),height(node->right)) + 1;
	return node;
}

void AVLTree::insert(const int &key)
{
	insert(root,key);
}

void AVLTree::destory(AVL_node* &node)
{
	if(node != NULL){
		destory(node->left);
		destory(node->right);
		delete node;
		node = nullptr;
	}
}

void AVLTree::destory()
{
	destory(root);
}

AVL_node *AVLTree::search_recurse(AVL_node *node,const int &key) const
{
	if(node != nullptr){
		if(key == node->element)
			return node;
		else if(key < node->element)
			return search_recurse(node->left,key);
		else
			return search_recurse(node->right,key);
	}
	return nullptr;
}

AVL_node *AVLTree::search_recurse(const int &key) const
{
	return search_recurse(root,key);
}

AVL_node *AVLTree::remove(AVL_node* &node,const int &key)
{
	if(node != NULL){
		if(node->element == key){
			if(node->left != NULL && node->right != NULL){
				if(height(node->left) > height(node->right)){
					AVL_node *p1 = maxmum(node->left);
					node->element = p1->element;
					
					node->left = remove(node->left,p1->element);
				}
				else{
					AVL_node *p2 = minmum(node->right);
					node->element = p2->element;

					node->right = remove(node->right,p2->element);
				}
			}
			else{
				AVL_node *temp = node;
				if(node->left == nullptr)
					node = node->right;
				else if(node->right == nullptr)
					node = node->left;
				delete temp;
				temp = nullptr;
			}
		}
		else if(key > node->element){
			node->right = remove(node->right,key);
			if(height(node->left) - height(node->right) == 2){
				if(height(node->left->right) > height(node->left->left))
					node = leftRightRotation(node);
				else
					node = leftRotation(node);
			}
		}
		else if(key < node->element){
			node->left = remove(node->left,key);
			if(height(node->right) - height(node->left) == 2){
				if(height(node->right->left) > height(node->right->right))
					node = rightLeftRotation(node);
				else
					node = rightRotation(node);
			}
		}
		return node;
	}
	
	return nullptr;
}

void AVLTree::remove(const int &key)
{
	remove(root,key);
}

AVL_node *AVLTree::minmum(AVL_node *node) const
{
	if(node == nullptr)
		throw AVLtreeEmpty("tree is empty,no minmum");
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}

AVL_node *AVLTree::maxmum(AVL_node *node) const
{
	if(node == nullptr)
		throw AVLtreeEmpty("tree is empty,no maxmum");
	while(node->right != NULL){
		node = node->right;
	}
	return node;
}

int AVLTree::minmum() const
{
	return (minmum(root))->element;
}

int AVLTree::maxmum() const
{
	return (maxmum(root))->element;
}

void AVLTree::preOrder(AVL_node *node) const
{
	if(node != NULL){
		cout<<node->element<<" ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void AVLTree::preOrder() const
{
	preOrder(root);
	cout<<endl;
}

void AVLTree::inOrder(AVL_node *node) const
{
	if(node != NULL){
		inOrder(node->left);
		cout<<node->element<<" ";
		inOrder(node->right);
	}
}

void AVLTree::InOrder() const
{
	inOrder(root);
	cout<<endl;
}

void AVLTree::postOrder(AVL_node *node) const
{
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		cout<<node->element<<" ";
	}
}

void AVLTree::postOrder() const
{
	postOrder(root);
	cout<<endl;
}


#endif
