/*
*
*　　　	 　　　　┏┓　           ┏┓+ +
*　　  　　　　　┏┛┻━━━━━━┛┻┓ + +
*　　  　　　　　┃　　　　       ┃ 　
*　　  　　　　　┃　　　━　　  ┃ ++ + + +
*　　  　　		  ┃  ███━███  ┃+
*　　  　　　　　┃　　　　　　 ┃ +
*　　  　　　　　┃　　   ┻　　  ┃
*　　  　　　　　┃　　　　　　┃ + +
*　　  　　　　　┗━┓　　　 ┏━┛
*　　　　　　　　　┃　　　┃　　　　　　　　　　　
*　　　　　　　　　┃　　　┃ + + + +
*　　　　　　　　　┃　　　┃　　　　Code is far away from bug with the animal protecting　　　　　　　
*　　　　　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug　　
*　　　　　　　　　┃　　　┃
*　　　　　　　　　┃　　　┃　　+　　　　　　　　　
*　　　　　　　　　┃　 　　┗━━━┓ + +
*　　　　　　　　　┃ 　　　　　　　┣┓
*　　　　　　　　　┃ 　　　　　　　┏┛
*　　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
*　　　　　　　　　　┃┫┫　┃┫┫
*　　　　　　　　　　┗┻┛　┗┻┛+ + + +
*/
#pragma once
#include<iostream>
#include <string>
#define Re(i,n) for(int i=1;i<=n;i++)
using namespace std;

void debug(string warring)
{
	cout << warring << endl;
	system("pause");
	exit(1);
}
template <class T>	class node
{
	node<T> *next;
public:
	T data;
	node(T const &data = 0, node<T>* next = 0) :	data(data), next(next)		{}
	void insert(node &other)										{ other.next = next; next = &other; }	//插入一个节点,注意顺序。
	void NewInsert(const T &item)/*new一个节点*/		{	insert(*new node<T>(item));	} 
	node<T> * DelAfter();			//剔除一个节点。并返回该节点的地址（用于释放）还挺好用的。
	node<T> * getnext()											{ return next; } //返回后续节点的指针
	const node<T>*   getnext()const						{ return next; }
};

template <class T>	node<T> *node<T>::DelAfter()
{
	node<T> *temp = next;	//用来返回值。
	if (next == 0)return 0;		//已经是最后一个节点。
	next = temp->next;			//挪到下一个点。
	return temp;						//用来被释放。
}

/************************************************************************/
/*					华丽的分割线	                                                               */
/************************************************************************/

template <class T>	class list	//链表模板
{
	node<T>  *front, *rear;																	//头指针，尾指针
	node<T> *Pre, *Current;																//游标的前一个指针，游标
	int length;																						//链表长度
	int position;																					//游标在链表中的顺序。
	void Move(node<T>* &pointer){ pointer = pointer->getnext(); }		//指针往后移
	void clean()/*初始化，但是没有释放内存。*/{ front = rear = Pre = Current = NULL; length = position = 0; }
public:
	list() { clean(); }
	list(const node<T> &item) :
		length(1), 
		position(1), 
		front(new node<T>(item)), 
		rear(front), 
		Pre(front), 
		Current(front)
	{}
	list(const list<T> &L);
	list<T> & operator=(const list<T> & other);
	list<T> &operator+=(list<T> const &other); //其实=也可以用这里的代码。但是要对insertRear进行修改防止死递归。

	int GetLength()				const	{ return length; }
	bool isEmpty()				const	{ return length== 0; }
	bool endOfList()				const	{ return position == length; }		//判断是否已经到了链尾
	
	int currentPosition(void)	const	{ return position; }						//返回游标位置
	T &data()									{ return Current->data; }			//当前位置的数据。
	const T &data()const					{ return Current->data; }

	void reset(int pos = 1);																//初始化游标的位置。
	void next();																				//游标移动到下一个节点。

	void insertFront(const T &item);													//在表头插入节点。
	void insertRear(const T &item);													//再表尾添加节点。
	void insertAt(const T &item);														//在当前节点前插入。
	void insertAfter(const T &item);													//在当前节点之后插入。

	void DelFront();																				//删除头节点。
	void DelCur();																				//删除当前节点
	void	clear();		//释放链表
	~list()	{ Re(i, length)	delete front->DelAfter(); }							//直接用clear也是可以的。但是多了一句Clean。

	friend ostream &operator<<(ostream& out, list<T>const &other)			//貌似只能写在这里... ...╮(╯-╰)╭
	{
		node<T> *one = other.front;
		Re(i, other.GetLength())
		{
			out << one->data << "->";
			other.Move(one); 
		}
		out << "END";
		return out;
	}
};
template <class T>	list<T>::list(const list<T> &other)		//只比=少了一个clear()，还有return
{
	node<T>* tempother = other.front;
	front = Current = new node<T>((other.front)->data); 
	length = other.GetLength();
	Re(i, length - 1)						
	{
		Move(tempother);
		Current->NewInsert(tempother->data);
		Move(Current);
	}
	rear = Current;						
	reset(other.currentPosition());
}
template <class T>	list<T> & list<T>::operator=(const list<T> & other)
{
	if (this == &other)return *this;			
	clear();									//释放先
	node<T>* tempother = other.front;
	front = Current = new node<T>((other.front)->data); //复制头
	length = other.GetLength();
	Re(i, length-1)										//逐点复制，第一点已经复制好
	{
		Move(tempother);						//操作的顺序还是很重要。
		Current->NewInsert(tempother->data);
		Move(Current);
	}
	rear = Current;							//维护rear
	reset(other.currentPosition());		//维护Current，Pre
	return *this;
}
template <class T>	void list<T>::next()
{
	if (isEmpty())			debug("队列为空 next()无法后移。");//两个异常处理。用来debug
	if (endOfList())		debug("到了队尾 next()无法后移。");
	Pre = Current;			//其实就是Pre=Pre->getnext() ,只是比较适合pos==1的情况
	Move(Current);
	position++;
}
template <class T>	void list<T>::reset(int pos = 1)
{
	Pre=Current = front;
	position = 1;
	if (pos > length)		debug("你越界了 in reset()");
	Re(i, pos-1)	next();	//前进n-1步
}

