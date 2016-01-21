/*
 *
 *　　　　　　　　┏┓　  ┏┓+ +
 *　　　　　　　┏┛┻━━━┛┻┓ + +
 *　　　　　　　┃　　　　　　  ┃ 　
 *　　　　　　　┃　　　━　　　┃ ++ + + +
 *　　　　			 |   ███━███    ┃+
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
#include <iostream>
#include <sstream>	//用于将输出转化为字符串
#include <iomanip> //用于格式化输入输出。float转化成字符串
#include <string>
#include <omp.h>
#define Re(i,n)	for(int i=1;i<=n;++i)
const int ten[5] = { 0,1, 10, 100, 1000 };		//用来进位的

class N; class Z; class Q; class R;
typedef Z Int;
typedef R Float;
//以下为一大堆模板。因为+=，-=，*=，/=... ...都依赖于那一类的+-*/的重载。
//平时x=的操作效率应该要高一点... ...因为但是这里没有对this进行精细的操作，所以会重新创建对象，效率会略低。
template <typename T>		T &operator+=(T &This, T const &num)		{ This = This + num; return This;	}		 
template <typename T>		T &operator-=(T &This, T const &num)			{ This = This - num;	return This;	}		
template <typename T>		T &operator*=(T &This, T const &num)			{ This = This * num;	return This;	}		
template <typename T>		T &operator/=(T &This, T const &num)			{ This = This / num;	return This;	}		
template <typename T>		T &operator%=(T &This, T const &num)		{ This = This % num; return This;	}		
template <typename T>		T &operator++(T &This, int)			{ This = This + 1;	return This; }
template <typename T>		T operator++(T &This)					{ T temp(This);	This = This + 1;	return This; }
template <typename T>		T &operator--(T &This, int)			{ This = This - 1;	return This; }
template <typename T>		T operator--(T &This)					{ T temp(This);	This = This - 1;	return This; }
//依赖于重载的>和==
template <typename T>		bool operator>=(T const &a, T const &b)			{ return a > b||a == b; }
template <typename T>		bool operator!=(T const &a, T const &b)				{ return !(a == b); }
template <typename T>		bool operator<(T const &a, T const &b)				{ return !(a > b||a==b); }
template <typename T>		bool operator<=(T const &a, T const &b)			{ return !(a > b); }
template <typename T>		
T gcd(T const &m, T const &n)//依赖于%
{
	if (n == T(0)) return m;
	else return gcd(n, m%n);
}
template<typename T>
std::istream &operator>>(std::istream &in, T &This) //这个的效率的确有点低。管他呢。
{
	std::string a;
	(in.operator>>)(a);
	This = T(a);
	return in;
}

class N  //自然数不能为负。
{
protected:
	int  *num;
	int length;	//代表长度. 从num[1]-num[length]		
private:
	int CheckLen(int max);	//检测长度
	N &half();
	int &operator[](int const &x)const				{ return num[x]; }
	int *intspace(int const &n)const; //用来申请已经清零的空间
public:
	N() :length(1), num(intspace(5)){}
	N(std::string str);
	N(int n);
	N(N const &other);
	~N()		{ /*std::cout << *this << std::endl; */delete[] num; }
	friend std::ostream &operator<<(std::ostream &out, N const &other);
	N &operator=(N const &other);
	bool operator>(N const &other)const;
	bool operator==(N const &other)const; 
	N operator +(N  const &other)const;
	N operator-(N const &other)const;
	N operator *(N const &other)const;
	N operator/(N const &other)const;
	N operator%(N const &other)const;
	N &operator+=(N const &other);
	N &operator-=(N const &other);
	N &operator*=(N const &other);

};	
N::N(std::string str) 
{
	length = str.length();
	num = intspace(length / 4 + 5);							
	Re(i, length)																				            
		num[(i-1)/4+1] += ten[(i-1)%4+1]*(str[length-i] - '0');		
	CheckLen(length / 4 + 1);
}
N::N(int n)
{		
	num = intspace(5);
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
	num = intspace(other.length + 2);
	length = other.length;
	memcpy(num, other.num, sizeof(int)*(other.length+2));
}
N &N::operator=(N const &other)
{
	if (this != &other)
	{
		if (length < other.length) //如果不用重新申请我就不管你了。
		{
			delete[] num;
			num = intspace(other.length + 5);
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
			if (This[This.length - i + 1] < 10)				out << "000";
			else if (This[This.length - i + 1] < 100)			out << "00";
			else if (This[This.length - i + 1] < 1000)		out << 0;
		}
		out << This[This.length + 1 - i];		//length,length-2,... ...1
	}
	return out;
}
//std::istream &operator>>(std::istream &in, N &This)
//{
//	std::string a;
//	in >> a;
//	This = N(a);
//	return in;
//}

