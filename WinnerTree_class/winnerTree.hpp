#ifndef _WINNERTREE_
#define _WINNERTREE_

#include"myException.hpp"

#include<iostream>
#include<algorithm>

using namespace std;

template<typename T> class winnerTree{

   public:
	winnerTree() : lowExt(0),offset(0),tree(nullptr),player(nullptr),playerSize(0) { }
	virtual ~winnerTree() { delete tree,player; }
	virtual void initialize(T *play,int theSize);
	virtual int winner() const { return tree[1]; }
	virtual int winner(int i) const { return (i < playerSize) ? tree[i] : 0; }
	virtual void rePlay(int thePlay);
	virtual void output() const;
   private:
	void play(int,int,int);

	int lowExt;
	int offset;
	int *tree;
	T *player;
	int playerSize;

};

template<typename T>
void winnerTree<T>::play(int p,int leftChild,int rightChild)
{
	if(p <= 0 || leftChild <= 0 || rightChild <= 0)
		throw illegaParameterValue("root or leftChild or rightChild must have at least 1");

	tree[p] = (player[leftChild] <= player[rightChild]) ? leftChild : rightChild;

	while(p % 2 == 1 && p > 1){
		tree[p / 2] = (player[tree[p - 1]] <= player[tree[p]]) ? tree[p - 1] : tree[p];
		p /= 2;
	}
}


template<typename T>
void winnerTree<T>::initialize(T *playArray,int theSize)
{
	if(theSize < 2)
		throw illegaParameterValue("player must have at least 2 players");
	
	int n = theSize;
	playerSize = theSize;
	tree = new int[playerSize];
	player = new T[playerSize + 1];
	copy(playArray,playArray + theSize,player + 1);
	int i,s;

	for(s = 1; 2 * s <= n - 1; s += s);
	offset = 2 * s - 1;
	lowExt = 2 * (n - s);

	for(i = 2; i <= lowExt; i += 2)	
		play((offset + i)/2,i - 1,i);
	if(n % 2 == 1){
		play(n/2,tree[n - 1],lowExt + 1);
		i = lowExt + 3;
	}
	else
		i = lowExt + 2;
	for(; i <= n; i += 2)
		play((i - lowExt + n - 1)/2,i - 1,i);
	
}

template<typename T>
void winnerTree<T>::rePlay(int thePlay)
{
	if(thePlay <= 0 || thePlay > playerSize)
		throw illegaParameterValue("player index is illega");

	int n = playerSize;
	int matchNode;
	int leftChild;
	int rightChild;

	if(thePlay <= lowExt){
		matchNode = (offset + thePlay) / 2;
		leftChild = tree[2 * matchNode];
		rightChild = leftChild + 1;
	}
	else{
		matchNode = (thePlay - lowExt + n - 1) / 2;
		if(2 * matchNode == n - 1){
			leftChild = tree[2 * matchNode];
			rightChild = thePlay;
		}
		else{
			leftChild = 2 * matchNode - n + 1 + lowExt;
			rightChild = leftChild + 1;
		}
	}
	
	tree[matchNode] = (player[leftChild] <= player[rightChild]) ? leftChild : rightChild;
	
	if(matchNode == n - 1 && n % 2 == 1){
		matchNode /= 2;
		tree[matchNode] = (player[tree[n - 1]] <= player[tree[lowExt + 1]]) ? tree[n - 1] : lowExt + 1;
	}

	matchNode /= 2;
	for(; matchNode >= 1; matchNode /=2)
		tree[matchNode] = (player[tree[2 * matchNode]] <= player[tree[2 * matchNode + 1]]) ? 
									tree[2 * matchNode] : tree[2 * matchNode + 1];
}

template<typename T>
void winnerTree<T>::output() const
{
	cout<<"number of players = "<<playerSize
		<<" lowExt = "<<lowExt
		<<" offset = "<<offset<<endl;
	cout<<"complete winner tree pointers are "<<endl;
	for(int i = 1; i < playerSize; ++i){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
}

#endif
