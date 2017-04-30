#include <iostream>

template<typename _Type> class linearList{

public:
    typedef _Type value_type;
    typedef _Type* iterator;

	virtual ~linearList() { }
	virtual bool empty() const = 0;
    virtual size_t size() const = 0;
};
