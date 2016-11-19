#include"RedBlackTree.hpp"
#include<iostream>

using namespace std;

int main()
{
	rbTree vec;
	for(int i = 10; i != 0; --i)
		vec.Insert(i);
//	vec.Print();

	vec.Find(1);
	vec.Find(4);
	vec.Find(3);
	vec.Find(10);

	vec.Delete(1);
	vec.Print();
	return 0;
}
