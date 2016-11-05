/***************************************

@file    skip list class
@author  jieshicheng
@data    5 Nov 2016
@remark  skip list by link list
@note    this is a test txt

***************************************/

#include"skipList.hpp"

#include<iostream>

using namespace std;

int main()
{
	skipList<int,int> vec(999,100,0.5);

	for(int i = 0; i != 10; ++i)
		vec.insert(pair<int,int>(i,i+1));

	vec.erase(9);
	cout<<vec.find(2)->first<<" "<<endl;;
	cout<<vec.empty()<<" "<<vec.size()<<endl;	
	return 0;
}
