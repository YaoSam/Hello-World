#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "LinkedList.h"
using namespace std;
LinkedList <int> L;
int bianli()
{
	Node<int> *now=L.getfront();
	while(now!=0)
		{
			cout<<now->data<<" "; 
			now=now->nextNode();
		}
	cout<<endl;
	return 0;
}
int main()
{
	srand(time(0));
	cout << sizeof(Node<int>) << endl;
	for(int i=1;i<=1000000;i++)
		{
			L.insertFront(i);
			//int seed=rand()%4;
			//int item=rand()%100;
			//if(seed==0) 
			//	{
			//		cout<<item<<"插入到头"<<endl;
			//		L.insertFront(item);
			//		bianli();
			//		cout<<"当前结点位置是："<<L.currentPosition()+1<<endl; 
			//	}
			//else if(seed==1) 
			//	{
			//		cout<<item<<"插入到尾"<<endl;
			//		L.insertRear(item);
			//		bianli();
			//		cout<<"当前结点位置是："<<L.currentPosition()+1<<endl; 
			//	}
			//else if(seed==2) 
			//	{
			//		cout<<item<<"插入到当前结点之前"<<endl;
			//		L.insertAt(item);
			//		bianli();
			//		cout<<"当前结点位置是："<<L.currentPosition()+1<<endl; 
			//	}
			//else if(seed==3) 
			//	{
			//		cout<<item<<"插入到当前结点之后"<<endl;
			//		L.insertAfter(item);
			//		bianli();
			//		cout<<"当前结点位置是："<<L.currentPosition()+1<<endl; 
			//	}
		}
	//22112
	//022112
	//L.next();
	system("pause");
	L.clear();
	system("pause");
	return 0;
}

