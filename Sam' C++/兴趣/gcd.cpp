#include <iostream>
using namespace std;
#define DEBUG
long long  gcd(long long  m, long long  n)//������xm+yn=gcd�е�x y��
{
	if (m < n)	{ long long  sto = m; m = n, n = sto; }
	static long long  x = 1, y = 0, tempm;
	static bool first = 1;
	if (first == 1)												//��һ�ν��룬���عرա���¼mֵ
	{
		first = 0;
		tempm = m;
	}
	if (n == 0)
	{	
		cout << m << endl;
		x = 1, y = 0;											//�޸Ĵ�ǰx,y��ֵ���ݹ���е�һ���ˣ���ʼ����x,y.
		return m;
	}

	else
	{
		printf("%lld��%lld=%lld*%lld+%lld\n", m, n,m / n, n, m%n);//��ʾշת����ĵݹ����
		long long  d=gcd(n, m%n);								//�ȴ��棬�������֮����return��
		long long  tempx = x;										//x,y����static������������ʧ��
		x = y;
		y = tempx - y*(m / n);
		printf("%lld*%lld+%lld*%lld=%lld\n", x,m , y,n, x*m + y*n);//��ʾ�������̡�
		if (tempm == m)									//��⵽mֵ���Ѿ��ص������ջ�����xy
		{
			printf("%lld %lld\n", x, y);
			first = 1;
		}
		return d;
	}

}

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	gcd(16920,14355);
	cout << endl;
	gcd(3,35);
	cout<<endl;
	gcd(5,21);
	gcd(7,15);
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}