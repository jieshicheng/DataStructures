#include"hashChain.hpp"

#include<iostream>
#include<utility>

using namespace std;

int main()
{
	hashChain<int,int> vec;
	vec.insert(pair<int,int>(1,2));

	return 0;
}
