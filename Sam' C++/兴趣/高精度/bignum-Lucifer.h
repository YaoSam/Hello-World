/*
*
*����������������������  ����+ +
*�������������������ߩ��������ߩ� + +
*����������������������������  �� ��
*�������������������������������� ++ + + +
*��������	   |   ��������������   ��+
*����������������������������  �� +
*�����������������������ߡ�������
*����������������������������  �� + +
*��������������������������������
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
#include <iostream>
#include <sstream>	//���ڽ����ת��Ϊ�ַ���
#include <iomanip> //���ڸ�ʽ�����������floatת�����ַ���
#include <omp.h>
#include <string>
#define Re(i,n)	for(int i=1;i<=n;++i)
const int ten[5] = { 0, 1, 10, 100, 1000 };		//������λ��
class N; class Z; class Q; class R;
typedef Z Int;
typedef R Float;
using namespace std;

void debug(std::string warning)
{
	std::cout << warning << std::endl;
	std::cout << "This program is closing"<<std::endl;
	system("pause");
	exit(1);
}


//����Ϊһ���ģ�塣��Ϊ+=��-=��*=��/=... ...����������һ���+-*/�����ء�
//ƽʱx=�Ĳ���Ч��Ӧ��Ҫ��һ��... ...��Ϊ��������û�ж�this���о�ϸ�Ĳ��������Ի����´�������Ч�ʻ��Ե͡�
template <typename T>		T &operator+=(T &This, T const &num)				{ This = This + num; return This; }
template <typename T>		T &operator-=(T &This, T const &num)				{ This = This - num;	return This; }
template <typename T>		T &operator*=(T &This, T const &num)				{ This = This * num;	return This; }
template <typename T>		T &operator/=(T &This, T const &num)				{ This = This / num;	return This; }
template <typename T>		T &operator%=(T &This, T const &num)				{ This = This % num; return This; }
template <typename T>		T &operator++(T &This, int)								{ This = This + 1;	return This; }
template <typename T>		T operator++(T &This)										{ T temp(This);	This = This + 1;	return This; }
template <typename T>		T &operator--(T &This, int)								{ This = This - 1;	return This; }
template <typename T>		T operator--(T &This)										{ T temp(This);	This = This - 1;	return This; }
//������>>=
template <typename T>		T operator>>(T const &This, int movement)		{ T temp(This); temp >>= movement; return temp; }
template <typename T>		T operator<<(T const &This, int movement)		{ T temp(This); temp >>= -movement; return temp; }
template <typename T>		T &operator<<=(T &This, int movement)			{ This >>= -movement;						return This; }
//���������ص�>��==
template <typename T>		bool operator>=(T const &a, T const &b)			{ return a > b || a == b; }
template <typename T>		bool operator!=(T const &a, T const &b)			{ return !(a == b); }
template <typename T>		bool operator<(T const &a, T const &b)				{ return !(a > b || a == b); }
template <typename T>		bool operator<=(T const &a, T const &b)			{ return !(a > b); }
template <typename T>
T gcd(T const &m, T const &n)//������%
{
	if (n == T(0)) return m;
	else return gcd(n, m%n);
}
template <typename T>		
/*������= . ���Ч�ʵĻ���ֱ�Ӹ��ĵ�ַ��ָ��*/
void Swap(T &a, T &b)	{ T temp = a;	a = b;	b = temp; }
template <typename T>
//�������ص�<<�����������������ת��Ϊ�ַ���
std::string &TurnToStr(T const &This, std::string &str)
{
	std::ostringstream ou;
	ou << This;						//����֮ǰ��<<�����ء�
	str = ou.str();
	return str;
}
class N  //��Ȼ���������㡣
{
	int  *num;
	int length;	//������. ��λ��һ����num[1]-num[length]		
	//��Ⲣ����length
	int CheckLen(int max);	
	/*�����2�������������Ż�100һ�µĳ�����*/
	N &half();
	/*���������Ѿ�����Ŀռ�Ϊ��������*/
	int *Space( int const &n)const;
public:
	N() :length(1), num(Space(5)){}
	N(std::string str);
	N(unsigned int n);
	N(N const &other);
	~N()	{ delete[] num; }
	friend std::ostream &operator<<(std::ostream &out, N const &other);
	N &operator=(N const &other);
	bool operator>(N const &other)const;
	bool operator==(N const &other)const;
	N &operator+=(N const &other);	
	N operator +(N  const &other)const;
	N &operator-=(N const &other);
	N operator-(N const &other)const;
	N operator *(N const &other)const;
	N operator/(N const &other)const;
	N operator%(N const &other)const;
	N &operator*=(N const &other);
	/*����λ��Mλ ��������ʽ���*/
	N &operator>>=(int movement);
	/*��ȡĳһλ�����֣�ֻ����ֵ����������*/
	int operator[](int const &x)const	{ return (num[(x-1) / 4+1] / ten[(x+3) % 4 + 1]) % 10; }
	/*��ȡ�������ֵ�λ��*/
	int getdigit()const;	
	friend void Swap(N &a, N &b);		
};
N::N(std::string str)
{
	length = str.length();
	num = Space(length / 4 + 5);
	Re(i, length)
		if (str[length - i] != '0') //�����0�Ͳ��ô�������ˡ�
			num[(i - 1) / 4 + 1] += ten[(i - 1) % 4 + 1] * (str[length - i] - '0');
	CheckLen(length / 4 + 1);
}
N::N(unsigned int n)
{
	num = Space(5);
	if (n > 0)
	{
		length = 0;
		if (n == 0)	++length;
		while (n != 0)
		{
			num[++length] = n % 10000;
			n /= 10000;
		}
	}
	else length = 1;
}
N::N(N const &other)
{
	num = Space(other.length + 2);
	length = other.length;
	memcpy(num, other.num, sizeof(int)*(other.length + 2));
}
N &N::operator=(N const &other)
{
	if (this != &other)
	{
		if (length < other.length+2) //����������������ҾͲ������ˡ�
		{
			delete[] num;
			num = Space(other.length + 5);
		}
		else memset(num, 0, sizeof(int)*length + 2);
		memcpy(num, other.num, sizeof(int)*(other.length + 2));
		length = other.length;
	}
	return *this;
}
std::ostream &operator<<(std::ostream &out, N const &This)
{
	Re(i, This.length)
	{
		if (i != 1)
		{
			if (This.num[This.length - i + 1] < 10)					out << "000";
			else if (This.num[This.length - i + 1] < 100)			out << "00";
			else if (This.num[This.length - i + 1] < 1000)		out << 0;
		}
		out << This.num[This.length + 1 - i];		//length,length-2,... ...1
	}
	return out;
}
std::istream &operator>>(std::istream &in, N &This)
{
	std::string a;
	in >> a;
	This = N(a);
	return in;
}
int N::getdigit()const
{
	Re(i, 4)	
		if (num[length] >= ten[5 - i]) //4,3,2,1; 1000,100,10,1
			return 1 - i + length * 4;
	return length * 4-3;
}
bool N::operator>(N const &other)const
{
	if (length != other.length)return (length > other.length);
	Re(i, length)
		if (num[length - i + 1] != other.num[length - i + 1])
			return num[length - i + 1]>other.num[length - i + 1];
	return 0;
}
bool N::operator==(N const &other)const
{
	if (length != other.length)	return 0;
	Re(i, length) //������ö��߳��Ż���
		if (num[i] != other.num[i])
			return 0;
	return 1;
}

