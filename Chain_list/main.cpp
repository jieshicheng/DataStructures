/**********************************

@file    main.cpp
@author  jieshicheng
@data    1 Nov 2016
@remark  chain list template
@note    this is a test txt

**********************************/

#include"chain_list.hpp"

#include<iostream>

using namespace std;

int main()
{
	chainList<int> vec;
	cout<<vec.empty()<<" "<<vec.size()<<endl;

	vec.insert(0,5);
	vec.insert(0,4);
	cout<<vec.get(0)<<" "<<vec.indexOf(4)<<endl;
	vec.erase(0);
	vec.push_back(6);	
	cout<<vec;
	return 0;
}
