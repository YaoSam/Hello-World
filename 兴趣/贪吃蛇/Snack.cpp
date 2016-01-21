#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define Re(i,n)		for(int i=1;i<=n;i++) //循环n次
#define re(i,n)		for(int i=0;i<n;i++)
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}
int const Width = 32;	//地图的尺寸
int const Height = 24;
int interval = 200;		//时间间隔
char map[Height][Width];
void play();				//函数前置声明

struct Location			//坐标
{
	int x, y;
	Location(int a = 0, int b = 0) :x(a), y(b){}
	bool operator==(const Location& other){ return x == other.x&&y == other.y; }
};

Location money;
class snack
{
public:		//目前先Public先
	Location body[Width*Height];
	int length;
	char direction;	//当前行走方向
public:
	snack() :length(7),direction('r')
	{
		re(i, length)body[i] = Location(1, 10-i);
	}
	void move(char movement=0)	//转弯方向
	{
		Location &head = body[0];
		Location temphead = head;
		if (movement == direction||movement==0)
		{
			switch (direction)
			{
				case'l':				head.y--;			break;
				case'r':				head.y++;			break;
				case'u':				head.x--;			break;
				case'd':				head.x++;			break;
			}
			if (movement != 0)interval = 10; //加速
		}
		else 
		{
			if (direction=='u'||direction=='d')
			{
				switch (movement)
				{
					case'l':		head.y--;		break;
					case'r':		head.y++;		break;
				}
				if (movement)direction = movement;
			}
			else 
				if (direction == 'l'||direction=='r')
			{
				switch (movement)
				{
					case'u':			head.x--;			break;
					case'd':			head.x++;			break;
				}
				if (movement)direction = movement;
			}
		}
		head.x %= Height;
		head.y %= Width;

	if (money == head)
		{ 
			body[length] = body[length - 1];										//在结尾增加一个节点。
			memmove(&body[1], body, sizeof(Location)*(length - 1));	//照常复制
			length++;			
			money.x = int(rand()) % (Height - 2) + 1;
			money.y = int(rand()) % (Width - 2) + 1;
		}
		else if (/*map[head.x][head.y] == '#' || */map[head.x][head.y] == '*')
		{
			cout << "you dead" << endl;
			system("pause");
			play();
		}
		else
			memmove(&body[1], body, sizeof(Location)*(length - 1));
		body[1] = temphead;
	}
};
snack one;
void Print()
{
	//清空屏幕
	system("cls");
	//清空map
	re(i, Height)		//画上围栏
	{
		memset(map[i], 0, sizeof(map[i]));
		map[i][0] = map[i][Width-1] = '#';
	}
	re(i, Width)
		map[0][i] = '#';
	memmove(map[Height-1], map[0], sizeof(map[0]));
	//钱
	map[money.x][money.y] = '$';
	//头
	Location &head = one.body[0];
	map[head.x][head.y] = '@';
	//身体
	Re(i, one.length - 1)
		map[one.body[i].x][one.body[i].y] = '*';
	//输出
	re(i,Height)
	{
		re(j, Width)
		{
			if (map[i][j] == 0)cout << ' ';
			else cout << map[i][j];
		}
		cout << endl;
	}
	cout << "direction: " << one.direction << endl;
	cout << "等级为：" << one.length - 7 << endl;
}

void play()
{
	one = snack();
	money.x = int(rand()) % (Height - 2) + 1;
	money.y = int(rand()) % (Width - 2) + 1;
	Print();
	char a, b;
	while (1)
	{
		if (_kbhit())
		{
			a = _getch();
			if (a == -32)
			{
				b = _getch();
				switch (b)
				{
					case 72:		one.move('u');			break;
					case 75:		one.move('l');			break;
					case 77:		one.move('r');			break;
					case 80:		one.move('d');			break;
				}
			}
			else if (a == 27)exit(1);
		}
		else one.move(0);

		Sleep(interval);
		Print();
		interval = 1000;
	}
}

int main()
{
	srand(time(NULL));
	play();
	return 0;
}