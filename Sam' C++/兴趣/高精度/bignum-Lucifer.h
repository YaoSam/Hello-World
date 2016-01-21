/*
*
*　　　　　　　　┏┓　  ┏┓+ +
*　　　　　　　┏┛┻━━━┛┻┓ + +
*　　　　　　　┃　　　　　　  ┃ 　
*　　　　　　　┃　　　━　　　┃ ++ + + +
*　　　　	   |   ███━███   ┃+
*　　　　　　　┃　　　　　　  ┃ +
*　　　　　　　┃　　　┻　　　┃
*　　　　　　　┃　　　　　　  ┃ + +
*　　　　　　　┗━┓　　　┏━┛
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
#include <iostream>
#include <sstream>	//用于将输出转化为字符串
#include <iomanip> //用于格式化输入输出。float转化成字符串
#include <omp.h>
#include <string>
#define Re(i,n)	for(int i=1;i<=n;++i)
const int ten[5] = { 0, 1, 10, 100, 1000 };		//用来进位的
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


//以下为一大堆模板。因为+=，-=，*=，/=... ...都依赖于那一类的+-*/的重载。
//平时x=的操作效率应该要高一点... ...因为但是这里没有对this进行精细的操作，所以会重新创建对象，效率会略低。
template <typename T>		T &operator+=(T &This, T const &num)				{ This = This + num; return This; }
template <typename T>		T &operator-=(T &This, T const &num)				{ This = This - num;	return This; }
template <typename T>		T &operator*=(T &This, T const &num)				{ This = This * num;	return This; }
template <typename T>		T &operator/=(T &This, T const &num)				{ This = This / num;	return This; }
template <typename T>		T &operator%=(T &This, T const &num)				{ This = This % num; return This; }
template <typename T>		T &operator++(T &This, int)								{ This = This + 1;	return This; }
template <typename T>		T operator++(T &This)										{ T temp(This);	This = This + 1;	return This; }
template <typename T>		T &operator--(T &This, int)								{ This = This - 1;	return This; }
template <typename T>		T operator--(T &This)										{ T temp(This);	This = This - 1;	return This; }
//依赖于>>=
template <typename T>		T operator>>(T const &This, int movement)		{ T temp(This); temp >>= movement; return temp; }
template <typename T>		T operator<<(T const &This, int movement)		{ T temp(This); temp >>= -movement; return temp; }
template <typename T>		T &operator<<=(T &This, int movement)			{ This >>= -movement;						return This; }
//依赖于重载的>和==
template <typename T>		bool operator>=(T const &a, T const &b)			{ return a > b || a == b; }
template <typename T>		bool operator!=(T const &a, T const &b)			{ return !(a == b); }
template <typename T>		bool operator<(T const &a, T const &b)				{ return !(a > b || a == b); }
template <typename T>		bool operator<=(T const &a, T const &b)			{ return !(a > b); }
template <typename T>
T gcd(T const &m, T const &n)//依赖于%
{
	if (n == T(0)) return m;
	else return gcd(n, m%n);
}
template <typename T>		
/*依赖于= . 最高效率的还是直接更改地址的指向。*/
void Swap(T &a, T &b)	{ T temp = a;	a = b;	b = temp; }
template <typename T>
//利用重载的<<，流输出将数字重新转化为字符串
std::string &TurnToStr(T const &This, std::string &str)
{
	std::ostringstream ou;
	ou << This;						//调用之前对<<的重载。
	str = ou.str();
	return str;
}
class N  //自然数，大于零。
{
	int  *num;
	int length;	//代表长度. 四位进一。从num[1]-num[length]		
	//检测并更新length
	int CheckLen(int max);	
	/*自身除2。还可以用来优化100一下的除法。*/
	N &half();
	/*用来申请已经清零的空间为除法服务*/
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
	/*向左位移M位 面向运气式编程*/
	N &operator>>=(int movement);
	/*读取某一位的数字，只返回值不返回引用*/
	int operator[](int const &x)const	{ return (num[(x-1) / 4+1] / ten[(x+3) % 4 + 1]) % 10; }
	/*读取整个数字的位数*/
	int getdigit()const;	
	friend void Swap(N &a, N &b);		
};
N::N(std::string str)
{
	length = str.length();
	num = Space(length / 4 + 5);
	Re(i, length)
		if (str[length - i] != '0') //如果是0就不用大费周折了。
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
		if (length < other.length+2) //如果不用重新申请我就不管你了。
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
	Re(i, length) //或许可用多线程优化。
		if (num[i] != other.num[i])
			return 0;
	return 1;
}

