#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#include"linear.hpp"
#include <iostream>
#include <algorithm>

template<typename _Type> 
class arrayList : public linearList<_Type>
{
public:
    using value_type = typename linearList<_Type>::value_type;
    using iterator = typename linearList<_Type>::iterator;

    arrayList();
    arrayList(size_t initialCapacity);
    arrayList(size_t initialCapacity, const value_type &ele);
    arrayList(const arrayList<_Type> &obj);
    arrayList(arrayList<_Type> &&obj);
    virtual ~arrayList();

    virtual bool empty() const
    {
        return length == 0;
    }
    virtual size_t size() const
    {
        return length;
    }

    //get element in array by index
    value_type &at(size_t theIndex);

    //get const or no-const iterator point to begin and end
    iterator begin()
    {
        return start;
    }
    iterator end()
    {
        return over;
    }
    const iterator cbegin() const
    {
        return const_cast<const iterator>(start);
    }
    const iterator cend() const
    {
        return const_cast<const iterator>(over);
    }

    //erase single element or area
    iterator erase(iterator index);
    iterator erase(iterator _begin, iterator _end);
    void pop_back();

    //insert single/repeat element in special postion
    iterator insert(iterator theIndex,const _Type &ele);
    iterator insert(iterator pos, size_t number, const value_type &ele);
    void push_back();

    value_type &operator [](size_t index);
    arrayList &operator =(const arrayList<_Type> &rhs);
    arrayList &operator =(arrayList<_Type> &&rhs);
    bool operator ==(const arrayList<_Type> &rhs);
    bool operator !=(const arrayList<_Type> &rhs);
    bool operator < (const arrayList<_Type> &rhs);
    bool operator > (const arrayList<_Type> &rhs);
    bool operator <=(const arrayList<_Type> &rhs);
    bool operator >=(const arrayList<_Type> &rhs);

private:
    bool checkIndex(size_t theIndex) const;
    void destory();
    void init(size_t size);
private:
    value_type *element;

    iterator start;
    iterator over;

    size_t length;
    size_t capacity;

};

template<typename _Type>
void arrayList<_Type>::init(size_t size)
{
    element = new _Type[size];
    length = 0;
    capacity = size;
    start = element;
    over = start;
}

template<typename _Type>
arrayList<_Type>::arrayList()
{
    init(20);
}

template<typename _Type>
arrayList<_Type>::arrayList(size_t initialCapacity)
{
    init(2 * initialCapacity);
    length = initialCapacity;
    std::fill(element, element + length, value_type());
    over = start + length;
}

template<typename _Type>
arrayList<_Type>::arrayList(const arrayList<_Type> &rhs)
{
    init(rhs.capacity);
    length = rhs.length;
    std::copy(rhs.element, rhs.element + length, element);
    over = start + length;
}

template<typename _Type>
arrayList<_Type>::arrayList(size_t initialCapacity, const value_type &ele)
{
    init(2 * initialCapacity);
    length = initialCapacity;
    std::fill(element, element + length, ele);
    over = start + length;
}

template<typename _Type>
arrayList<_Type>::arrayList(arrayList<_Type> &&rhs)
{
    element = rhs.element;
    length = rhs.length;
    capacity = rhs.capacity;
    start = rhs.start;
    over = rhs.over;
}


template<typename _Type>
arrayList<_Type>::~arrayList()
{
    destory();
}


template<typename _Type>
bool arrayList<_Type>::checkIndex(size_t theIndex) const
{
    if(theIndex >= length){
        std::cout<<"Error: index is not exist"<<std::endl;
        return false;
    }
    else
        return true;
}

template<typename _Type>
void arrayList<_Type>::destory()
{
    delete []element;
    start = nullptr;
    over = nullptr;
    length = 0;
    capacity = 0;
}

template<typename _Type>
typename arrayList<_Type>::value_type &arrayList<_Type>::at(size_t theIndex)
{
    if( checkIndex(theIndex) )
        return element[theIndex];
}


template<typename _Type>
typename arrayList<_Type>::iterator arrayList<_Type>::erase(iterator theIndex)
{
    std::copy(theIndex + 1, over,theIndex);
    --length;
    --over;
}

template<typename _Type>
typename arrayList<_Type>::iterator arrayList<_Type>::erase(iterator _begin, iterator _end)
{
    std::copy(_end, over, _begin);
    length = length - (_end - _begin);
    over = start + length;
}

template<typename _Type>
void arrayList<_Type>::pop_back()
{
    --length;
    --over;
}


template<typename _Type>
typename arrayList<_Type>::iterator arrayList<_Type>::insert(iterator theIndex, const _Type &ele)
{

}


#endif
