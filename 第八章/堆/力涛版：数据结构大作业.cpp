#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

const int MaxNum=1000; 

string OutOfBounds() {return "Out Of Bounds!";}		//void�Ͳ��ܱ�throw �ʸĳ�string�Ͳ�������ʾ�� 
string BadInput() {return "Bad Input!";}
string NoNum() {return "No Memory!";}

struct bbnode
{
	bbnode *parent;	//ָ�򸸽���ָ�� 
	bool LChild;	//����ӽ���־ 
};

struct HeapNode
{
	double uprofit; //���ļ�ֵ�Ͻ�
	double profit;	//����ֵ
	double weight;	//�������
	int level;		//�������Ӽ����������Ĳ����
	bbnode *ptr;	//ָ��������Ӽ�������Ӧ����ָ�� 
	bool operator<(const HeapNode &other)const
		{
			//if((profit/weight)<(other.profit/other.weight)) return true;
			if((uprofit)<(other.uprofit)) return true;
			else return false;
		}	
	bool operator>(const HeapNode &other)const
		{
			//if((profit/weight)>(other.profit/other.weight))	return true;
			if((uprofit)>(other.uprofit)) return true;
			else return false;
		}
};

class MaxHeap
{
	public:
		MaxHeap(int MaxHeapSize)				//���캯�� 
			{
				MaxSize=MaxHeapSize;
				heap=new HeapNode[MaxSize+1];
				CurrentSize=0;
			}
		MaxHeap &Insert(const HeapNode &x);		//���뺯�� 
		MaxHeap &DeleteMax(HeapNode &x); 		//ɾ������
		void Initialize(HeapNode a[],int size,int ArraySize);	//��ʼ��
		
		int CurrentSize;	//��ǰ�ѵĴ�С 
		int MaxSize;		//�ѵ��������
		HeapNode *heap;		//�ѵ�Ԫ�� 
};

MaxHeap &MaxHeap::Insert(const HeapNode &x)
{
	if(CurrentSize==MaxSize/*�������ǰ�Ѵ�С=���������*/) throw NoNum(); 
	//ΪxѰ�Ҳ���λ��
	int i=++CurrentSize;
	while(i!=1&&x>heap[i/2]/*x�ȸ��״�*/) //iΪx�±꣬i/2Ϊx�����±�
		{
			heap[i]=heap[i/2];//��x�����Ƶ�x��λ�� 
			i=i/2;
		}
	heap[i]=x;
	return *this;
}

MaxHeap &MaxHeap:: DeleteMax(HeapNode &x)
{
	
	//�����Ԫ�ش���x ���Ӷ���ɾ�� 
	if(CurrentSize==0) throw OutOfBounds();
	x=heap[1];
	HeapNode y=heap[CurrentSize];
	CurrentSize--;
	int i=1,ci=2;	//iΪ��ǰ��㣬ciΪi�ĺ��� 
	while(ci<=CurrentSize)
		{
			if(ci<CurrentSize&&heap[ci]<heap[ci+1])ci++;	//ciָ��ϴ�Ķ���
			if(y>heap[ci]) break;							//�ж�y�ܷ����heap[i]
			heap[i]=heap[ci];								//Ԫ��ci����iλ�� 
			i=ci;											//i�±������� 
			ci=i*2;											//ci�±������� 
		}
	heap[i]=y;
	return *this;
}
void Sift(HeapNode r[],int k,int m)
{
	int i=k;int j=2*i;
	while(j<=m)
		{
			if(j<m&&r[j]<r[j+1])j++;
			if(r[i]>r[j]) break;
			else
				{
					HeapNode temp=r[i];
					r[i]=r[j];
					r[j]=temp;
					i=j;j=2*i;
				}
		}
}
void MaxHeap::Initialize(HeapNode a[],int size,int ArraySize)
{
	heap=a;
	CurrentSize=size;
	MaxSize=ArraySize;
	HeapNode temp;		//������Ԫ�ؽ���
	
	for(int i=CurrentSize/2;i>=1;i--) 
		Sift(heap,i,CurrentSize);
	for(int i=1;i<CurrentSize;i++)
		{
			temp=heap[1];
			heap[1]=heap[CurrentSize-i+1];
			heap[CurrentSize-i+1]=temp;
			Sift(heap,1,CurrentSize-i);
		}
	return ;
}

class Object
{
	public:
		int ID;
		double d;		//��λ������ֵ 
}; 

class Knap
{
	public:
		Knap(double *pp,double *ww,double cc,int nn);	//���캯��+����
		double Knapsack();
		double MaxKnapsack();
		double Bound(int i);
		void AddLiveNode(double up,double cp,double cw,bool ch,int lev);
		void output();
	private:
		bbnode *E;				//ָ����չ����ָ�� 
		double c;				//�������� 
		int n;					//��Ʒ���� 
		double w[MaxNum];		//�������� 
		double p[MaxNum];		//��ֵ���� 
		double cw;				//��ǰװ������ 
		double cp;				//��ǰװ����ֵ 
		int *bestx;				//���Ž� 
		MaxHeap *H;
};

void Knap::output()
{
	for(int i=1;i<=n;i++)	cout<<bestx[i]<<" ";
	cout<<endl; 
}

