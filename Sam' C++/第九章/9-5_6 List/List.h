/*
*
*������	 ��������������           ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������  �� ++ + + +
*����  ����		  ��  ��������������  ��+
*����  ������������������������ �� +
*����  ����������������   �ߡ���  ��
*����  �������������������������� + +
*����  ���������������������� ������
*��������������������������������������������������
*���������������������������� + + + +
*������������������������������������Code is far away from bug with the animal protecting��������������
*���������������������������� + �����������ޱ���,������bug����
*����������������������������
*��������������������������������+������������������
*���������������������� �������������� + +
*�������������������� ���������������ǩ�
*�������������������� ������������������
*�����������������������������ש����� + + + +
*�����������������������ϩϡ����ϩ�
*�����������������������ߩ������ߩ�+ + + +
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
	void insert(node &other)										{ other.next = next; next = &other; }	//����һ���ڵ�,ע��˳��
	void NewInsert(const T &item)/*newһ���ڵ�*/		{	insert(*new node<T>(item));	} 
	node<T> * DelAfter();			//�޳�һ���ڵ㡣�����ظýڵ�ĵ�ַ�������ͷţ���ͦ���õġ�
	node<T> * getnext()											{ return next; } //���غ����ڵ��ָ��
	const node<T>*   getnext()const						{ return next; }
};

template <class T>	node<T> *node<T>::DelAfter()
{
	node<T> *temp = next;	//��������ֵ��
	if (next == 0)return 0;		//�Ѿ������һ���ڵ㡣
	next = temp->next;			//Ų����һ���㡣
	return temp;						//�������ͷš�
}

/************************************************************************/
/*					�����ķָ���	                                                               */
/************************************************************************/

template <class T>	class list	//����ģ��
{
	node<T>  *front, *rear;																	//ͷָ�룬βָ��
	node<T> *Pre, *Current;																//�α��ǰһ��ָ�룬�α�
	int length;																						//������
	int position;																					//�α��������е�˳��
	void Move(node<T>* &pointer){ pointer = pointer->getnext(); }		//ָ��������
	void clean()/*��ʼ��������û���ͷ��ڴ档*/{ front = rear = Pre = Current = NULL; length = position = 0; }
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
	list<T> &operator+=(list<T> const &other); //��ʵ=Ҳ����������Ĵ��롣����Ҫ��insertRear�����޸ķ�ֹ���ݹ顣

	int GetLength()				const	{ return length; }
	bool isEmpty()				const	{ return length== 0; }
	bool endOfList()				const	{ return position == length; }		//�ж��Ƿ��Ѿ�������β
	
	int currentPosition(void)	const	{ return position; }						//�����α�λ��
	T &data()									{ return Current->data; }			//��ǰλ�õ����ݡ�
	const T &data()const					{ return Current->data; }

	void reset(int pos = 1);																//��ʼ���α��λ�á�
	void next();																				//�α��ƶ�����һ���ڵ㡣

	void insertFront(const T &item);													//�ڱ�ͷ����ڵ㡣
	void insertRear(const T &item);													//�ٱ�β��ӽڵ㡣
	void insertAt(const T &item);														//�ڵ�ǰ�ڵ�ǰ���롣
	void insertAfter(const T &item);													//�ڵ�ǰ�ڵ�֮����롣

	void DelFront();																				//ɾ��ͷ�ڵ㡣
	void DelCur();																				//ɾ����ǰ�ڵ�
	void	clear();		//�ͷ�����
	~list()	{ Re(i, length)	delete front->DelAfter(); }							//ֱ����clearҲ�ǿ��Եġ����Ƕ���һ��Clean��

	friend ostream &operator<<(ostream& out, list<T>const &other)			//ò��ֻ��д������... ...�r(�s-�t)�q
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
template <class T>	list<T>::list(const list<T> &other)		//ֻ��=����һ��clear()������return
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
	clear();									//�ͷ���
	node<T>* tempother = other.front;
	front = Current = new node<T>((other.front)->data); //����ͷ
	length = other.GetLength();
	Re(i, length-1)										//��㸴�ƣ���һ���Ѿ����ƺ�
	{
		Move(tempother);						//������˳���Ǻ���Ҫ��
		Current->NewInsert(tempother->data);
		Move(Current);
	}
	rear = Current;							//ά��rear
	reset(other.currentPosition());		//ά��Current��Pre
	return *this;
}
template <class T>	void list<T>::next()
{
	if (isEmpty())			debug("����Ϊ�� next()�޷����ơ�");//�����쳣��������debug
	if (endOfList())		debug("���˶�β next()�޷����ơ�");
	Pre = Current;			//��ʵ����Pre=Pre->getnext() ,ֻ�ǱȽ��ʺ�pos==1�����
	Move(Current);
	position++;
}
template <class T>	void list<T>::reset(int pos = 1)
{
	Pre=Current = front;
	position = 1;
	if (pos > length)		debug("��Խ���� in reset()");
	Re(i, pos-1)	next();	//ǰ��n-1��
}