int N::CheckLen( int max)
{
	length = 1; //��ֹ����Ϊ�㡣
	Re(i, max)
		if (num[max - i + 1] > 0) //���пռ䶼�Ѿ����㡣
		{
			length = max - i + 1;
			break;
		}
	return length;
}

int *N::Space( int const &n)const	
{
	if (n <= 0)			debug("WTF!!!You apply Negitive memory?!");//���볤��Ϊ����������һ��
	int *p = new int[n];
	if (p == NULL)	debug("Sorry. I fail to apply memory... ...");	//�����ڴ����һ�¡�
	memset(p, 0, sizeof(int)*n);		//���㡣CheckLen��ʱ�򷽱㡣
	return p;
}
N &N::operator+=(N const &other)	//ͨ����ϸ�µĲ������Ż�Ч�ʡ�
{
	if (length <= other.length)				//����ռ䲻��������������ɡ��ռ乻�����ˡ�
	{
		int *tempnum = num;
		num = Space(other.length + 5);
		memcpy(num, tempnum, sizeof(int)*(length + 2));
		delete[] tempnum; //��intspace�ĵط�����delete��
	}
	int max = length > other.length ? length : other.length;
#pragma omp parallel for
	Re(i, other.length)
		num[i] += other.num[i];
	Re(i, max)
		if (num[i] >= 10000)
		{
			++num[i + 1];
			num[i]%=10000;
		}
	CheckLen(max + 1);
	return *this;
}
N N::operator+(N const &other)const
{
	if (length >= other.length)	{ N temp(*this); temp += other; return temp; }//ͨ���Ƚϴ�С�������ڴ�Ĳ�����
	else									{ N temp(other); temp += *this; return temp; }
}
N &N::operator-=(N const &other)
{
	if (*this < other)		debug("Well, I'm a N number. I can't be negetive. I just can't."); //��Ȼ���ļ��������ܳ��ָ�����
	else if (*this == other) *this = N(0);
	else
	{
#pragma omp parallel for
		Re(i, other.length)
			num[i] -= other.num[i];
		Re(i, length)
			if (num[i] < 0)
			{
				--num[i + 1];
				num[i] += 10000;
			}
		CheckLen(length);
	}
	return *this;
}

