#ifndef _AVL_
#define _AVL_

#include"AVL_Node.hpp"
#include"myException.hpp"

#include<iostream>

using namespace std;

#define LH +1
#define EH 0
#define RH -1

class AVL_tree{
	friend class AVL_node;

    public:
	AVL_tree() : root(nullptr),nodeSize(0) { }
	AVL_tree(AVL_node *the_root,int theSize) : root(the_root),nodeSize(theSize) { }
	
	~AVL_tree() { delete root; }

	bool empty() const { return nodeSize == 0; }
	int size() const { return nodeSize; }
	void insert(const int &,bool *);
	void erase(const int &);//
	AVL_node *find(const int &);
	void output() const;

    private:
	void leftBalance(AVL_node **); 
	void rightBalance(AVL_node **); 
	void R_Rotate(AVL_node **);
	void L_Rotate(AVL_node **);
	bool AVLinsert(AVL_node **,const int &,bool *);
	void midLook(AVL_node *) const;

	AVL_node *root;
	int nodeSize;
};

void AVL_tree::R_Rotate(AVL_node **theRoot)
{

	AVL_node *p;
	p = (*theRoot)->left;
	(*theRoot)->left = p->right;
	p->right = *theRoot;
	*theRoot = p;
}

void AVL_tree::L_Rotate(AVL_node **theRoot)
{
	AVL_node *p;
	p = (*theRoot)->right;
	(*theRoot)->right = p->left;
	p->left = *theRoot;
	*theRoot = p;
}

void AVL_tree::leftBalance(AVL_node **theRoot)
{
	AVL_node *L,*Lr;
	L = (*theRoot)->left;
	switch( L->bf ){
		case LH:
			(*theRoot)->bf = L->bf = EH;
			R_Rotate(theRoot);
			break;
		case RH:
			Lr = L->right;
			switch( Lr->bf ){
				case LH:
					(*theRoot)->bf = RH;
					L->bf = EH;
					break;
				case EH:
					(*theRoot)->bf = L->bf = EH;
					break;
				case RH:
					(*theRoot)->bf = EH;
					L->bf = LH;
					break;
			}
			Lr->bf = EH;
			L_Rotate(&(*theRoot)->left);
			R_Rotate(theRoot);
	}
}

void AVL_tree::rightBalance(AVL_node **theRoot)
{
	AVL_node *L,*Lr;
	L = (*theRoot)->right;
	switch( L->bf){
		case RH:
			(*theRoot)->bf = L->bf = EH;
			L_Rotate(theRoot);
		case LH:
			Lr = L->left;
			switch( Lr->bf ){
				case RH:
					(*theRoot)->bf = EH;
					L->bf = LH;
					break;
				case EH:
					(*theRoot)->bf = L->bf = EH;
					break;
				case LH:
					(*theRoot)->bf = LH;
					L->bf = EH;
					break;
			}
			Lr->bf = EH;
			R_Rotate(&(*theRoot)->right);
			L_Rotate(theRoot);
	}
}

AVL_node *AVL_tree::find(const int &value)
{
	if(empty())
		throw AVLtreeEmpty("AVL tree is empty");
	
	AVL_node *p = root;
	while(p != NULL ){
		if(value > p->element)
			p = p->right;
		else if(value < p->element)
			p = p->left;
		else
			return p;
	}

	return p;
}

bool AVL_tree::AVLinsert(AVL_node **T,const int &key,bool *taller)
{
	if( !*T ){
		*T = new AVL_node(key);
		*taller = true;
	}
	else{
		if(key == (*T)->element){
			*taller = false;
			return false;
		}
		if(key < (*T)->element){
			if( !AVLinsert(&(*T)->left,key,taller) )
				return false;
			if(*taller){
				switch((*T)->bf){
					case LH:
						leftBalance(T);
						*taller = false;
						break;
					case EH:
						(*T)->bf = LH;
						*taller = true;
						break;
					case RH:
						(*T)->bf = EH;
						*taller = false;
						break;
				}
			}
		}
		else{
			if( !AVLinsert(&(*T)->right,key,taller) )
				return false;
			if(*taller){
				switch((*T)->bf){
					case LH:
						(*T)->bf = EH;
						*taller = false;
						break;
					case EH:
						(*T)->bf = RH;
						*taller = true;
						break;
					case RH:
						rightBalance(T);
						*taller = true;
						break;
				}
			}
		}
	}

	return true;
	
}

void AVL_tree::insert(const int &key,bool *taller)
{
	AVLinsert(&root,key,taller);
	++nodeSize;
}
/*
void AVL_tree::erase(const int &key)
{
	AVL_node *p = find(key);
	
}
*/

inline void AVL_tree::midLook(AVL_node *p) const
{
	if( p ){
		midLook(p->left);
		cout<<p->element<<" ";
		midLook(p->right);
	}
}

inline void AVL_tree::output() const
{
	midLook(root);
	cout<<endl;
}









#endif
