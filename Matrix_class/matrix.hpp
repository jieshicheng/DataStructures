#ifndef MATRIX
#define MATRIX

#include<iostream>
#include<algorithm>

using namespace std;

template<typename T> class matrix{

	template<typename U> friend ostream &operator <<(ostream &,const matrix<U> &);

public:
	matrix(int theRows = 0,int theCols = 0);
	matrix(const matrix<T> &);
	~matrix()   { delete []element; }
	int rows() const { return theRows; }
	int cols() const { return theCols; }
	T &operator ()(int i,int j) const;
	matrix<T> &operator =(const matrix<T> &);
	matrix<T>  operator +(const matrix<T> &) const;
	matrix<T>  operator -(const matrix<T> &) const;
	matrix<T>  operator *(const matrix<T> &) const;
	matrix<T>  &operator +=(const T &);

private:
	int theRows;
	int theCols;
	T *element;
};

#endif

template<typename T>
matrix<T>::matrix(int theRows,int theCols)
{
	if( theRows < 0 || theCols < 0 )
		cout<<"error parameter value"<<endl;
	this->theRows = theRows;
	this->theCols = theCols;
	element = new T[theRows * theCols];	
}

template<typename T>
matrix<T>::matrix(const matrix<T> &rhs)
{
	theRows = rhs.theRows;
	theCols = rhs.theCols;
	element = new T[theRows * theCols];
	copy(rhs.element,rhs.element + theRows * theCols,element);
}

template<typename T>
T &matrix<T>::operator ()(int i,int j) const
{
	if( (i < 1 || i > theRows) || (j < 1 || j > theCols) )
		cout<<"error parameter value"<<endl;
	return element[(i - 1) * theCols + j - 1];
}

template<typename T>
matrix<T> &matrix<T>::operator =(const matrix<T> &rhs)
{
	if( this != &rhs ){
		delete element;
		theRows = rhs.theRows;
		theCols = rhs.theCols;
		element = new T[theRows * theCols];
		copy(rhs.element,rhs.element + theRows * theCols,element);
		return *this;
	}
}

template<typename T>
matrix<T> matrix<T>::operator +(const matrix<T> &rhs) const
{
	if( theRows != rhs.theRows || theCols != rhs.theCols ){
		cout<<"do not match"<<endl;
	}
	matrix<T> data(theRows,theCols);
	for( int i = 0; i != theRows * theCols; ++i ){
		data.element[i] = element[i] + rhs.element[i];
	}
	return data;
}

template<typename T>
matrix<T> matrix<T>::operator -(const matrix<T> &rhs) const
{
	
	if( theRows != rhs.theRows || theCols != rhs.theCols ){
		cout<<"do not match"<<endl;
	}
	matrix<T> data(theRows,theCols);
	for( int i = 0; i != theRows * theCols; ++i ){
		data[i] = element[i] - rhs.element[i];
	}
	return data;
}

template<typename T>
matrix<T> matrix<T>::operator *(const matrix<T> &rhs) const
{
	if( theCols != rhs.theRows )
		cout<<"do not match"<<endl;
	matrix<T> data(theRows,rhs.theCols);
	int ct = 0,cm = 0,cw = 0;

	for( int i = 0; i <= theRows; ++i ){
		for( int j = 1; j <= rhs.theCols; ++j ){
			T sum = element[ct] * rhs.element[cm];

			for( int k = 2; k <= theCols; ++k ){
				++ct;
				cm += rhs.theCols;
				sum += element[ct] * rhs.element[cm];
			}
			data.element[cw++] = sum;

			ct -= theCols - 1;
			cm = j;
		}
		ct += theCols;
		cm = 0;
	}
	return data;

}

template<typename T>
matrix<T> &matrix<T>::operator +=(const T &rhs)
{	
	for( int i = 0; i != theRows * theCols; ++i ){
		element[i] = element[i] + rhs;
	}
	return *this;
}

template<typename U>
ostream &operator <<(ostream &os,const matrix<U> &rhs)
{
	for( int i = 0; i != rhs.theRows * rhs.theCols; ++i ){
		os<<rhs.element[i];
	}
	return os;
}
