/*******************************************

@file     hashTable
@author   jieshicheng
@data     5 Nov 2016
@remark   hashTable by array
@note     this is a test txt




*********************************************/


#include"hashTable.hpp"

#include<iostream>
#include<utility>

using namespace std;

int main()
{
	hashTable<int,string> vec;
	vec.insert(pair<int,string>(1,"cheng"));

	return 0;
}
