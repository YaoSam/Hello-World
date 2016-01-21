#include <iostream>
#include <string>
#define TEMP template<class T>

#define re(i,n) for(unsigned int i=0;i<n;i++)
#define MAX 1000

TEMP class SeqTree;
TEMP class tree
{
	T data;
	tree<T>* left, *right;
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
	friend class SeqTree<T>;
	tree<T>* findParent(T const & X)
	{
		if (this == NULL)
			return NULL;
		if ((left&&left->data == X) || (right&&right->data == X))
			return this;
		tree<T>* temp = NULL;
		if (X<data&&left)
			temp=left->findParent(X);
		else if (right)
			temp=right->findParent(X);
		return temp;
	}
	tree<T>* find(T const & X)
	{
		if (this == NULL||data==X)
			return this;
		tree<T> *ans=NULL;
		ans = left->find(X);
		if (ans)
			return ans;
		return right->find(X);
	}
public:
	T &Data(){ return data; }
	T Data()const { return data; }
	tree<T>(T const &data, tree<T>* l = NULL, tree<T>* r = NULL):
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
	tree<T>& operator=(tree<T> const &other)
	{
		if (this!=&other)
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
		unsigned int l=left->height(), r=right->height();
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
		tree<T>* ans=NULL;
		if (key < root->data)
		{
			return (ans=findMAX(root->left,key)) == NULL ? root : ans;
		}
		else
			return findMAX(root->right, key);
	}
};
TEMP
class SeqTree
{
	tree<T>* root;
	tree<T>* findParent(T const & X)
	{
		return root->findParent(X);
	}
public:
	SeqTree<T>() : root(NULL){}
	SeqTree<T>(T const &data) :root(new tree<T>(data)){}
	SeqTree<T>(T data[], unsigned int n)
	{
		root = new tree<T>(data[0]);
		re(i, n-1)
			root->intsert(data[i+1]);
	}
	SeqTree<T>( SeqTree<T> const & other)
	{
		root = new tree<T>(*other.root);
	}
	SeqTree<T>& operator=(SeqTree<T> const &other)
	{
		if (this == &other)
			return *this;
		else
		{
			if (root)
			{
				root->release();
				delete root;
			}
			root = new tree<T>(*other.root);
		}
		return *this;
	}
	~SeqTree()
	{
		if (root)
		{
			root->release();
			delete root;
		}
		return;
	}
	unsigned int height()const{ return root->height(); }
	unsigned int nodeNum()const{ return root->nodeNum(); }
	void insert(T const &X)
	{
		if (root == NULL)
			root = new tree<T>(X);
		else 
			root->intsert(X);
	}
	tree<T>* find(T const &X){	return root->find(X);	}
	void Del(T const & X)
	{
		tree<T>* temp = findParent(X),*fa=NULL,*a=NULL;
		if (root == NULL)return;
		if (temp == NULL)return;
		tree<T>* templ = temp->left, *tempr = temp->right;
		if (templ&&templ->data == X)
		{
			if (templ->left == NULL&&temp->right == NULL)
			{
				temp->left = NULL;
				delete templ;
			}
			else if (templ->left == NULL)
			{
				temp->left = templ->right;
				delete templ;
			}
			else if (templ->right == NULL)
			{
				temp->left = templ->left;
				delete templ;
			}
			else
			{
				fa = templ, a = fa->right;
				while (a->left != NULL)
				{
					fa = a;
					a = a->left; //找到最接近templ的节点
				}
				templ->data = a->data;//替换
				if (fa == templ) fa->right = a->right;//如果并没有变，则a就是所求的点。
				else fa->left = a->right;
				delete a;
			}
		}
		else if (tempr&&tempr->data==X)
		{
			if (tempr->left == NULL&&tempr->right == NULL)
			{
				temp->right = NULL;
				delete tempr;
			}
			else if (tempr->left==NULL)
			{
				temp->right = tempr->right;
				delete tempr;
			}
			else if (tempr->right==NULL)
			{
				temp->right = tempr->left;
				delete tempr;
			}
			else
			{
				fa = tempr, a = tempr->left;
				while (a->right != NULL)
				{
					fa = a;
					a = a->right;
				}
				tempr->data = a->data;
				if (fa == tempr)
					fa->left = a->left;
				else fa->right = a->left;//包括了NULL的情况
				delete a;
			}
		}
	}
	//中序遍历
	void mid(){root->mid();}
	//层序遍历
	void print()
	{
		if (!root)		return;
		unsigned int front = 0, rear = 0;
		tree<T> *quene[MAX],*temp;
		quene[front++] = root;
		while (rear < front)
		{
			//pop
			temp = quene[rear++];
			cout << (temp->data) << ' ';
			//push
			if (temp->left)
				quene[front++] = temp->left;
			if (temp->right)
				quene[front++] = temp->right;
		}
		return;
	}
	T findMAX(T const &key)
	{
		return root->findMAX(root,key)->data;
	}


};

#undef re(i,n) 
#undef  MAX
