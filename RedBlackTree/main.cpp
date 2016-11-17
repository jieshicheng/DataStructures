#include"RedBlackTree.hpp"
#include<iostream>

using namespace std;

int main()
{
	rbTree vec;
	for(int i = 10; i != 0; --i)
		vec.Insert(i);
	vec.Print();
	return 0;
}
