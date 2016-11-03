/************************************


@file    matrix class
@author  jieshicheng
@data    2 Nov 2016
@remark  matrix by unary array
@note    this is a test txt


************************************/

#include"matrix.hpp"

#include<iostream>

using namespace std;

int main()
{
	matrix<int> vec(5,5);
	matrix<int> vec2(vec);
	vec2 = vec;
	cout<<vec2.rows()<<" "<<vec2.cols()<<endl;
	cout<<vec2(1,2)<<endl;
	cout<<(vec + vec2)<<endl;
	return 0;
}
