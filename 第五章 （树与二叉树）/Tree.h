#define TEMP template<class T>
#include <iostream>
using namespace std;
#ifndef re
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //循环n次
#endif // !Re(i,n)


TEMP 
class tree
{
	T data;
	tree<T> *right,*left;
public:
	tree<T>* le()const{ return left; }
	tree<T>* ri()const{ return right; }
	T DATA()const { return data; }
	tree<T>(T data=0,tree<T>* L=NULL,tree<T>* R=NULL):
		data(data), 
		left(L),
		right(R)
	{}
	tree<T>* create(T end)
	{
		T temp;
		if (cin >> temp &&temp != end)
		{
			left=create(end);
			right=create(end);
			return new tree<T>(temp);
		}
		else return NULL;
	}
	tree<T>(const tree<T> &other)
	{
		left = NULL;
		right = NULL;
		if (other.left)
			left = new tree<T>(*other.left);
		if (other.right)
			right = new tree<T>(*other.right);
		data = other.data;
	}
	tree<T>& operator=(const tree<T>& other)
	{
		if (this == &other)
			return *this;
		this->release();
		left = NULL;
		right = NULL;
		if (other.left)
			left = new tree<T>(*other.left);
		if (other.right)
			right = new tree<T>(*other.right);
		data = other.data;
		return *this;
	}
	~tree()
	{
		this->release();
	}
	void release()
	{
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
	friend ostream& operator<<(ostream& out, const tree<T>& one)
	{
		if (one.left)
			out << *one.left;
		if (one.right)
			out << *one.right;
		out << one.data << ' ';
		return out;
	}
	void pre()
	{
		cout << data << ' ';
		if (left)
			left->pre();
		if (right)
			right->pre();
	}
	void mid()
	{
		if (left)
			left->mid();
		cout << data << ' ';
		if (right)
			right->mid();
	}
	void back()
	{
		if (left)
			left->back();
		if (right)
			right->back();
		cout << data << ' ';
	}
	void back_1()
	{
		cout << data << " ";
		if (right)
			right->back_1();
		if (left)
			left->back_1();
	}
	void print()
	{
		tree<T> *quene[1000];
		unsigned int first = 0, rear = 0;
		quene[first++] = this;
		tree<T>* temp;
		int maxh = 0, maxnum = 1;
		while (rear < first)
		{
			//pop
			temp = quene[rear++];
			cout << temp->data << ' ';
			//push
			if (temp->left)
				quene[first++] = temp->left;
			if (temp->right)
				quene[first++] = temp->right;
		}
	}
	friend tree<int>* Create(int end);
	friend tree<char>* Create(char end);
	//前序遍历的非递归实现。。
	void aprint()
	{
		tree<T>* root;
		tree<T>* a[1000];
		unsigned int mark[1000] = { 0 };
		int top = 0;
		a[++top] =root= this;
		while (top != 0)
		{
			while(root!= NULL&&top!=-1)
			{
				cout << (root->data) << ' ';
				a[++top] = root;
				root = root->l();
			}
			if (top!=-1)
			{
				root = a[top--]->r();
			}
		}
	}
	//以下下为第五章题目
	//5.1
	unsigned int nodeNum()const
	{
		int ans=1;
		if (left)
		{
			ans += left->nodeNum();
		}
		if (right)
		{
			ans += right->nodeNum();
		}
		return ans;
	}
	//5.2
	unsigned int height()const
	{
		unsigned int a = 1, b = 1;
		if (left)
			a = left->height() + 1;
		if (right)
			b = right->height() + 1;
		return a > b ? a : b;
	}
	//5.3
	void printLeave()const
	{
		if (!left&&!right)
			cout << data << ' ';
		if (left)
			left->printLeave();
		if (right)
			right->printLeave();
	}
	//5.4 5.8 得手动释放内存。
	tree<T>* invertCopy()
	{
		tree<T>* to = new tree<T>(data);
		if (left)
			to->right = left->invertCopy();
		if (right)
			to->left = right->invertCopy();
		return to;
	}
	void InvertBackPrint()
	{
		//先倒转左右子树
		tree<T> *a = invertCopy();
		//前序输出
		a->pre();
		//释放内存。
		a->release();
		delete a;
	}
	//5.5
	tree<T> *findParents(T const X)
	{
		tree<T>* ans=NULL;
		if (!left&&!right)
			return NULL;
		if (left)
		{
			if (left->data == X)
				return this;
			else
				ans = left->findParents(X);
		}
		if (ans)
			return ans;
		if (right)
		{
			if (right->data == X)
				return this;
			else
				ans = right->findParents(X);
		}
		if (ans)
			return ans;
		else return NULL;
	}
	//5.6
	void Del(T const X)
	{
		if (data == X)
			this->release();
		if (left)
		{
			if (left->data == X)
			{
				left->release();
				delete left;
				left = NULL;
			}
			else left->Del(X);
		}
		if (right)
		{
			if (right->data == X)
			{
				right->release();
				delete right;
				right = NULL;
			}
			else right->Del(X);
		}
	}
	
};

tree<int>* Create(int end = 0)
{
	int data;
	if (cin >> data&&data != 0)
	{
		tree<int>* p = new tree<int>(data);
		p->left = Create(end);
		p->right = Create(end);
		return p;
	}
	else
		return NULL;
}
tree<char>* Create(char end = '#')
{
	char data;
	if (cin >> data&&data != end)
	{
		tree<char>* p = new tree<char>(data);
		p->left = Create(end);
		p->right = Create(end);
		return p;
	}
	else
		return NULL;
}


//5.7
TEMP
class quenetree
{
	T data[1000];
	T end;
	int num;
public:
	quenetree(T END) :end(END)
	{
		re(i, 100)
			data[i] = end;
		num = 0;
		T temp;
		if (cin >> temp)
			intial(temp, 1, 0);
	}
	//还是用递归来实现比较自然……
	void intial(T const X, unsigned int rank, unsigned int n)
	{
		data[rank + n] = X;
		if (X == end)
			return;
		num++;
		T a;
		if (cin >> a)
			intial(a, rank << 1, 2 * n);
		if (cin >> a)
			intial(a, rank << 1, 2 * n + 1);
		return;
	}
	void pre(unsigned int rank=1,unsigned int n=0)
	{
		if (data[rank + n] != end)
			cout << data[rank + n] << ' ';
		else return;
		pre(rank << 1, 2 * n);
		pre(rank << 1, 2 * n + 1);
	}


};