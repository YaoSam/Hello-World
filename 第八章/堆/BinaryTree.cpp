#pragma once
#include "BinaryTree.h"
#undef  TEMP
#define TEMP template <class T>
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)

TEMP btree<T>::btree(btree<T> const & other) :left(NULL), right(NULL)
{
	if (other.left)		left = new btree<T>(*other.left);
	if (other.right)	right = new btree<T>(*other.right);
}

TEMP btree<T>& btree<T>::operator=(btree<T> const &other)
{
	if (this == &other)return *this;
	this->del();
	data = other.data;
	if(other.left)		left = new btree<T>(*other.left);
	if (other.right)	right = new btree<T>(*other.right);
	return *this;
}
TEMP void btree<T>::del()
{
	if (left)
	{
		left->del();
		delete left;
		left = NULL;
	}
	if (right)
	{
		right->del();
		delete right;
		right = NULL;
	}
}

TEMP btree<T>::~btree(){ this->del(); }