bool N::operator>(N const &other)const
{
	if (length != other.length)return (length > other.length);
	Re(i, length)
		if (num[length-i+1] != other.num[length-i+1])
			return num[length-i+1]>other.num[length-i+1];
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

int N::CheckLen(int max)
{
	length = 1; //防止长度为零。
	Re(i, max)
		if (num[max - i + 1] > 0)
		{
			length = max - i + 1;
			break;
		}
	return length;
}
int *N::intspace(int const &n)const //用来申请已经清零的空间
{
	//std::cout << "Applying memory:" << n << std::endl;
	int *p = new int[n];
	if(p==NULL)exit(1);			//申请内存出错报一下。
	memset(p, 0, sizeof(int)*n);
	return p;
}
N N::operator+(N const &other)const
{
	int max = length > other.length ? length : other.length;
	N temp;
	delete[] temp.num;						//不是在构造函数中调用intspace一定要释放。
	temp.num = intspace(max + 5); //这里有个泄漏。
	Re(i, max) 
	{
		if (i <= length)				temp.num[i] += num[i];					//0...length
		if (i <= other.length)		temp.num[i] += other.num[i];			//
		if (temp.num[i] >= 10000)
		{
			++temp.num[i + 1];
			temp.num[i] %= 10000;			//0... ...MAX
		}
	}
	temp.length = temp.num[max + 1] > 0 ? max + 1 : max;
	return temp;
}
N N::operator-(N const &other)const
{
	if (*this < other) std::cout << "N's ERROR" << std::endl;
	else if (*this == other) return N();
	else
	{
		N temp(*this);
		Re(i, length) 		//这里同样可以先减后进位的，并行操作。
		{
			if(i<=other.length)
				temp.num[i] -= other.num[i];
			if (temp.num[i]<0)
			{
				--temp.num[i + 1];
				temp.num[i] += 10000;
			}
		}
		temp.CheckLen(length);
		return temp;
	}
	return N();
}
N N::operator*(N const &other)const
{
	int max = length + other.length + 1;
	N temp;
	delete[] temp.num;                  //释放内存
	temp.num = intspace(max + 5);//这里和等于号不一样了。
	Re(i, length)		
		Re(j, other.length) //这里也可以拆分为两个循环并行操作,可惜效率太低。
		{
			temp.num[i + j - 1] += num[i] * other.num[j];
			if (temp.num[i + j - 1] >= 10000)					//必须及时进位防止溢出。
			{
				temp.num[i + j] += temp.num[i + j - 1] / 10000;
				temp.num[i + j - 1] %= 10000;					//0... ...MAX
			}
		}
	temp.CheckLen(max);
	return temp;
}
N &N::half() //将自己二分，为除法服务。
{
//#pragma omp parallel for
	if (*this == 1);
	else 
		Re(i, length) //这个循环可以拆为两个
		{
			if (i != length&&num[length - i + 1] % 2)
				num[length - i] += 10000;
			num[length - i + 1] /=2;
		}
	CheckLen(length);
	return *this;
}
N N::operator/(N const &other)const
{
	N ans,sum,Half(*this),r;
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
	N temp,sum;
	N Half(*this);
	N r;
	while (*this >= sum + other) //sum=other*temp;
	{
		r = Half*other;
		if (sum + r <= *this) sum += r, temp += Half; //sum=other*(temp+half);
		Half .half();
	}
	return *this - sum;
}
N &N::operator+=(N const &other)	//虽然模板可以解决，但还是想通过更细致的操作来优化效率。平时需要申请5次内存，现在一次就差不多了
{
	int *tempnum=num;
	if (length <= other.length)				//如果空间不够，就重新申请吧。空间够就免了。
	{
		num = intspace(other.length + 5);
		memcpy(num, tempnum, sizeof(int)*(length + 2));
		delete[] tempnum; //有intspace的地方就有delete。
	}
	Re(i,other.length)	num[i] += other.num[i];
	int max = length > other.length ? length : other.length;
	Re(i,max)
		if (num[i] > 10000)
		{
			++num[i + 1];
			num[i] %= 10000;
		}
	CheckLen(max+1);
	return *this;
}
N &N::operator-=(N const &other)
{
	if (*this < other) std::cout << "N's ERROR" << std::endl; //自然数的减法，不能出现负数。
	else if (*this == other) *this = N(0);
	else
	{
		Re(i, length) 	
		{
			if (i <= other.length)
				num[i] -= other.num[i];
			if (num[i] < 0)
			{
				--num[i + 1];
				num[i] += 10000;
			}
		}
		CheckLen(length);
	}
	return *this;
}
N &N::operator*=(N const &other)
{
	N temp(*this);
	int max = length + other.length + 1;
	delete[] num;
	num = intspace(max + 5); //这里基本上还是要重新申请的，就不进行判断了。
	Re(i, length)
		Re(j, other.length) 
	{
		num[i + j - 1] +=temp.num[i]* other.num[j];
		if (num[i + j - 1] >= 10000)				
		{
			num[i + j] += num[i + j - 1] / 10000;
			num[i + j - 1] %= 10000;				
		}
	}
	CheckLen(max);
	return *this;
}
/************************************************************************/
/*                             华丽的分割线                              */
/************************************************************************/
class Z 
{
	N num;
	bool sign;
public:
	Z() :num(), sign(0)	{}
	Z(std::string str);
	Z(int other):	sign(other < 0),num(other*(other < 0 ? -1 : 1))	{}
	Z(Z const &other) :num(other.num), sign(other.sign)	{}
	Z(N const &other) : num(other), sign(0){}
	friend std::ostream &operator<<(std::ostream &out, Z const &other);
	Z &operator=(Z const &other)					{ if(this!=&other)	num = other.num, sign = other.sign; return *this; }
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
//std::istream &operator>>(std::istream &in, Z &This)
//{
//	std::string a;
//	in >> a;
//	This = Z(a);
//	return in;
//}

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
Z Z::operator-(Z const &other)const //(a - b) = a + (-b) 我知道这样的效率会比较低。
{
	Z temp(other);
	temp.sign = !other.sign;
	return temp + *this;
}
Z Z::operator*(Z const &other)const
{
	Z temp;
	temp.num = num*other.num;
	temp.sign = !(sign == other.sign); //正负为负。
	return temp;
}
Z Z::operator/(Z const &other)const
{
	if (other==Z())
	{
		std::cout << "除数不能为零" << std::endl;
		return Z();
	}
	Z temp;
	temp.num = num/other.num;
	if(temp.num!=N())		temp.sign = !(sign == other.sign); 
	else temp.sign = 0;
	return temp;
}
Z Z::operator%(Z const &other)const
{
	if (other == Z())
	{
		std::cout << "分母不能为零" << std::endl;
		return Z();
	}
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
			num -=other.num;
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
	sign = !(sign == other.sign);
	return *this;
}

/************************************************************************/
/*                             华丽的分割线                              */
/************************************************************************/
class Q
{
	Z up, down;
public:
	Q() :up(1), down()	{}
	Q(Z up, Z down);
	Q(N up, N down);
	Q(int up, int down);
	Q(int const &other);
	Q(Q const &other)									{ up = other.up; down = other.down; }
	Q operator=(Q const &other)					{ if (this != &other)up = other.up, down = other.down; return *this; }
	friend std::ostream &operator<<(std::ostream &out, Q const &other);
	bool operator>(Q const &other)	const	{	return up*other.down - down*other.up > 0; }
	bool operator==(Q const &other)	const	{	return up == up&&down == down; }
	Q operator +(Q const &other)		const	{	return Q(up*other.down + other.down, down*other.down);}
	Q operator - (Q const &other)		const	{	return Q(up*other.down - other.down*down, down*other.down); }
	Q operator * (Q const &other)		const	{	return Q(up*other.up, down*other.down); }
	Q operator / (Q const &other)		const	{	return Q(up*other.down, down*other.up); }
};
Q::Q(Z one, Z two=1)
{
	if (two == Z(0))
	{
		std::cout << "坟墓不能为零" << std::endl;
		up = Z(0), down = Z(1);
	}
	else 
	{
		Z GCD = gcd(one, two);
		if(GCD!=Z(1))
		{
			up = one / GCD;
			down = two / GCD; //TODO 个人觉得这里的效率应该更高一点
		}
		else up = one, down = two;
		if (down<Z(0))					//保持分母为正。分子决定符号。
			up *= Z(-1), down *= Z(-1); //只是不想直接调用sign而已。
	}
}
Q::Q(N one, N two=1)
{
	if (two == N())
	{
		std::cout << "除数不能为零" << std::endl;
		up = Z(0), down = Z(1);
	}
	else 
	{
		N GCD = gcd(one, two);
		up = one / GCD;
		down = two / GCD;
	}
}
Q::Q(int const &other) :up(Z(other)), down(1){}
Q::Q(int one=0, int two=1)
{
	if (two == 0)
	{
		std::cout << "除数不能为零" << std::endl;
		up = Z(0), down = Z(1);
		return;
	}
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
class R
{
	Z num;
	unsigned point;
public:
	R() :num(),point(0){}
	R(std::string str);
	R(double const &other);
	R(R const &other) :num(other.num), point(other.point)	{}
	R(Z const &other) :num(other), point(0){}
	friend std::ostream &operator<<(std::ostream &out, R const &other);
	R &operator=(R const &other);
	R &operator=(N const &other)				{ num = other, point = 0; }
	bool operator>(R const &other)	const	{ return (*this - other).num>Z(0); }			//貌似在小数点浮动的情况下只能这么比了。
	bool operator==(R const &other)	const	{ return (*this - other).num == Z(0);		/*num == other.num&&point == other.point; */ }//目前0.100000！=0.1
	R operator +(R  const &other)		const; 	//补齐小数点再运算
	R operator - (R const &other)		const;	//补齐小数点再运算
	R operator *(R const &other)			const;	//小数点单独运算。
	//R operator/(R const &other)			const;
};
R::R(std::string str)
{
	point = 0;
	int length = str.length();
	Re(i, length)
		if (str[i - 1] == '.')
			{
				point = length - i;
				break;
			}
	if (point > 0)
	{
		if (point != length - 1)
			num = Z(str.substr(0, length - point - 1) + str.substr(length - point, point));
		else
			num = Z(str.substr(1, length - 1));
	}
	else num = Z(str);
}
R &R::operator=(R const &other)
{
	if (this != &other)	num = other.num,	point = other.point;
	return *this; 
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
	std::ostringstream ou;
	ou << This.num; //调用之前对<<的重载。
	std::string temp=ou.str();
	if (temp.length() < This.point)	//小于1的小数往前面补上0。
		temp.insert(0,This.point-temp.length()+1,'0');
	if(This.point!=0)						//往中间插入小数点。
		temp.insert(temp.length() - This.point, ".");
	out << temp;
	return out;
}
//std::istream &operator>>(std::istream &in, R &This)
//{
//	std::string a;
//	in >> a;
//	This = R(a);
//	return in;
//}

R R::operator+(R const &other)const
{
	R temp;
	if (point == other.point)
	{
		temp.num = num + other.num;
		temp.point = point;
	}
	else if (point > other.point)//*10^n次方来对齐小数点。
	{
		temp.num = num+other.num*Z('1' + std::string().append(point - other.point, '0')); 
		temp.point = point;
	}
	else
	{
		temp.num = other.num+num*Z('1' + std::string().append(other.point-point, '0'));
		temp.point = other.point;
	}
	return temp;
}
R R::operator-(R const &other)const
{
	R temp;
	if (point == other.point)
	{
		temp.num = num - other.num;
		temp.point = point;
	}
	else if (point > other.point)
	{
		temp.num = num - other.num*Z('1' + std::string().append(point - other.point, '0'));
		temp.point = point;
	}
	else 
	{
		temp.num = other.num - num*Z('1' + std::string().append(other.point - point, '0'));
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