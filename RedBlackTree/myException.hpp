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

class illegaParameterValue{

public:
	illegaParameterValue(string theMessage = "parameter value is wrong")
			{ message = theMessage; }
	void outputMessage() { cout<<message<<endl; }
private:
	string message;
};

class AVLtreeEmpty{

public:
	AVLtreeEmpty(string theMessage = "the tree is empty")
			{ message = theMessage; }
	void outputMessage() { cout<<message<<endl; }
private:
	string message;
};

class NotFindDeleteNode{

public:
	NotFindDeleteNode(string theMessage = "Not find delete node")
			{ message = theMessage; }
	void outputMessage() { cout<<message<<endl; }
private:
	string message;
}; 


#endif
