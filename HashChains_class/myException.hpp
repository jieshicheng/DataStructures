#ifndef _EXCEPTION_
#define _EXCEPTION_

#include<iostream>
#include<string>

using namespace std;

class hashTableFull{

public:
	hashTableFull(string theMessage = "the hash table is full")
			{ message = theMessage; }
	void outputMessage() { cout<<message<<endl; }
private:
	string message;
};


class hashChainNofind{

public:
	hashChainNofind(string theMessage = "the hash chain is no find")
			{ message = theMessage; }
	void outputMessage() { cout<<message<<endl; }
private:
	string message;
};
#endif
