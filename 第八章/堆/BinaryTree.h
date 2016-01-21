#pragma once
template <class T>
struct btree
{
	T data;
	btree<T>* father, *left, *right;
	btree(T const & D = T(), btree<T>* F = NULL, btree<T>* L = NULL, btree<T>* R = NULL) :
		data(D), father(F), left(L), right(R){}
	btree(btree<T> const &other);
	btree<T>& operator=(btree<T> const &other);
	void del();
	~btree();
};