N N::operator-(N const &other)const
{
	N temp(*this);
	temp -= other;
	return temp;
}

N N::operator*(N const &other)const
{
	int max = length + other.length + 1;
	N ans;										//�����洢�𰸡�
	delete[] ans.num;						//�ͷ��ڴ�
	ans.num = Space(max + 5);		//����͵��ںŲ�һ���ˡ�
	Re(i, length)
		if (num[i] != 0)						//��΢���һ��Ч�ʡ�
		{
#pragma omp parallel for
			Re(j, other.length)				//����Ҳ���Բ��Ϊ����ѭ�����в���,��ϧЧ��̫�͡�
				ans.num[i + j - 1] += num[i] * other.num[j];
			Re(j, other.length)
				if (ans.num[i + j - 1] >= 10000)					//���뼰ʱ��λ��ֹ�����
				{
					ans.num[i + j] += ans.num[i + j - 1] / 10000;
					ans.num[i + j - 1] %= 10000;					//0... ...MAX
				}
		}
	ans.CheckLen(max);
	return ans; //����ʱҪ����һ�οռ䡣
}
//*=����Ҫ�������οռ䡣Ч����ʵ��ֱ��*��ࡣ
N &N::operator*=(N const &other) 
{
	N temp(*this);
	int max = length + other.length + 1;
	delete[] num;
	num = Space(max + 5); //��������ϻ���Ҫ��������ģ��Ͳ������ж��ˡ�
	Re(i, length) //�൱��length��+��
		if (temp.num[i] != 0)
			Re(j, other.length)
				if (other.num[j] != 0)
				{
					num[i + j - 1] += temp.num[i] * other.num[j];
					if (num[i + j - 1] >= 10000)
					{
						num[i + j] += num[i + j - 1] / 10000; //��+Ψһ��������ʵ�ӷ�Ҳ�ǿ�����ô��ġ�
						num[i + j - 1] %= 10000;
					}
				}

	CheckLen(max);
	return *this; 
}

N &N::half() //Ϊ��������
{
	if (*this == 1)	return *this;
	else
		Re(i, length) 
	{
		if (i != length&&num[length - i + 1] % 2) //��1��λ��
			num[length - i] += 10000;
		num[length - i + 1] >>= 1;
	}
	CheckLen(length);
	return *this;
}
N N::operator/(N const &other)const
{
	N ans, sum, Half(*this), r;
	Half.half();
	while (*this >= sum + other) //sum=other*temp;
	{
		r = Half*other;
		if (sum + r <= *this) sum += r, ans += Half; //sum=other*(temp+half);
		Half.half();
	}
	return ans;
}
N N::operator%(N const &other)const //��ģ,ֻ�Ǽ򵥵��޸���һ��/�ķ���ֵ��
{
	N temp, sum;
	N Half(*this);
	N r;
	while (*this >= sum + other) //sum=other*temp;
	{
		r = Half*other;
		if (sum + r <= *this) sum += r, temp += Half; //sum=other*(temp+half);
		Half.half();
	}
	return *this - sum;
}
/*������������ֱ���޸ĵ�ַ����friend ������˵�ǿ��*/
void Swap(N &a, N &b)  
{
	Swap(a.num, b.num);
	Swap(a.length, b.length);
}

