#include<iostream>
#include"list.hpp"

using namespace std;

int main()
{
	arrayList<int> vec(20);
	
	cout<<vec.empty()<<endl;
	cout<<vec.size()<<endl;
	cout<<vec<<endl;

	vec.insert(0,4);
	vec.insert(1,2);
	vec.erase(1);
	cout<<vec.indexOf(4)<<endl;
	cout<<vec.get(0)<<endl;

	cout<<vec<<endl;

	return 0;
}
