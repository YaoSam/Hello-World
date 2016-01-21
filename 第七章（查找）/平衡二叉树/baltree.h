#include <iostream>
#include <string>
#include <math.h>
#define TEMP template<class T>

#define re(i,n) for(unsigned int i=0;i<n;i++)
#define MAX 1000

TEMP class SeqTree;
TEMP class tree
{
	T data;
	tree<T>* left, *right;
	friend class SeqTree < T > ;
	tree<T>* findParent(T const & X)
	{
		if (this == NULL)
			return NULL;
		if ((left&&left->data == X) || (right&&right->data == X))
			return this;
		tree<T>* temp = NULL;
		if (X < data&&left)
			temp = left->findParent(X);
		else if (right)
			temp = right->findParent(X);
		return temp;
	}
	void intsert(T const & X)
	{
		if (this == NULL)
			return;
		if (data > X)
		{
			if (left == NULL)
				left = new tree<T>(X);
			else
				left->intsert(X);
		}
		else
		{
			if (right == NULL)
				right = new tree<T>(X);
			else
				right->intsert(X);
		}
	}
public:
	T &Data(){ return data; }
	T Data()const { return data; }
	tree<T>(T const &data, tree<T>* l = NULL, tree<T>* r = NULL) :
		data(data),
		left(l),
		right(r)
	{}
	tree<T>(tree<T> const &other)
	{
		data = other.data;
		left = (other.left) ? new tree<T>(*other.left) : NULL;
		right = (other.right) ? new tree<T>(*other.right) : NULL;
	}
	tree<T>bInsert(T const &X)
	{
		insert(X);
		int lHeight = left->height(), rHeight = right->height();
		if (lHeight-rHeight>1)
		{
			
		}
		else if (rHeight - lHeight > 1)
		{

		}
	}
	tree<T>& operator=(tree<T> const &other)
	{
		if (this != &other)
		{
			release();
			data = other.data;
			left = (other.left) ? new tree<T>(*other.left) : NULL;
			right = (other.right) ? new tree<T>(*other.right) : NULL;
		}
		return *this;
	}
	void pre()const
	{
		if (this == NULL)return;
		cout << data << ' ';
		left->pre();
		right->pre();
	}
	void mid()const
	{
		if (this == NULL)return;
		left->mid();
		cout << data << ' ';
		right->mid();
	}
	void back()const
	{
		if (this == NULL)return;
		left->back();
		right->back();
		cout << data << ' ';
	}
	tree<T>* find(T const & X)
	{
		if (this == NULL || data == X)
			return this;
		tree<T> *ans = NULL;
		ans = left->find(X);
		if (ans)
			return ans;
		return right->find(X);
	}
	void release()
	{
		if (this == NULL)
			return;
		if (left)
		{
			left->release();
			delete left;
			left = NULL;
		}
		if (right)
		{
			right->release();
			delete right;
			right = NULL;
		}
	}
	unsigned int height()const
	{
		if (this == NULL) return 0;
		unsigned int l = left->height(), r = right->height();
		return (l > r ? l : r) + 1;
	}
	unsigned int nodeNum()
	{
		return (this == NULL) ? 0 : (1 + left->nodeNum() + right->nodeNum());
	}
	tree<T>* findMAX(tree<T>* root, T const &key)
	{
		if (root == NULL)
			return NULL;
		tree<T>* ans = NULL;
		if (key < root->data)
		{
			return (ans = findMAX(root->left, key)) == NULL ? root : ans;
		}
		else
			return findMAX(root->right, key);
	}
};


#undef re(i,n) 
#undef  MAX
