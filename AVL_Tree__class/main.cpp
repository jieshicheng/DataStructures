#include"AVL_tree.hpp"

#include<iostream>

using namespace std;

int main()
{
	AVLTree tree;
	for( int i = 0; i != 20; ++i )
		tree.insert(i);
	cout<<"preOrder :";
	tree.preOrder();
	cout<<"InOrder :";
	tree.InOrder();
	cout<<"postOrder :";
	tree.postOrder();

	tree.remove(19);
	tree.InOrder();

	return 0;
}