N &N::operator>>=(int movement) 
{
	if (movement == 0)	return *this;
	int big = movement / 4, small = movement % 4;
	int newlength=length-big;								//big<0�����ơ��������ӡ�
	if (newlength <= 0) {*this = N(0); return *this; } //�����и�Сbug
	int *newnum=Space(newlength+5);				//����ǵ��ͷ�
	if (movement>0)											//���ơ����١�
	{
		if (small == 0)
			Re(i, newlength) //4�ı���ֱ�Ӹ��ơ�
				newnum[i] = num[i + big];
		else
			Re(i, newlength)
		{
			newnum[i] += num[i + big] / ten[small + 1];					//��������ʽ���
			newnum[i] += (num[i + big + 1] % ten[small  + 1])*ten[5 - small];
		}
	}
	else
	{
		big *= -1, small *= -1;
		if (small == 0)
			Re(i, length)
				newnum[i+big] = num[i];
		else
			Re(i, length)
			{
				newnum[i + big] += (num[i] % ten[5-small])*ten[small+1];//ֻ�Ǹ�������ʽ���±귴�ˡ�
				newnum[i + big + 1] += (num[i] / ten[5-small]);
			}
	}
	delete[] num;
	num = newnum;
	CheckLen(newlength+1);
	return *this;
}

/************************************************************************/
/*                             �����ķָ���                              */
/************************************************************************/
class Z //��������sign��������
{
	N num;
	bool sign; //���š�
public:
	Z() :num(), sign(0)	{}
	Z(std::string str);
	Z(int other) : sign(other < 0), num(other*(other < 0 ? -1 : 1))	{}
	Z(Z const &other) :num(other.num), sign(other.sign)	{}
	Z(N const &other) : num(other), sign(0){}
	friend std::ostream &operator<<(std::ostream &out, Z const &other);
	Z &operator=(N const &other)					{ num = other; sign = 0; return *this; }
	bool operator>(Z const &other)const			{ return sign != other.sign ? other.sign : ((!sign) == num > other.num); }
	bool operator==(Z const &other)const		{ return sign == other.sign&&num == other.num; } //���ȱȽ�sign
	Z operator +(Z  const &other)const;
	Z operator-(Z const &other)const;
	Z operator *(Z const &other)const;
	Z operator/(Z const &other)const;
	Z operator%(Z const &other)const;
	Z &operator+=(Z const &other);
	Z &operator-=(Z const &other);
	Z &operator*=(Z const &other);
	Z &operator>>=(int movement){ num >>= movement; return *this; }
	int getdigit()const	{ return num.getdigit(); }
	friend void Swap(Z &a, Z &b);
	friend R;
};

Z::Z(std::string str) :
sign(str[0] == '-'), num(sign ? str : str.substr(1, str.length() - 1))
{
	if (sign)num = N(str.substr(1, str.length() - 1));
	else num = N(str);
	if (num == 0)sign = 0;
}
std::ostream &operator<< (std::ostream &out, Z const &This)
{
	if (This.sign)out << '-';
	out << This.num;
	return out;
}
std::istream	&operator>>(std::istream &in, Z &This)
{
	std::string a;
	in >> a;
	This = Z(a);
	return in;
}

