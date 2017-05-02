/*******************************************


@file    Linear_list
@author  jieshicheng
@data    1 Nov 2016
@remark  linear list
@note    this is a test txt


*********************************************/

#include<iostream>
#include"list.hpp"

using namespace std;

int main()
{
    //construct function test 
	arrayList<int> vec1(20);
    arrayList<int> vec2;
    arrayList<int> vec3(10, 5);
    arrayList<int> vec4(vec1);
    arrayList<int> *point = new arrayList<int>(20);
    arrayList<int> vec5(move(*point));
    point = nullptr;

    /*
    //erase function
    vec1.pop_back();
    cout<<vec1.size()<<endl;
    vec1.erase(vec1.begin());
    cout<<vec1.size()<<endl;
    vec1.erase(vec1.begin(), vec1.end());
    cout<<vec1.size()<<endl;
    size_t size = vec3.size();
    for(size_t i = 0; i != size; ++i)
    {
        vec3.pop_back();
    }
    cout<<endl<<vec3.size()<<endl;
    
    //get element by index

    */


    vec1.insert(vec1.begin(), 10, 4);
    cout<<vec1.size()<<endl;
    cout<<vec1.at(1);



	return 0;
}
