//LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
using namespace std;
template<class T>
class LinkedList {
	private:
		//数据成员 
		Node<T> *front, *rear;							 //表头和表尾指针 
		Node<T> *currPtr,*prevPtr;			  	   		 //记录表当前遍历位置的指针,由插入和删除操作更新 
		int size;										 //表中的元素个数 
		int position;								 	 //当前元素在表中的位置序号。由函数reset使用 
		
		
		//函数成员：
		//生成新结点,数据域为item,指针域为ptrNext
		Node<T>* newNode(const T &item,Node<T>* ptrNext=0);
		
		//释放结点
		void freeNode(Node<T>* p);
		
		//将链表L复制到当前表（假设当前表为空）
		//被复制构造函数和"operator="调用
		void copy(const LinkedList<T>& L);
		 
		
	public:
		LinkedList();									  //构造函数
		LinkedList(const LinkedList<T>& L);			   	  //复制构造函数
		~LinkedList();									  //析构函数
		LinkedList<T>& operator= (const LinkedList<T>& L); //重载赋值运算符 
		
		
		int getSize() const;							  //返回链表中元素个数 
		bool isEmpty() const;							  //链表是否为空 
		
		
		void reset(int pos=0);							  //初始化游标的位置 
		void next();									  //使游标移动到下一个结点 
		bool endOfList() const;							  //游标是否到了链表尾端
		int currentPosition(void) const;				  //返回游标当前位置
		
		 
		void insertFront(const T& item);				  //在表头插入结点
		void insertRear(const T& item);					  //在表尾添加结点
		void insertAt(const T& item);				 	  //在当前结点之前插入结点
		void insertAfter(const T& item);			 	  //在当前结点之后插入结点
		
		
		T deleteFront() ;								  //删除头结点
		void deleteCurrent();							  //删除当前结点
		
		
		T& data(); 										 //返回当前结点成员数据的引用
		const T& data() const;							 //返回当前结点成员数据的常引用
		
		
		Node<T>* getfront();							 //返回表头 
		
		//清空链表：释放所有结点的内存空间。被析构函数的"operator="调用
		void clear();
};

//类的实现部分

//私有成员函数实现：
//生成新结点，数据域为item，指针域为ptrNext
template<class T>
Node<T>* LinkedList<T>:: newNode(const T& item,Node<T>* ptrNext/*=NULL*/)
{
	ptrNext->data=item;
	return ptrNext;
}


//释放结点
template<class T>
void LinkedList<T>:: freeNode(Node<T>* p)
{
	delete p; 
} 


		
//将链表L复制到当前表（假设当前表为空）
//被复制构造函数和"operator="调用
template<class T>
void LinkedList<T>:: copy(const LinkedList<T>& L)
{
	Node<T> *now=L.getfront();
	front=now;
	currPtr=now;
	position=1;
	while(now->nextNode()!=0)
		{
			now=now->nextNode();
			currPtr->nextNode=now;
			position++;
			prevPtr=currPtr;
			currPtr=currPtr->nextNode();
		}
	size=L.getSize();
	rear=now;
	reset(0);
}


//公有成员函数实现： 
//构造函数
template<class T>
LinkedList<T>::LinkedList()
{
	front=rear=currPtr=prevPtr=0;
	size=0;
	position=0;
}


//复制构造函数
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L)
{
	copy(L);
} 


//析构函数
template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
	size=0;
	position=0;
} 


//重载赋值运算符
template<class T>
LinkedList<T>& LinkedList<T>:: operator=(const LinkedList<T>& L)
{
	clear();
	copy(L);
}


//返回链表中元素个数
template<class T>
int LinkedList<T>:: getSize() const
{
	return size;
}


//链表是否为空
template<class T> 
bool LinkedList<T>:: isEmpty() const
{
	return size;
}


//初始化游标的位置 
template<class T>
void LinkedList<T>:: reset(int pos/*=0*/)
{
	prevPtr=0;
	currPtr=front;
	position=0;
	while(position!=pos)
		{
			prevPtr=currPtr;
			currPtr=currPtr->nextNode();
			position++;
		}	 
}


//使游标移动到下一个结点
template<class T>
void LinkedList<T>:: next()
{
	if(!endOfList())
		{
			prevPtr=currPtr;
			currPtr=currPtr->nextNode();
			position++;
		}
	return ;
}


//游标是否到了链表尾端
template<class T>
bool LinkedList<T>:: endOfList()const
{
	if(currPtr==rear)	return true;
	else return false;
} 


//返回游标当前位置
template<class T>
int LinkedList<T>:: currentPosition(void)const
{
	return position;
} 


//在表头插入结点
template<class T>
void LinkedList<T>:: insertFront(const T& item)
{
	Node<T>* newp=new Node<T>(item,front);
	size++;
	if(currPtr!=0) position++;
	if(currPtr==0) currPtr=newp;
	else if(currPtr==front) prevPtr=newp; 
	if(rear==0) rear=newp;
	front=newp;
} 


//在表尾添加结点
template<class T>
void LinkedList<T>:: insertRear(const T& item) 
{
	Node<T>* newp=new Node<T>(item,0);
	size++;
	if(rear!=0)rear->insertAfter(newp);
	if(front==0) front=newp;
	if(currPtr==0) currPtr=front;
	rear=newp;
}


//在当前结点之前插入结点
template<class T>
void LinkedList<T>:: insertAt(const T& item)
{
	if(currPtr==front)
		{ 
			insertFront(item);
			prevPtr=front;
		}
	else
		{
			Node<T>* newp=new Node<T>(item,currPtr);
			size++;
			position++;
			prevPtr->insertAfter(newp);
			prevPtr=newp;
		}
}


//在当前结点之后插入结点
template<class T>
void LinkedList<T>:: insertAfter(const T& item)
{
	if(currPtr==rear) 
		{
			insertRear(item);
		}
	else
		{
			Node<T>* newp=new Node<T>(item,0);
			size++;
			currPtr->insertAfter(newp);
		}
}


//删除头结点
template<class T>
T LinkedList<T>:: deleteFront()
{
	if(front!=0)
		{
			Node<T>* nex=front->nextNode();
			delete front;
			front=nex;
			size--;
			position--;
		}
}


//删除当前结点
template<class T>
void LinkedList<T>:: deleteCurrent()
{
	if(currPtr!=0)
		{
			size--;
			prevPtr->insertAfter(currPtr->nextNode());
			delete currPtr;
			currPtr=prevPtr->nextNode();
		} 
}



//返回对当前结点成员数据的引用
template<class T>
T&  LinkedList<T>:: data()
{
	return currPtr->data;
}



//返回对当前结点成员数据的常引用
template<class T>
const T&  LinkedList<T>:: data() const
{
	return currPtr->data;
}


//返回表头 
template<class T>
Node<T>* LinkedList<T>:: getfront()
{
	return front;
}



//清空链表：释放所有结点的内存空间。被析构函数和"operator="调用
template<class T>
void LinkedList<T>::clear() 
{
	if(size==0) return ;
	currPtr=front;
	size=0; 
	position=0;
	while(currPtr!=rear)
		{
			//cout<<currPtr->data<<endl;
			Node<T>* nex=currPtr->nextNode();
			delete currPtr;
			currPtr=nex;
		}	 
	//cout<<currPtr->data<<endl;
	delete currPtr;
} 
#endif													 //LINKEDLIST_H 