int N::CheckLen( int max)
{
	length = 1; //防止长度为零。
	Re(i, max)
		if (num[max - i + 1] > 0) //所有空间都已经清零。
		{
			length = max - i + 1;
			break;
		}
	return length;
}

int *N::Space( int const &n)const	
{
	if (n <= 0)			debug("WTF!!!You apply Negitive memory?!");//申请长度为负数。报错一下
	int *p = new int[n];
	if (p == NULL)	debug("Sorry. I fail to apply memory... ...");	//申请内存出错报一下。
	memset(p, 0, sizeof(int)*n);		//清零。CheckLen的时候方便。
	return p;
}
N &N::operator+=(N const &other)	//通过更细致的操作来优化效率。
{
	if (length <= other.length)				//如果空间不够，就重新申请吧。空间够就免了。
	{
		int *tempnum = num;
		num = Space(other.length + 5);
		memcpy(num, tempnum, sizeof(int)*(length + 2));
		delete[] tempnum; //有intspace的地方就有delete。
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
	if (length >= other.length)	{ N temp(*this); temp += other; return temp; }//通过比较大小来减少内存的操作。
	else									{ N temp(other); temp += *this; return temp; }
}
N &N::operator-=(N const &other)
{
	if (*this < other)		debug("Well, I'm a N number. I can't be negetive. I just can't."); //自然数的减法，不能出现负数。
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
	N ans;										//用来存储答案。
	delete[] ans.num;						//释放内存
	ans.num = Space(max + 5);		//这里和等于号不一样了。
	Re(i, length)
		if (num[i] != 0)						//稍微提高一点效率。
		{
#pragma omp parallel for
			Re(j, other.length)				//这里也可以拆分为两个循环并行操作,可惜效率太低。
				ans.num[i + j - 1] += num[i] * other.num[j];
			Re(j, other.length)
				if (ans.num[i + j - 1] >= 10000)					//必须及时进位防止溢出。
				{
					ans.num[i + j] += ans.num[i + j - 1] / 10000;
					ans.num[i + j - 1] %= 10000;					//0... ...MAX
				}
		}
	ans.CheckLen(max);
	return ans; //返回时要申请一次空间。
}
//*=还是要申请两次空间。效率其实和直接*差不多。
N &N::operator*=(N const &other) 
{
	N temp(*this);
	int max = length + other.length + 1;
	delete[] num;
	num = Space(max + 5); //这里基本上还是要重新申请的，就不进行判断了。
	Re(i, length) //相当于length个+。
		if (temp.num[i] != 0)
			Re(j, other.length)
				if (other.num[j] != 0)
				{
					num[i + j - 1] += temp.num[i] * other.num[j];
					if (num[i + j - 1] >= 10000)
					{
						num[i + j] += num[i + j - 1] / 10000; //跟+唯一的区别。其实加法也是可以这么打的。
						num[i + j - 1] %= 10000;
					}
				}

	CheckLen(max);
	return *this; 
}

N &N::half() //为除法服务。
{
	if (*this == 1)	return *this;
	else
		Re(i, length) 
	{
		if (i != length&&num[length - i + 1] % 2) //余1进位。
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
N N::operator%(N const &other)const //求模,只是简单的修改了一下/的返回值。
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
/*交换两个数字直接修改地址。有friend 就是如此的强大。*/
void Swap(N &a, N &b)  
{
	Swap(a.num, b.num);
	Swap(a.length, b.length);
}

N &N::operator>>=(int movement) 
{
	if (movement == 0)	return *this;
	int big = movement / 4, small = movement % 4;
	int newlength=length-big;								//big<0则右移。所以增加。
	if (newlength <= 0) {*this = N(0); return *this; } //这里有个小bug
	int *newnum=Space(newlength+5);				//后面记得释放
	if (movement>0)											//左移。减少。
	{
		if (small == 0)
			Re(i, newlength) //4的倍数直接复制。
				newnum[i] = num[i + big];
		else
			Re(i, newlength)
		{
			newnum[i] += num[i + big] / ten[small + 1];					//面向运气式编程
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
				newnum[i + big] += (num[i] % ten[5-small])*ten[small+1];//只是跟上面表达式的下标反了。
				newnum[i + big + 1] += (num[i] / ten[5-small]);
			}
	}
	delete[] num;
	num = newnum;
	CheckLen(newlength+1);
	return *this;
}

/************************************************************************/
/*                             华丽的分割线                              */
/************************************************************************/
class Z //整数。由sign决定正负
{
	N num;
	bool sign; //符号。
public:
	Z() :num(), sign(0)	{}
	Z(std::string str);
	Z(int other) : sign(other < 0), num(other*(other < 0 ? -1 : 1))	{}
	Z(Z const &other) :num(other.num), sign(other.sign)	{}
	Z(N const &other) : num(other), sign(0){}
	friend std::ostream &operator<<(std::ostream &out, Z const &other);
	Z &operator=(N const &other)					{ num = other; sign = 0; return *this; }
	bool operator>(Z const &other)const			{ return sign != other.sign ? other.sign : ((!sign) == num > other.num); }
	bool operator==(Z const &other)const		{ return sign == other.sign&&num == other.num; } //优先比较sign
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
Z Z::operator-(Z const &other)const //(a - b) = a + (-b) 我知道这样的效率会比较低。 TODO
{
	Z temp(other);
	temp.sign = !other.sign;
	return temp + *this;
}
Z Z::operator*(Z const &other)const
{
	Z temp;
	temp.num = num*other.num;
	temp.sign = (sign != other.sign);		//不同号即为-。
	return temp;
}
Z Z::operator/(Z const &other)const
{
	if (other == Z())
	{
		std::cout << "除数不能为零" << std::endl;
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
	if (other == Z())	debug( "分母不能为零" );
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
			num = other.num - num; //这里就没办法了。
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
/*                             华丽的分割线                              */
/************************************************************************/
class Q //有理数。这个类效率有点低。因为要找GCD.
{
	Z up, down;//分子分母
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
		debug("分母不能为零");
	else
	{
		Z GCD = gcd(one, two);
		if (GCD != Z(1))
		{
			up = one / GCD;
			down = two / GCD; //TODO 个人觉得这里的效率应该更高一点
		}
		else up = one, down = two;
		if (down<Z(0))					//保持分母为正。分子决定符号。
			up *= Z(-1), down *= Z(-1); //只是不想直接调用sign而已。
	}
}
Q::Q(N one, N two = 1)
{
	if (two == N())
		debug("除数不能为零");
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
		debug("除数不能为零");
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
/*                             华丽的分割线						                           */
/************************************************************************/
class R //浮点数
{
	Z num;
	unsigned point; //小数点离num最后一位的距离。
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
	//补齐小数点再运算
	R operator +(R  const &other)		const; 
	R operator - (R const &other)		const;	
	//小数点单独运算。
	R operator *(R const &other)			const;	
	//牛顿迭代法
	R operator/(R const &other)			const;	
	R &operator*=(R const &other)		{ num *= other.num;		point += other.point; return *this; }
	R &operator>>=(int movement)	{ num >>= movement; point -= movement; return *this; }
};
R::R(std::string str)
{
	int length = str.length();
	//point = length-str.find(".")+1;
	point = 0;
	Re(i, length) //找point。
		if (str[i - 1] == '.')
		{
			point = length - i;
			break;
		}
	if (point!=0)
	{
		if (point != length - 1)
			num = Z(str.substr(0, length - point - 1) + str.substr(length - point, point)); //将小数点剔除。
		else
			num = Z(str.substr(1, length - 1));
	}
	else num = Z(str), point = 0;
}
R::R(double const &other) //支持的精度为十五位。并且float型精度会有损失。
{
	std::ostringstream out;
	out << std::setprecision(15) << other;
	std::string str(out.str());
	*this = R(str);
}

std::ostream &operator<<(std::ostream &out, R const &This)
{
	std::string temp; 
	TurnToStr(This.num,temp);		//其实这个的效率比较低。但如果输出不是很大的话。不管了。
	if (temp.length() <= This.point)	//小于1的小数往前面补上0。
		temp.insert(0, This.point - temp.length() + 1, '0');
	if (This.point != 0)						//往中间插入小数点。
		temp.insert(temp.length() - This.point, "."); //因为长度已经改变。所以要用temp.length.
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
		temp.num = num + (other.num << (point - other.point)); //对齐小数点。
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
void R::setprecision(unsigned int Precision)		//调节num的长度,
{
	if (point > Precision)
	{
		bool flag = num.num[point-Precision-1]>=5; //是否进位。
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
	if (other>R(10))		//通过调节小数点调整other的大小。
	{
		tempother=other;
		COUNT = tempother.num.getdigit();
		tempother.point += COUNT;
		pother = &tempother;
	}
	R temp = 1;	temp.point = 1;		//temp=0.1 。初始值为0.1
	Re(i,20)										 //求other的倒数。牛顿迭代法
	{
		temp *= two - temp*(*pother);
		temp.setprecision(500);
	}
	if(COUNT)		temp.point += COUNT;
	R ans = *this*temp;
	ans.setprecision(250);
	return ans;
}
