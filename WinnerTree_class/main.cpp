/**********************************************

@file       winnerTree
@author     jieshicheng
@data       12 Nov 2016
@remark     winnerTree by array
@note       this is a test txt

**********************************************/

#include"winnerTree.hpp"

int main()
{
	int *play = new int[8]{1,2,3,4,5,6,7,8};
	winnerTree<int> vec;

	vec.initialize(play,8);
	vec.output();
	return 0;
}
