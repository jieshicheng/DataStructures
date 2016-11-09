#ifndef _EXCEPTION_
#define _EXCEPTION_

#include<iostream>

using namespace std;

class hashTableFull{

public:
	hashTableFull(string theMessage = "the hash table is full")
			{ message = theMessage; }
	void outputMessage() { cout<<message<<endl; }
private:
	string message;
};

class maxHbltEmpty{

public:
	maxHbltEmpty(string theMessage = "max hblt is empty")
			{ message = theMessage; }
private:
	string message;
};

class queueEmpty{

public:
	queueEmpty(string theMessage = "the queue is empty")
			{ message = theMessage; }
	void outputMessage() { cout<<message<<endl; }
private:
	string message;
};

class illegalParameterValue{

public:
	illegalParameterValue(string s = "illegal parameter")
			{ message = s; }
private:
	string message;
};

#endif