template <class T>	list<T> &list<T>::operator+=(list<T> const &other)
{
	node<T>* temp=other.front;
	int tempLen = other.length;		//��Ϊother�п��ܾ����Լ�������other.length�ᱻ�ı䡣�������ѭ����
	Re(i, tempLen)							//����length�����ݡ���ȻЧ�ʻ��Ǻܵ͡��������۵�����
	{
		insertRear(temp->data);		//�Զ�ά��Rear��length... ...
		Move(temp);
	}
	return *this;
}

template <class T >	void list<T>::insertFront(const T &item)
{
	if (isEmpty())*this = list(item);							//Ч��ʲô��ȥ���ġ�
	else
	{
		node<T>* temp = new node<T>(item,front); //����ָ��front�Ľڵ㡣
		front = temp;													//����front
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
		Move(Pre);					//����Pre��currǰ
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
		Current->NewInsert(item);		//�Թ���Current��ӽڵ����������... ...
		length++;
	}
}

template <class T>	void list<T>::DelFront()
{
	if (isEmpty())return; //length==0
	if (length>1)	
	{	
		if (position == 2)		Move(Pre);					//ת��Pre
		if (position == 1)		next(),Move(Pre);			//ת��Pre��current
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
		delete Pre->DelAfter();					//���ص���Curr�ĵ�ַ��
		length--;
		if (position!=length+1)
			Current = Pre->getnext();
		else
			reset(length);									//�ڶ�β��Pre�����Ѿ�û�ж����ˡ�ֻ�ܴ�ͷ������β��
	}
}

template <class T>	void list<T>::clear()						//�����ֱ��deleteFrontʡ��һЩ����... ...����Ч����Debug��ʱ���Ǻܵ͡�
{
	if (isEmpty())	return;
	Re(i, length)	
	{
		cout << i << ' ';
		delete front->DelAfter();	//�Զ�Ų����һ����
	}
	clean();
}

/************************************************************************/
/* �����ķָ���                                                                     */
/************************************************************************/

template <class T>	class OrderList
{
	list<T> mylist;
public:
	OrderList<T>() : mylist(){}
	void insert(T const &item) //Ψһ�Ľӿ�... ...
	{
		if (mylist.isEmpty())	mylist = list<T>(item); //��ʼ����
		else
		{
			int tempPosition = mylist.currentPosition();
			mylist.reset();							//�α����
			while (1)
			{
				if (mylist.data() > item) //��ÿ���ڵ�Ƚ�
				{
					mylist.insertAt(item);
					break;
				}
				if (mylist.endOfList())	//���˶�β��ÿ���㶼������
				{
					mylist.insertRear(item);
					break;
				}
				 mylist.next(); //��ʵnext�͸��껹ԭ��ͦ�ķ���Դ�ġ��r(�s-�t)�q�����������ⲿָ����~
			}
			mylist.reset(tempPosition);			//�α껹ԭ��
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