//Node.h
#ifndef NODE_H
#define NODE_H
template<class T>
class Node {
	private:
		Node<T>* next;								//ָ���̽���ָ�� 
	public:
		T data;										//������ 
		
		Node (const T& data, Node<T>* next=0);		//���캯�� 
		void insertAfter(Node<T> *p);				//�ڱ����֮�����һ��ͬ����p 
		Node<T>* deleteAfter();						//ɾ�������ĺ�̽�㡣 
		Node<T>* nextNode();						//��ȡ��̽��ĵ�ַ 
		const Node<T>* nextNode() const;			//��ȡ��̽��ĵ�ַ 
};

//���ʵ�ֲ���
//���캯��,��ʼ�����ݺ�ָ���Ա 
template<class T>
Node<T>::Node(const T& data, Node<T>* next/*=0*/):data(data),next(next){}

//���غ�̽���ָ��
template<class T>
Node<T>* Node<T>::nextNode() {
	return next;
}

//���غ�̽���ָ��
template<class T>
const Node<T>* Node<T>::nextNode() const {
	return next;
}

//�ڵ�ǰ���֮�����һ�����p

//���غ�̽���ָ��
template<class T>
void Node<T>::insertAfter(Node<T>* p) {
	p->next=next;
	next=p;
} 

//ɾ����ǰ���ĺ�̽��,���������ַ

//���غ�̽���ָ��
template<class T>
Node<T>* Node<T>::deleteAfter() {
	Node<T> *tempPtr=next;
	if(next==0)
		return 0;
	next=tempPtr->next;
	return tempPtr; 
} 
#endif
