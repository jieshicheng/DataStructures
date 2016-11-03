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
