#ifndef _RBTREE_
#define _RBTREE_

#include"myException.hpp"
#include"rbTreeNode.hpp"

#include<iostream>

using namespace std;

#define INF 0x7FFFFF

TreeNode *NULL_ptr = new TreeNode(INF,BLACK,nullptr,nullptr,nullptr);

class rbTree{
	friend class TreeNode;
    public:
	rbTree();  //
	~rbTree();  //

	void Insert(const int &key);  //
	void Delete(const int &key);
	TreeNode *Find(const int &key) const;
	void Print() const;  //preOrder
	int Size() { return theSize; }  //
	int maxmum() const;  //
	int minmum() const;  //
	
    private:
	void RB_Insert(const int &key); //
	void RB_Delete(const int &key);

	void RB_Insert_FixedUp(TreeNode *node);  //
	void RB_Delete_FixedUp(TreeNode *node);

	void RB_Left_Rotate(TreeNode *node); //
	void RB_Right_Rotate(TreeNode *node);  //

	void RB_Print(TreeNode *node) const; //preOrder

	void TransPlant(TreeNode *u,TreeNode *v);

	TreeNode *maxmum(TreeNode *node) const; //
	TreeNode *minmum(TreeNode *node) const; //

	void destoryTree(TreeNode *node);
    private:
	TreeNode *root;
	TreeNode *empty_ptr;
	int theSize;
	
};

void rbTree::destoryTree(TreeNode *node)
{
	if(node != NULL_ptr){
		destoryTree(node->left);
		TreeNode *temp = node;
		destoryTree(node->right);
	
		delete temp;
	}
}


inline rbTree::rbTree()
{
	root = nullptr;
	empty_ptr = NULL_ptr;
	theSize = 0;
}


inline rbTree::~rbTree()
{
	destoryTree(root);
	delete empty_ptr;

	root = empty_ptr = nullptr;
}


inline void rbTree::RB_Print(TreeNode *node) const
{
	if(node != NULL_ptr){
		RB_Print(node->left);
		cout<<node->element<<" color is"<<node->color<<" parent is"<<node->parent->element<<endl;
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

void rbTree::RB_Left_Rotate(TreeNode *node)
{

	TreeNode *temp = node->right;
	node->right = temp->left;

	if(temp->left != NULL_ptr)
		temp->left->parent = node;
	temp->parent = node->parent;

	if(node->parent == NULL_ptr)
		this->root = temp;
	else if(node == node->parent->left)
		node->parent->left = temp;
	else
		node->parent->right = temp;
	temp->left = node;
	node->parent = temp;
}

void rbTree::RB_Right_Rotate(TreeNode *node)
{

	TreeNode *temp = node->left;
	node->left = temp->right;

	if(temp->right != NULL_ptr)
		temp->right->parent = node;
	temp->parent = node->parent;

	if(node->parent == NULL_ptr)
		this->root = temp;
	else if(node == node->parent->left)
		node->parent->left = temp;
	else
		node->parent->right = temp;
	temp->right = node;
	node->parent = temp;
}

void rbTree::RB_Insert_FixedUp(TreeNode *node)
{
	TreeNode *temp = node;

	while(temp->parent->color == RED){
		if(temp->parent == temp->parent->parent->left){
			if(temp->parent->parent->right->color == RED){
				temp->parent->color = BLACK;
				temp->parent->parent->right->color = BLACK;
				if(temp->parent->parent != this->root)
					temp->parent->parent->color = RED;
				temp = temp->parent->parent;
			}
			else{
				if(temp == temp->parent->right){
					temp = temp->parent;
					RB_Left_Rotate(temp);
				}
				temp->parent->color = BLACK;
				temp->parent->parent->color = RED;
				RB_Right_Rotate(temp->parent->parent);
			}
		}
		else{
			if(temp->parent->parent->left->color == RED){
				temp->parent->color = BLACK;
				temp->parent->parent->left->color = BLACK;
				if(temp->parent->parent != this->root)
					temp->parent->parent->color = RED;
				temp = temp->parent->parent;
			}
			else{
				if(temp == temp->parent->left){
					temp = temp->parent;
					RB_Right_Rotate(temp);
				}
				temp->parent->color = BLACK;
				temp->parent->parent->color = RED;
				RB_Left_Rotate(temp->parent->parent);
			}
		}
	}
	this->root->color = BLACK;
	return ;
}

void rbTree::RB_Insert(const int &key)
{
	TreeNode *data = new TreeNode(key,RED,NULL_ptr,NULL_ptr,NULL_ptr);

	if(this->root == nullptr){
		data->color = BLACK;
		this->root = data;
		return ;
	}
	
	TreeNode *y = this->root;
	TreeNode *p = this->root;
	while(p != NULL_ptr){
		y = p;
		if(key > p->element)
			p = p->right;
		else if(key == p->element)
			return ;
		else
			p = p->left;
	}

	data->parent = y;
	if(y->element > key)
		y->left = data;
	else
		y->right = data;


	RB_Insert_FixedUp(data);
	
}

inline void rbTree::Insert(const int &key)
{
	RB_Insert(key);
	cout<<"insert successful"<<endl;
}
#endif
