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
		//���ݳ�Ա 
		Node<T> *front, *rear;							 //��ͷ�ͱ�βָ�� 
		Node<T> *currPtr,*prevPtr;			  	   		 //��¼��ǰ����λ�õ�ָ��,�ɲ����ɾ���������� 
		int size;										 //���е�Ԫ�ظ��� 
		int position;								 	 //��ǰԪ���ڱ��е�λ����š��ɺ���resetʹ�� 
		
		
		//������Ա��
		//�����½��,������Ϊitem,ָ����ΪptrNext
		Node<T>* newNode(const T &item,Node<T>* ptrNext=0);
		
		//�ͷŽ��
		void freeNode(Node<T>* p);
		
		//������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ�
		//�����ƹ��캯����"operator="����
		void copy(const LinkedList<T>& L);
		 
		
	public:
		LinkedList();									  //���캯��
		LinkedList(const LinkedList<T>& L);			   	  //���ƹ��캯��
		~LinkedList();									  //��������
		LinkedList<T>& operator= (const LinkedList<T>& L); //���ظ�ֵ����� 
		
		
		int getSize() const;							  //����������Ԫ�ظ��� 
		bool isEmpty() const;							  //�����Ƿ�Ϊ�� 
		
		
		void reset(int pos=0);							  //��ʼ���α��λ�� 
		void next();									  //ʹ�α��ƶ�����һ����� 
		bool endOfList() const;							  //�α��Ƿ�������β��
		int currentPosition(void) const;				  //�����α굱ǰλ��
		
		 
		void insertFront(const T& item);				  //�ڱ�ͷ������
		void insertRear(const T& item);					  //�ڱ�β��ӽ��
		void insertAt(const T& item);				 	  //�ڵ�ǰ���֮ǰ������
		void insertAfter(const T& item);			 	  //�ڵ�ǰ���֮�������
		
		
		T deleteFront() ;								  //ɾ��ͷ���
		void deleteCurrent();							  //ɾ����ǰ���
		
		
		T& data(); 										 //���ص�ǰ����Ա���ݵ�����
		const T& data() const;							 //���ص�ǰ����Ա���ݵĳ�����
		
		
		Node<T>* getfront();							 //���ر�ͷ 
		
		//��������ͷ����н����ڴ�ռ䡣������������"operator="����
		void clear();
};

//���ʵ�ֲ���

//˽�г�Ա����ʵ�֣�
//�����½�㣬������Ϊitem��ָ����ΪptrNext
template<class T>
Node<T>* LinkedList<T>:: newNode(const T& item,Node<T>* ptrNext/*=NULL*/)
{
	ptrNext->data=item;
	return ptrNext;
}


//�ͷŽ��
template<class T>
void LinkedList<T>:: freeNode(Node<T>* p)
{
	delete p; 
} 


		
//������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ�
//�����ƹ��캯����"operator="����
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


//���г�Ա����ʵ�֣� 
//���캯��
template<class T>
LinkedList<T>::LinkedList()
{
	front=rear=currPtr=prevPtr=0;
	size=0;
	position=0;
}


//���ƹ��캯��
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L)
{
	copy(L);
} 


//��������
template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
	size=0;
	position=0;
} 


//���ظ�ֵ�����
template<class T>
LinkedList<T>& LinkedList<T>:: operator=(const LinkedList<T>& L)
{
	clear();
	copy(L);
}


//����������Ԫ�ظ���
template<class T>
int LinkedList<T>:: getSize() const
{
	return size;
}


//�����Ƿ�Ϊ��
template<class T> 
bool LinkedList<T>:: isEmpty() const
{
	return size;
}


//��ʼ���α��λ�� 
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


//ʹ�α��ƶ�����һ�����
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


//�α��Ƿ�������β��
template<class T>
bool LinkedList<T>:: endOfList()const
{
	if(currPtr==rear)	return true;
	else return false;
} 


//�����α굱ǰλ��
template<class T>
int LinkedList<T>:: currentPosition(void)const
{
	return position;
} 


//�ڱ�ͷ������
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


//�ڱ�β��ӽ��
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


//�ڵ�ǰ���֮ǰ������
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


//�ڵ�ǰ���֮�������
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


//ɾ��ͷ���
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


//ɾ����ǰ���
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



//���ضԵ�ǰ����Ա���ݵ�����
template<class T>
T&  LinkedList<T>:: data()
{
	return currPtr->data;
}



//���ضԵ�ǰ����Ա���ݵĳ�����
template<class T>
const T&  LinkedList<T>:: data() const
{
	return currPtr->data;
}


//���ر�ͷ 
template<class T>
Node<T>* LinkedList<T>:: getfront()
{
	return front;
}



//��������ͷ����н����ڴ�ռ䡣������������"operator="����
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
