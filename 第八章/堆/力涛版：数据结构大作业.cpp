#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

const int MaxNum=1000; 

string OutOfBounds() {return "Out Of Bounds!";}		//void型不能被throw 故改成string型并返回提示语 
string BadInput() {return "Bad Input!";}
string NoNum() {return "No Memory!";}

struct bbnode
{
	bbnode *parent;	//指向父结点的指针 
	bool LChild;	//左儿子结点标志 
};

struct HeapNode
{
	double uprofit; //结点的价值上界
	double profit;	//结点价值
	double weight;	//结点重量
	int level;		//活结点在子集树种所处的层序号
	bbnode *ptr;	//指向活结点在子集树中相应结点的指针 
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
		MaxHeap(int MaxHeapSize)				//构造函数 
			{
				MaxSize=MaxHeapSize;
				heap=new HeapNode[MaxSize+1];
				CurrentSize=0;
			}
		MaxHeap &Insert(const HeapNode &x);		//插入函数 
		MaxHeap &DeleteMax(HeapNode &x); 		//删除函数
		void Initialize(HeapNode a[],int size,int ArraySize);	//初始化
		
		int CurrentSize;	//当前堆的大小 
		int MaxSize;		//堆的最大容量
		HeapNode *heap;		//堆的元素 
};

MaxHeap &MaxHeap::Insert(const HeapNode &x)
{
	if(CurrentSize==MaxSize/*如果（当前堆大小=最大容量）*/) throw NoNum(); 
	//为x寻找插入位置
	int i=++CurrentSize;
	while(i!=1&&x>heap[i/2]/*x比父亲大*/) //i为x下标，i/2为x父亲下标
		{
			heap[i]=heap[i/2];//把x父亲移到x的位置 
			i=i/2;
		}
	heap[i]=x;
	return *this;
}

MaxHeap &MaxHeap:: DeleteMax(HeapNode &x)
{
	
	//将最大元素存于x 并从堆中删除 
	if(CurrentSize==0) throw OutOfBounds();
	x=heap[1];
	HeapNode y=heap[CurrentSize];
	CurrentSize--;
	int i=1,ci=2;	//i为当前结点，ci为i的孩子 
	while(ci<=CurrentSize)
		{
			if(ci<CurrentSize&&heap[ci]<heap[ci+1])ci++;	//ci指向较大的儿子
			if(y>heap[ci]) break;							//判断y能否放入heap[i]
			heap[i]=heap[ci];								//元素ci移至i位置 
			i=ci;											//i下标往下移 
			ci=i*2;											//ci下标往下移 
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
	HeapNode temp;		//用于作元素交换
	
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
		double d;		//单位重量价值 
}; 

class Knap
{
	public:
		Knap(double *pp,double *ww,double cc,int nn);	//构造函数+重排
		double Knapsack();
		double MaxKnapsack();
		double Bound(int i);
		void AddLiveNode(double up,double cp,double cw,bool ch,int lev);
		void output();
	private:
		bbnode *E;				//指向扩展结点的指针 
		double c;				//背包容量 
		int n;					//物品总数 
		double w[MaxNum];		//重量数组 
		double p[MaxNum];		//价值数组 
		double cw;				//当前装包重量 
		double cp;				//当前装包价值 
		int *bestx;				//最优解 
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
	//定义依单位重量价值排序的物品数组
	Object temp;		//用于交换
	Object *Q=new Object[n+1] ;
	for(i=1;i<=n;i++)
		{
			Q[i].ID=i;
			Q[i].d=1.0*pp[i]/ww[i];
		}
	sort(Q+1,Q+n+1,maxcmp);		//排序 
	for(i=1;i<=n;i++)			//排序后，赋值 p[],w[] 
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
	double cleft=c-cw;		//剩余容量
	double b=cp;			//b用来记录价值上界
	//以物品单位重量价值递减序装填剩余容量
	while(i<=n&&w[i]<=cleft) 
		{
			cleft-=w[i];	//这里的w[]已经排好序了 
			b+=p[i];
			i++;
		}
	//装填剩余容量装满背包
	if(i<=n) 	b+=p[i]/w[i]*cleft;
	return b;
}

//函数AddLiveNode将一个新的活结点插入到子集树和优先队列中
void Knap::AddLiveNode(double up,double cp,double cw,bool ch,int lev) 
{
	//将一个新的活结点插入到子集树和最大堆H中
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

//优先队列式分支限界法，返回最大价值，bestx返回最优解
double Knap::MaxKnapsack()
{
	int i=1;
	double bestp=0;		//当前最优解
	double up=Bound(1);	//价值上界 
	//搜索子集空间树
	while(i!=n+1) 		//非叶子结点
		{
			//检查当前扩展结点的左儿子
			double wt=cw+w[i] ;
			if(wt<=c/*重量条件*/)
				{
					if(cp+p[i]>bestp) bestp=cp+p[i];
					AddLiveNode(up,cp+p[i],wt,true,i+1);		//5个参数 
				}
			up=Bound(i+1);
			//检查当前扩展结点的右儿子 
			if(up>=bestp) 		//右子树可能含有最优解
				{
					AddLiveNode(up,cp,cw,false,i+1);
				} 
			//取下一扩展结点
			HeapNode N;
			H->DeleteMax(N);	//调用H的DeleteMax函数，N用于记录根 
			E=N.ptr;
			cp=N.profit;
			up=N.uprofit;
			cw=N.weight;
			i=N.level;
		} 
	//构造当前最优解 
	for(int j=n;j>0;j--)
		{
			bestx[j]=E->LChild;
			E=E->parent;
		}
	return cp;
}

double Knap::Knapsack() 
{
	double W=0,P=0;		//装包物品重量,价值
	for(int i=1;i<=n;i++) 
		{
			P+=p[i];
			W+=w[i];
		}
	if(W<=c)			//全部装下 
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
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
	int n=5;
	double c=10;
	double p[6]={0,6,3,5.5,4,6};		//下标0不记 
	double w[6]={0,2,2,6,5,6.5};

	Knap K=Knap(p,w,c,n);
	cout<<"The max sum_value is:"<<endl<<K.Knapsack()<<endl;
	cout<<"The optimum solution"<<endl;
	K.output();
	cout<<endl<<endl;
	return 0; 
}