Z Z::operator+(Z const &other)const
{
	Z temp;
	if (sign != other.sign)
	{
		if (num > other.num)  //3+(-1)=2, -3+(+1)=-(3-1)=-2
		{
			temp.num = num - other.num;
			temp.sign = sign;
		}
		else							//(+1)+(-2)=-1,(-1)-(-2)=1
		{
			temp.num = other.num - num;
			temp.sign = !sign;
		}
	}
	else								//1+2=3,-1+(-3)
	{
		temp.sign = sign;
		temp.num = num + other.num;
	}
	if (temp.num == 0)temp.sign = 0;
	return temp;
}
Z Z::operator-(Z const &other)const //(a - b) = a + (-b) ��֪��������Ч�ʻ�Ƚϵ͡� TODO
{
	Z temp(other);
	temp.sign = !other.sign;
	return temp + *this;
}
Z Z::operator*(Z const &other)const
{
	Z temp;
	temp.num = num*other.num;
	temp.sign = (sign != other.sign);		//��ͬ�ż�Ϊ-��
	return temp;
}
Z Z::operator/(Z const &other)const
{
	if (other == Z())
	{
		std::cout << "��������Ϊ��" << std::endl;
		return Z();
	}
	Z temp;
	temp.num = num / other.num;
	if (temp.num != N())		temp.sign = !(sign == other.sign);
	else temp.sign = 0;
	return temp;
}
Z Z::operator%(Z const &other)const
{
	if (other == Z())	debug( "��ĸ����Ϊ��" );
	Z temp;
	temp.num = num% other.num;
	if (temp.num == N())		temp.sign = 0;
	else temp.sign = (sign != other.sign);
	return temp;
}
Z &Z::operator+=(Z const &other)
{
	if (sign != other.sign)
	{
		if (num > other.num)			 //3+(-1)=2, -3+(+1)=-(3-1)=-2
			num -= other.num;
		else									//(+1)+(-2)=-1,(-1)-(-2)=1
		{
			num = other.num - num; //�����û�취�ˡ�
			sign = !sign;
		}
	}
	else										//1+2=3,-1+(-3)
		num += other.num;
	if (num == 0)sign = 0;
	return *this;
}
Z &Z::operator-=(Z const &other)
{
	if (sign != other.sign) //+1-(-2)=1+2 ,-2-(+1)=-2-1
		num = other.num;
	else								//1+2=3,-1+(-3)
	{
		if (num > other.num)			 //3-(+1)=2, -3-(-1)=-3+1=-2
			num -= other.num;
		else									//(+1)-(+2)=-1,	(-1)-(-2)=-1+2=1
		{
			num = other.num - num;
			sign = !sign;
		}
	}
	if (num == 0)sign = 0;
	return *this;
}
Z &Z::operator*=(Z const &other)
{
	num *= other.num;
	sign = (sign != other.sign);
	return *this;
}
void Swap(Z &a, Z &b)
{
	Swap(a.num, b.num);
	if (a.sign != b.sign) a.sign = b.sign, b.sign = !b.sign;
}

/************************************************************************/
/*                             �����ķָ���                              */
/************************************************************************/
class Q //�������������Ч���е�͡���ΪҪ��GCD.
{
	Z up, down;//���ӷ�ĸ
public:
	Q() :up(1), down()	{}
	Q(Z up, Z down);
	Q(N up, N down);
	Q(int up, int down);
	Q(int const &other);
	Q(Q const &other)										{ up = other.up; down = other.down; }
	friend std::ostream &operator<<(std::ostream &out, Q const &other);
	bool operator>(Q const &other)	const	{ return up*other.down - down*other.up > 0; }
	bool operator==(Q const &other)	const	{ return up == up&&down == down; }
	Q operator +(Q const &other)		const	{ return Q(up*other.down + other.down, down*other.down); }
	Q operator - (Q const &other)		const	{ return Q(up*other.down - other.down*down, down*other.down); }
	Q operator * (Q const &other)		const	{ return Q(up*other.up, down*other.down); }
	Q operator / (Q const &other)		const	{ return Q(up*other.down, down*other.up); }
};
Q::Q(Z one, Z two = 1)
{
	if (two == Z(0))
		debug("��ĸ����Ϊ��");
	else
	{
		Z GCD = gcd(one, two);
		if (GCD != Z(1))
		{
			up = one / GCD;
			down = two / GCD; //TODO ���˾��������Ч��Ӧ�ø���һ��
		}
		else up = one, down = two;
		if (down<Z(0))					//���ַ�ĸΪ�������Ӿ������š�
			up *= Z(-1), down *= Z(-1); //ֻ�ǲ���ֱ�ӵ���sign���ѡ�
	}
}
Q::Q(N one, N two = 1)
{
	if (two == N())
		debug("��������Ϊ��");
	else
	{
		N GCD = gcd(one, two);
		up = one / GCD;
		down = two / GCD;
	}
}
Q::Q(int const &other) :up(Z(other)), down(1){}
Q::Q(int one = 0, int two = 1)
{
	if (two == 0)
		debug("��������Ϊ��");
	up = Z(one / gcd(one, two));
	down = Z(two / gcd(one, two));
}
std::ostream &operator<<(std::ostream &out, Q const &This)
{
	if (This.down == Z(1))	out << This.up;
	else 								out << This.up << '/' << This.down;
	return out;
}
/************************************************************************/
/*                             �����ķָ���						                           */
/************************************************************************/
class R //������
{
	Z num;
	unsigned point; //С������num���һλ�ľ��롣
public:
	void setprecision(unsigned int Precision);
	R() :num(), point(0){}
	R(std::string str);
	R(double const &other);
	R(R const &other) :num(other.num), point(other.point)	{}
	R(Z const &other) :num(other), point(0){}
	friend std::ostream &operator<<(std::ostream &out, R const &other);
	R &operator=(N const &other)				{ num = other, point = 0; }
	bool operator>(R const &other)	const;
	bool operator==(R const &other)	const;
	//����С����������
	R operator +(R  const &other)		const; 
	R operator - (R const &other)		const;	
	//С���㵥�����㡣
	R operator *(R const &other)			const;	
	//ţ�ٵ�����
	R operator/(R const &other)			const;	
	R &operator*=(R const &other)		{ num *= other.num;		point += other.point; return *this; }
	R &operator>>=(int movement)	{ num >>= movement; point -= movement; return *this; }
};
R::R(std::string str)
{
	int length = str.length();
	//point = length-str.find(".")+1;
	point = 0;
	Re(i, length) //��point��
		if (str[i - 1] == '.')
		{
			point = length - i;
			break;
		}
	if (point!=0)
	{
		if (point != length - 1)
			num = Z(str.substr(0, length - point - 1) + str.substr(length - point, point)); //��С�����޳���
		else
			num = Z(str.substr(1, length - 1));
	}
	else num = Z(str), point = 0;
}
R::R(double const &other) //֧�ֵľ���Ϊʮ��λ������float�;��Ȼ�����ʧ��
{
	std::ostringstream out;
	out << std::setprecision(15) << other;
	std::string str(out.str());
	*this = R(str);
}