int maxcmp(Object a,Object b)
{
	return a.d>b.d;
}
Knap::Knap(double *pp,double *ww,double cc,int nn)
{
	int i,j,k;
	c=cc;
	n=nn;
	cw=0;
	cp=0;
	E=0;
	
	bestx=new int[n+1];
	H=new MaxHeap(1000);
	cout<<"n="<<n<<" "<<"c="<<c<<endl;
	cout<<"The input value(p[]) is:"<<endl;
	for(int i=1;i<=n;i++) cout<<pp[i]<<" ";
	cout<<endl;
	cout<<"The input weight(w[]) is"<<endl;
	for(int i=1;i<=n;i++) cout<<ww[i]<<" ";
	cout<<endl;
	cout<<"The input ID is:"<<endl;
	for(int i=1;i<=n;i++) cout<<i<<" ";
	cout<<endl;
	//��������λ������ֵ�������Ʒ����
	Object temp;		//���ڽ���
	Object *Q=new Object[n+1] ;
	for(i=1;i<=n;i++)
		{
			Q[i].ID=i;
			Q[i].d=1.0*pp[i]/ww[i];
		}
	sort(Q+1,Q+n+1,maxcmp);		//���� 
	for(i=1;i<=n;i++)			//����󣬸�ֵ p[],w[] 
		{
			p[i]=pp[Q[i].ID];
			w[i]=ww[Q[i].ID];
		}
	cout<<"The sorted value(p[]) is:"<<endl;
	for(int i=1;i<=n;i++)	cout<<p[i]<<" ";
	cout<<endl;
	cout<<"The sorted weight(w[]) is:"<<endl;
	for(int i=1;i<=n;i++)	cout<<w[i]<<" ";
	cout<<endl;
	cout<<"The sorted ID is:"<<endl;
	for(int i=1;i<=n;i++)	cout<<Q[i].ID<<" ";
	cout<<endl<<endl<<endl;
}

double Knap::Bound(int i)
{
	double cleft=c-cw;		//ʣ������
	double b=cp;			//b������¼��ֵ�Ͻ�
	//����Ʒ��λ������ֵ�ݼ���װ��ʣ������
	while(i<=n&&w[i]<=cleft) 
		{
			cleft-=w[i];	//�����w[]�Ѿ��ź����� 
			b+=p[i];
			i++;
		}
	//װ��ʣ������װ������
	if(i<=n) 	b+=p[i]/w[i]*cleft;
	return b;
}

//����AddLiveNode��һ���µĻ�����뵽�Ӽ��������ȶ�����
void Knap::AddLiveNode(double up,double cp,double cw,bool ch,int lev) 
{
	//��һ���µĻ�����뵽�Ӽ���������H��
	bbnode *b=new bbnode;
	b->parent=E;
	b->LChild=ch;
	
	HeapNode N;
	N.uprofit=up;
	N.profit=cp;
	N.weight=cw;
	N.level=lev;
	N.ptr=b; 
	
	H->Insert(N);
}

//���ȶ���ʽ��֧�޽編����������ֵ��bestx�������Ž�
double Knap::MaxKnapsack()
{
	int i=1;
	double bestp=0;		//��ǰ���Ž�
	double up=Bound(1);	//��ֵ�Ͻ� 
	//�����Ӽ��ռ���
	while(i!=n+1) 		//��Ҷ�ӽ��
		{
			//��鵱ǰ��չ���������
			double wt=cw+w[i] ;
			if(wt<=c/*��������*/)
				{
					if(cp+p[i]>bestp) bestp=cp+p[i];
					AddLiveNode(up,cp+p[i],wt,true,i+1);		//5������ 
				}
			up=Bound(i+1);
			//��鵱ǰ��չ�����Ҷ��� 
			if(up>=bestp) 		//���������ܺ������Ž�
				{
					AddLiveNode(up,cp,cw,false,i+1);
				} 
			//ȡ��һ��չ���
			HeapNode N;
			H->DeleteMax(N);	//����H��DeleteMax������N���ڼ�¼�� 
			E=N.ptr;
			cp=N.profit;
			up=N.uprofit;
			cw=N.weight;
			i=N.level;
		} 
	//���쵱ǰ���Ž� 
	for(int j=n;j>0;j--)
		{
			bestx[j]=E->LChild;
			E=E->parent;
		}
	return cp;
}

double Knap::Knapsack() 
{
	double W=0,P=0;		//װ����Ʒ����,��ֵ
	for(int i=1;i<=n;i++) 
		{
			P+=p[i];
			W+=w[i];
		}
	if(W<=c)			//ȫ��װ�� 
		{
			for(int j=1;j<=n;j++) bestx[j]=1;
			return P;
		}
	else
		{
			return MaxKnapsack() ;
		}
} 
int main()
{
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
	int n=5;
	double c=10;
	double p[6]={0,6,3,5.5,4,6};		//�±�0���� 
	double w[6]={0,2,2,6,5,6.5};

	Knap K=Knap(p,w,c,n);
	cout<<"The max sum_value is:"<<endl<<K.Knapsack()<<endl;
	cout<<"The optimum solution"<<endl;
	K.output();
	cout<<endl<<endl;
	return 0; 
}
