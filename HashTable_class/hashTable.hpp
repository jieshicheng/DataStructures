#ifndef _HASHTABLE_
#define _HASHTABLE_

#include<iostream>
#include<string>
#include<utility>
#include"myException.hpp"

using namespace std;

template<typename K,typename E> class hashTable{

public:
	hashTable(int initialCapacity = 11);
	~hashTable() { delete []table; }

	bool empty() const { return dSize == 0; }
	int size() const { return dSize; }
	pair<const K,E> *find(const K &) const;
	void insert(const pair<const K,E> &the_pair);
private:
	int search(const K &) const;

	pair<K,E> **table;
	int dSize;
	int divisor;
};

#endif

template<typename K,typename E>
int hashTable<K,E>::search(const K &the_key) const
{
	int i = the_key % divisor;
	int j = i;
	do{
		if( table[j]->first == the_key || table[j] == NULL )
			return j;
		j = (j + 1) % divisor;
	}while(j != i);

	return j;
}

template<typename K,typename E>
hashTable<K,E>::hashTable(int initialCapacity)
{
	dSize = 0;
	divisor = initialCapacity;

	table = new pair<K,E>* [divisor];
	for( int i = 0; i != divisor; ++i )
		table[i] = NULL;
}

template<typename K,typename E>
pair<const K,E> *hashTable<K,E>::find(const K &the_key) const
{
	int i = search(the_key);
	
	if(table[i] == NULL || table[i]->first != the_key)
		return NULL;
	else
		return table[i];
}

template<typename K,typename E>
void hashTable<K,E>::insert(const pair<const K,E> &the_pair)
{
	int i = the_pair.first % divisor;
	if( table[i] == NULL ){
		table[i] = new pair<K,E>(the_pair);
		++dSize;
	}
	else if(table[i]->first == the_pair.first)
			table[i]->second = the_pair.second;
	else
		throw hashTableFull();
}