std::ostream &operator<<(std::ostream &out, R const &This)
{
	std::string temp; 
	TurnToStr(This.num,temp);		//��ʵ�����Ч�ʱȽϵ͡������������Ǻܴ�Ļ��������ˡ�
	if (temp.length() <= This.point)	//С��1��С����ǰ�油��0��
		temp.insert(0, This.point - temp.length() + 1, '0');
	if (This.point != 0)						//���м����С���㡣
		temp.insert(temp.length() - This.point, "."); //��Ϊ�����Ѿ��ı䡣����Ҫ��temp.length.
	out << temp;
	return out;
}
std::istream &operator>>(std::istream &in, R &This)
{
	std::string a;
	in >> a;
	This = R(a);
	return in;
}

bool R::operator>(R const &other)	const
{
	if (point == other.point)		return num > other.num;
	else if (point > other.point)	return num > (other.num >> (point - other.point)); 
	else										return (num >> (other.point - point)) > other.num;
}
bool R::operator==(R const &other)	const
{
	if (point == other.point)		return num == other.num;
	else if (point > other.point)	return num == (other.num >> (point - other.point)); 
	else										return(num >> (other.point - point)) == other.num;
}

R R::operator+(R const &other)const
{
	R temp;
	if (point >= other.point)
	{
		temp.num = num + (other.num << (point - other.point)); //����С���㡣
		temp.point = point;
	}
	else
	{
		temp.num = other.num + (num << (other.point - point));
		temp.point = other.point;
	}
	return temp;
}
R R::operator-(R const &other)const
{
	R temp;
	if (point >= other.point)
	{
		temp.num = num - (other.num << (point - other.point)); 
		temp.point = point;
	}
	else
	{
		temp.num = (num << (other.point - point)) - other.num;
		temp.point = other.point;
	}
	return temp;
}
R R::operator*(R const &other)const
{
	R temp;
	temp.num = other.num*num;
	temp.point = other.point + point;
	return temp;
}
void R::setprecision(unsigned int Precision)		//����num�ĳ���,
{
	if (point > Precision)
	{
		bool flag = num.num[point-Precision-1]>=5; //�Ƿ��λ��
		num.num >>= point-Precision;
		if (flag) num.num+=1;
		point = Precision;
	}
}
R R::operator/(R const &other)const
{
	R const *pother = &other;
	R tempother, two = 2;
	int COUNT = 0;
	if (other>R(10))		//ͨ������С�������other�Ĵ�С��
	{
		tempother=other;
		COUNT = tempother.num.getdigit();
		tempother.point += COUNT;
		pother = &tempother;
	}
	R temp = 1;	temp.point = 1;		//temp=0.1 ����ʼֵΪ0.1
	Re(i,20)										 //��other�ĵ�����ţ�ٵ�����
	{
		temp *= two - temp*(*pother);
		temp.setprecision(500);
	}
	if(COUNT)		temp.point += COUNT;
	R ans = *this*temp;
	ans.setprecision(250);
	return ans;
}
