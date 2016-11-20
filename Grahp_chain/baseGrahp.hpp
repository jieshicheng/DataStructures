#ifndef GRAHP_
#define GRAHP_

#include<iostream>

using namespace std;

template<typename T>
class grahp{

    public:
	virtual ~grahp() { }
	
	virtual int numberOfEdges() const = 0;
	virtual int numberOfVertices() const = 0;
	virtual bool existsEdge(int,int) const = 0;
	virtual void insertEdge()
    private:
	
};


#endif
