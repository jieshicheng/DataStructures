/*******************************************


@file    Linear_list
@author  jieshicheng
@data    1 May 2017
@remark  linear list
@note    this is a test txt


*********************************************/

#include<iostream>
#include"list.hpp"

using namespace std;

/**
 *  test function
 *      echo arrayList<T> element by iterator
 */
template<typename _Type>
void echo(const arrayList<_Type> &arr)
{
    typename arrayList<_Type>::iterator iter = arr.begin();
    while(iter != arr.end())
    {
        cout<<*iter++<<" ";
    }
    cout<<endl;
}

/**
 *  test function
 *      echo arrayList<T> element by index
 */
template<typename _Type>
void print(const arrayList<_Type> &arr)
{
    size_t i = 0, size = arr.size();
    while(i != size)
    {
        cout<<arr.at(i++)<<" ";
    }
    cout<<endl;
}

template<typename _Type>
void output(const arrayList<_Type> &arr)
{
    size_t i = 0, size = arr.size();
    while(i != size)
    {
        cout<<arr[i++]<<" ";
    }
    cout<<endl;
}


int main()
{
    /**
     *  construct function test 
     *  Five ways to construct arrayList   
     *  Outcome:
     *      Successful
     */
    arrayList<int> vec1(20);
    arrayList<int> vec2;
    const arrayList<int> vec3(10, 5);
    arrayList<int> vec4(vec1);
    arrayList<int> *point = new arrayList<int>(20);
    arrayList<int> vec5(move(*point));
    point = nullptr;
    arrayList<string> str1(10);
    arrayList<string> str2(10, "A");

    echo(vec1);
    echo(vec2);
    print(vec3);
    print(vec4);
    print(vec5);
    output(str1);
    output(str2);

    /**
     *  base function
     *  size(), empty()
     *  Outcome:
     *      Successful
     */
    cout<<"size of vec1(arrayList<int>) is: "<<vec1.size()<<endl;
    cout<<"size of vec3(const arrayList<int>) is: "<<vec3.size()<<endl;
    cout<<"whether vec2 is empty?  "<<vec2.empty()<<endl;

    /**
     *  access element function
     *  begin(), end(), at(), operator []()
     *  Outcome:
     *      Successful
     */
    //  echo()    prove by begin(), end()
    //  print()    prove by at()
    //  output()    prove by operator []()

    
    /**
     *  
     *
     *
     */

	return 0;
}
