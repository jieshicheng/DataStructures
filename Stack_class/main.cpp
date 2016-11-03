/************************************

@file    Stack_list
@author  jieshicheng
@data    2 Nov 2016
@remark  stack list by array
@note    this is a test txt


*************************************/

#include"arrayStack.hpp"

#include<iostream>

using namespace std;

int main()
{
	arrayStack<int> vec(5);

	cout<<vec.empty()<<" "<<vec.size()<<endl;

	vec.push(20);
	cout<<vec.top()<<endl;
	vec.pop();
	return 0;
}
