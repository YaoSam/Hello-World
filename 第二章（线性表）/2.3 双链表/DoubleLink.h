#include <iostream>
#ifndef re
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //循环n次
#endif // !Re(i,n)

template <class T>
struct dnode
{
	T data;
	dnode<T> *pre, *next;
	dnode(const T &one) :data(one),pre(NULL),next(NULL){}
	dnode<T>* Delete()
	{
		if(pre)		pre->next = next;
		if(next)		next->pre = pre;
		return this;
	}
}; 
template<class T>
 void link(dnode<T>* a, dnode<T>* b)
{
	if (a)
		a->next = b;
	if (b)
		b->pre = a;
}
template<class T>
void SwapNode(dnode<T> *a, dnode<T> *b)
{
	if (a == NULL || b == NULL)	return;
	if (a->next == b)
	{
		link(a->pre, b);
		link(a, b->next);
		link(b, a);
	}
	else if (a->pre == b)
	{
		link(b->pre, a);
		link(b, a->next);
		link(a, b);
	}
	else
	{
		dnode<T> *apre = a->pre, *anext = a->next;
		dnode<T> *bpre = b->pre, *bnext = b->next;
		link(apre, b); link(b, anext);
		link(bpre, a); link(a, bnext);
	}
}
template <class T>
dnode<T>* MoveNode(dnode<T> *p, unsigned int n)
	{
		re(i, n)
		{
			if (p)
				p = p->next;
			else
				throw "越界";
		}
		return p;
	}

bool isChar(char one)
{
	return ((one >= 'a'&&one <= 'z') || (one >= 'A'&&one <= 'Z'));
}

template <class T>
class doubleLink
{
	dnode<T> *head, *last;
public:
	doubleLink(T a[]=NULL, int length=0)
	{
		//建立空链表
		if (a == NULL || length == 0)
		{
			head = last = NULL;
			return;
		}
		//建立正常链表，当length为1时正常。
		head = new dnode < T >(a[0]) ;
		head->pre = NULL;
		dnode<T> *temp = head;
		Re(i, length-1)
		{
			link(temp, (new dnode<T>(a[i])));
			temp = temp->next;								//移动
		}
		last = temp;
		last->next = NULL;
	}
	doubleLink(const doubleLink<T> &other) :head(NULL), last(NULL)//复制构造函数
	{
		if (other.head==NULL)return;
		head = new dnode<T>(other.head->data);
		dnode<T>* p1 = other.head->next,*p2=head,*temp;
		while (p1 != NULL)
		{
			link(p2, new dnode<T>(p1->data));
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = NULL;
		last = p2;
	}
	doubleLink<T>& operator=(const doubleLink<T> &other)
	{
		last = NULL;
		dnode<T>* temp;
		while (head!=NULL)
		{
			temp = head->next;
			delete head->Delete();
			head = temp;
		}
		//此时head==NULL;
		if (other.head == NULL)return *this;
		head = new dnode<T>(other.head->data);
		dnode<T>* p1 = other.head, *p2 = head;
		while (p1 != NULL)
		{
			p1 = p1->next;
			link(p2, new dnode<T>(p1->data));
			p2 = p2->next;
		}
		p2->next = NULL;
		last = p2;
		return *this;

	}
	~doubleLink()
	{
		dnode<T>* temp;
		while (head)
		{
			temp = head->next;
			delete head->Delete();
			head = temp;
		}
	}
	int Lenght() const
	{
		int ans = 0;
		dnode<T> * temp = head;
		while (temp != NULL)
		{
			ans++;
			temp = temp->next;
		}
		return ans;
	}
	inline T Get(int i) const
	{
		return MoveNode(head, i)->data;
	}
	int find(T const &x) const
	{
		dnode<T>*temp = head;
		int ans = 0;
		while (temp)
		{
			if (temp->data == x)
				return ans;
			else
			{
				ans++;
				temp = temp->next;
			}
		}
		return -1;
	}
	doubleLink<T>& Insert(T const &x,int i=-1)	//默认从尾部插入
	{
		if (head == NULL)
		{
			head = new dnode<T>(x);
			last = head;
			return *this;
		}
		if (i == -1)
		{
			link(last, new dnode<T>(x));
			last = last->next;
			return *this;
		}
	
		if (i == 0)
		{	
			link(new dnode<T>(x), head);
			head = head->pre;
			return *this;
		}
		dnode<T> * temp = MoveNode(head, i);
		//dnode<T> *one = new dnode < T >(x) ;
		link(new dnode<T>(x), temp->next);
		link(temp, temp->next->pre);
		return *this;
	}
	T Delete(int i)
	{
		dnode<T> *temp = MoveNode(head, i);
		//对头尾节点的维护
		if (temp == head)	head = head->next;
		if (temp == last)	last = last->pre;
		//用来返回删除的值
		T ans = temp->data;
		delete temp->Delete();
		return ans;
	}
	void DeleteData(T const &one)
	{
		dnode<T> *temp = head, *temp2;
		while (temp)
		{
			if (temp->data == one)
			{
				//temp2用来继续扫描
				temp2 = temp->next;
				//对头尾节点的维护
				if (temp == head) head = temp2;
				if (temp == last)	last = last->pre;
				delete temp->Delete();
				temp = temp2;
			}
			else temp = temp->next;
		}
	}
	doubleLink<T>& Invert(dnode<T>* left, dnode<T>* right)
	{
		dnode<T> *p1, *p2;
		if (left == head)
			head = right;
		if (right == last)
			last = left;
		while (left->next != right&&left != right)
		{
			p1 = left->next, p2 = right->pre;
			SwapNode(left, right);
			left = p1, right = p2;
		}
		return *this;
	}
	doubleLink<T>& Invert()
	{
		dnode<T> *left = head, *right = last, *p1, *p2;
		head = right;
		last = left;
		while (left->next != right&&left != right)
		{
			//先储存好下一个交换的位置。否则会乱。
			p1 = left->next, p2 = right->pre;
			SwapNode(left, right);
			left = p1, right = p2;
		}
		return *this;
	}
	doubleLink<T>& Exchange(unsigned int a, unsigned int b)
	{
		SwapNode(MoveNode(head,a), MoveNode(head,b));
		while (head->pre)head = head->pre;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, doubleLink<T>const & other)
	{
		dnode<T>* temp = other.head;
		while (temp)
		{
			out << temp->data;
			temp = temp->next;
		}
		return out;
	}
	friend void invertWords(doubleLink<char> &one)
	{
		dnode<T>* p1, *p2, *right, *left, *temp1, *temp2;
		p1 = new dnode < T >(0) ;
		p1->next = one.head;
		p1->data = ' ';
		while (p1->next)
		{
				cout << one << endl;
			while (p1->next&&!isChar(p1->data)) //p1为单词。并且不为空。
				p1 = p1->next;
			right = left = p2 = p1;
			while (p2&&isChar(p2->data))
				p2 = p2->next;
			if (p2)right = p2->pre;
			one.Invert(left, right);
		}
		one.last = p1;
		while (p1->pre)p1 = p1->pre;
		one.head = p1;
	}
};