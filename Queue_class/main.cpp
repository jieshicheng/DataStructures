/*********************************************

@file     Queue_class
@author   jieshicheng
@data     3 Nov 2016
@remark   array queue
@note     this is a test txt

***********************************************/

#include"arrayQueue.hpp"

#include<iostream>

using namespace std;

int main()
{
	arrayQueue<int> vec(5);

	cout<<vec.empty()<<" "<<vec.size()<<endl;

	vec.push(10);
	vec.push(20);
	cout<<vec.front()<<" "<<vec.back()<<endl;
	vec.pop();
	vec.pop();
	cout<<vec.empty();
	return 0;
}