template <class T>	list<T> &list<T>::operator+=(list<T> const &other)
{
	node<T>* temp=other.front;
	int tempLen = other.length;		//因为other有可能就是自己。所以other.length会被改变。会出现死循环。
	Re(i, tempLen)							//复制length个数据。虽然效率还是很低。。。蛋疼的链表。
	{
		insertRear(temp->data);		//自动维护Rear，length... ...
		Move(temp);
	}
	return *this;
}

template <class T >	void list<T>::insertFront(const T &item)
{
	if (isEmpty())*this = list(item);							//效率什么的去他的。
	else
	{
		node<T>* temp = new node<T>(item,front); //生成指向front的节点。
		front = temp;													//更新front
		if (position == 1)	Pre = front;						
		length++;
		position++;
	}
}
template <class T>	void list<T>::insertRear(const T &item)
{
	if (isEmpty())*this = list(item);
	else		
	{
		rear->NewInsert(item);	
		Move(rear);
		length++;
	}
}
template <class T>	void list<T>::insertAt(const T &item)
{
	if (isEmpty())	*this = list(item);
	else if (position == 1) insertFront(item);
	else 
	{
		Pre->NewInsert(item);
		Move(Pre);					//保持Pre在curr前
		position++;
		length++;
	}
}
template <class T>	void list<T>::insertAfter(const T &item)
{
	if (isEmpty())*this = list(item);
	else 	if (endOfList()) insertRear(item);
	else 		
	{
		Current->NewInsert(item);		//乖乖在Current后加节点世界多美好... ...
		length++;
	}
}

template <class T>	void list<T>::DelFront()
{
	if (isEmpty())return; //length==0
	if (length>1)	
	{	
		if (position == 2)		Move(Pre);					//转移Pre
		if (position == 1)		next(),Move(Pre);			//转移Pre和current
		delete front->DelAfter();
		length--;
		position--;
	}
	else clear();			//length==1
}
template <class T>	void list<T>::DelCur()
{
	if (isEmpty())	return;
	if (position == 1)DelFront();
	else 
	{
		delete Pre->DelAfter();					//返回的是Curr的地址。
		length--;
		if (position!=length+1)
			Current = Pre->getnext();
		else
			reset(length);									//在队尾。Pre后面已经没有东西了。只能从头来到队尾。
	}
}

template <class T>	void list<T>::clear()						//相对于直接deleteFront省了一些步骤... ...但是效率在Debug的时候还是很低。
{
	if (isEmpty())	return;
	Re(i, length)	
	{
		cout << i << ' ';
		delete front->DelAfter();	//自动挪到下一个点
	}
	clean();
}

/************************************************************************/
/* 华丽的分割线                                                                     */
/************************************************************************/

template <class T>	class OrderList
{
	list<T> mylist;
public:
	OrderList<T>() : mylist(){}
	void insert(T const &item) //唯一的接口... ...
	{
		if (mylist.isEmpty())	mylist = list<T>(item); //初始化。
		else
		{
			int tempPosition = mylist.currentPosition();
			mylist.reset();							//游标归零
			while (1)
			{
				if (mylist.data() > item) //跟每个节点比较
				{
					mylist.insertAt(item);
					break;
				}
				if (mylist.endOfList())	//到了队尾，每个点都比他大。
				{
					mylist.insertRear(item);
					break;
				}
				 mylist.next(); //其实next和浮标还原还挺耗费资源的。╮(╯-╰)╭。懒得生成外部指针了~
			}
			mylist.reset(tempPosition);			//游标还原。
		}
	}
	friend ostream &operator<<(ostream &out, OrderList<T>  &other){		return out <<"OrderList: "<<other.mylist;	}
};	
	/*Testing*/
	//Re(i, 10)
	//	a.insertRear(i);
	//cout << a << endl;
	//Re(i, 10)
	//	a.insertAt(i*10);
	//cout << a << endl;
	//Re(i, 10)
	//	a.insertAfter(i*100);
	//cout << a << endl;
	//Re(i, 10)
	//	a.insertFront(i*1000);
	//cout << a << endl;
	//Re(i, 50)
	//{
	//	a.deleteFront();
	//	cout << a << endl;
	//}