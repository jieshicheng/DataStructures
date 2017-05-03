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
    explicit arrayList(size_t initialCapacity);
    arrayList(size_t initialCapacity, const value_type &ele);
    arrayList(const arrayList<_Type> &obj);
    arrayList(arrayList<_Type> &&obj);
    virtual ~arrayList();

    virtual bool empty()
    {
        return length == 0;
    }
    virtual bool empty() const
    {
        return length == 0;
    }
    virtual size_t size()
    {
        return length;
    }
    virtual size_t size() const
    {
        return length;
    }

    //get element in array by index
    value_type &at(size_t theIndex);
    const value_type &at(size_t theIndex) const;    //

    //get const or no-const iterator point to begin and end
    iterator begin()
    {
        return start;
    }
    iterator end()
    {
        return over;
    }
    const iterator begin() const
    {
        return const_cast<const iterator>(start);
    }
    const iterator end() const
    {
        return const_cast<const iterator>(over);
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
    void push_back(const value_type &ele);

    value_type &operator [](size_t index);
    const value_type &operator [](size_t index) const;
    arrayList &operator =(const arrayList<_Type> &rhs);
    arrayList &operator =(arrayList<_Type> &&rhs);
    bool operator ==(const arrayList<_Type> &rhs);
    bool operator !=(const arrayList<_Type> &rhs);
    bool operator < (const arrayList<_Type> &rhs);
    bool operator > (const arrayList<_Type> &rhs);
    bool operator <=(const arrayList<_Type> &rhs);
    bool operator >=(const arrayList<_Type> &rhs);

private:
    void recalloc(size_t initialCapacity);
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
const typename arrayList<_Type>::value_type &arrayList<_Type>::at(size_t theIndex) const
{
    if( checkIndex(theIndex) )
        return const_cast<const value_type &>(element[theIndex]);
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
void arrayList<_Type>::recalloc(size_t initialCapacity)
{
    iterator point = new value_type[initialCapacity];
    std::copy(start, over, point);
    delete []element;
    element = point;
    start = element;
    over = element + length;
    capacity = initialCapacity;
}

template<typename _Type>
typename arrayList<_Type>::iterator arrayList<_Type>::insert(iterator theIndex, const _Type &ele)
{
    if(length == capacity)
    {
        size_t distance = theIndex - start;
        recalloc(2 * capacity);
        theIndex = start + distance;
    }
    if(over != theIndex)
        std::copy(theIndex, over, theIndex + 1);
    *theIndex = ele;
    over++;
    length++;
    return theIndex;
}

template<typename _Type>
typename arrayList<_Type>::iterator arrayList<_Type>::insert(iterator theIndex, size_t number, const value_type &ele)
{
    if(length + number > capacity)
    {
        size_t distance = theIndex - start;
        recalloc(2 * (length + number));
    }
    std::copy(theIndex, over, theIndex + number);
    std::fill(theIndex, theIndex + number, ele);
    length = length + number;
    over += number;
    return theIndex;
}

template<typename _Type>
void arrayList<_Type>::push_back(const value_type &ele)
{
    if(length == capacity)
    {
        recalloc(2 * capacity);
    }
    *over++ = ele;
    length++;
}

template<typename _Type>
typename arrayList<_Type>::value_type &arrayList<_Type>::operator [](size_t index)
{
    if( checkIndex(index) )
        return element[index];
}

template<typename _Type>
const typename arrayList<_Type>::value_type &arrayList<_Type>::operator [](size_t index) const
{
    if( checkIndex(index) )
        return const_cast<const value_type &>(element[index]);
}

template<typename _Type>
arrayList<_Type> &arrayList<_Type>::operator =(const arrayList<_Type> &rhs)
{
    delete []element;
    init(rhs.capacity);
    length = rhs.length;
    std::copy(rhs.start, rhs.over, element);
    start = element;
    over = element + over;
    return *this;
}

template<typename _Type>
arrayList<_Type> &arrayList<_Type>::operator =(arrayList<_Type> &&rhs)
{
    delete []element;
    element = rhs.element;
    length = rhs.length;
    capacity = rhs.capacity;
    start = rhs.start;
    over = rhs.over;
}

template<typename _Type>
bool arrayList<_Type>::operator ==(const arrayList<_Type> &rhs)
{
    if(length != rhs.length)
        return false;
    else
    {
        size_t size = length;
        for(size_t i = 0; i != size; ++i)
        {
            if((*this)[i] != rhs[i])
                return false;
        }
    }
    return true;
}

template<typename _Type>
bool arrayList<_Type>::operator !=(const arrayList<_Type> &rhs)
{
    return !(this->operator ==(rhs));
}

template<typename _Type>
bool arrayList<_Type>::operator <(const arrayList<_Type> &rhs)
{
    size_t i, size = min(rhs.length, length);
    for(i = 0; i != size; ++i)
    {
        if((*this)[i] > rhs[i])
            return false;
    }
    return length < rhs.length;
}


template<typename _Type>
bool arrayList<_Type>::operator >(const arrayList<_Type> &rhs)
{
    return !(this->operator <(rhs));
}

template<typename _Type>
bool arrayList<_Type>::operator <=(const arrayList<_Type> &rhs)
{
    return (this->operator <(rhs) || this->operator ==(rhs));
}

template<typename _Type>
bool arrayList<_Type>::operator >=(const arrayList<_Type> &rhs)
{
    return (this->operator >(rhs) || this->operator ==(rhs));
}

#endif
