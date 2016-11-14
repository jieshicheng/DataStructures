#include"AVL_Tree.hpp"

#include<iostream>

using namespace std;

int main()
{
	AVL_tree tree;
	bool *taller = new bool();
	for( int i = 0; i != 5; ++i ){
		tree.insert(i,taller);
	}
	tree.output();
	if( tree.find(5) )
		cout<<"true"<<endl;

	cout<<tree.empty()<<" "<<tree.size()<<endl;

	return 0;
}
