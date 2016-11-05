#ifndef _HASH_
#define _HASH_

#include<iostream>

using namespace std;


class hash{

public:
	size_t operator()(const int theKey) const
	{
		return static_cast<size_t>(theKey);
	}

};

#endif
