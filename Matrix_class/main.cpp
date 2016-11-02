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
