#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 从输入栏获取下一个数据，由于输入有可能是数字，也可能是字符串，所以用bool区分 
// 如果返回值是true，则out是数字
// 如果返回值是false，则out要转为字符使用 
bool INBox(int* out); 

// 输入栏是否还有数据 
bool INBoxNotEmpty(); 

// 模拟游戏输出栏OutBox 
void OUTBox(bool b, int n);

///////////////////////////////////////////////////////////////////////////////////////

// 模拟游戏的输入栏 
//char* inbox[] = {"A", "U", "T", "O", "E", "X", "E"};
void Level2()
{
	while(true)
	{
		bool b = false;
		int out = 0;
		
		// b用来区分数字还是字母 
		b = INBox(&out);
		OUTBox(b, out);
	}
}

void Level3()
{
	char floor[] = {'U', 'J', 'X', 'G', 'B', 'E'};	
	OUTBox(false, floor[4]);
	OUTBox(false, floor[0]);
	OUTBox(false, floor[3]);
}

// 模拟游戏的输入栏  
// char* inbox[] = {"8", "6", "-3", "-7", "7", "-6", "6", "6"};
void Level14()
{
	// 求最大值，只用人手和一块地板 
	int hand;
	int a;
	
	while (true)
	{
		INBox(&hand);
		a = hand;
		INBox(&hand);
		hand = hand - a;
		if (hand < 0) { 
			hand = a;
		}
		else {
			hand = hand + a;
		}
		OUTBox(true, hand);
	}
}

// 模拟游戏的输入栏 
// char* inbox[] = {"4", "4", "1", "4", "1"};
void Level29()
{
	// 取地板上某一块作为临时变量 
	int n;
	
	// 地板上的字符
	char floor[] = "NKAERDOLYJ";
	while (true)
	{
		INBox(&n);
		// n 被作为下标使用 
		OUTBox(false, floor[n]);
	}
}

void Level29_pointer()
{
	int n;
	char* floor = "NKAERDOLYJ";
	
	while (true)
	{
		INBox(&n);
		// 从floor开头偏移n的地方 
		char c = *(floor + n);
		OUTBox(false, c);
	}
}

char* inbox[] = {"4", "15", "7", "0", "21", "17", "11", "20", "2", "13", "4", "17", "21"};
void Level30()
{
	char* data[] = {"4", "15", "7", "0", "21", "17", "11", "20", "2", "13", "4", "17", "21"};
	
	
	// 密码破译 
	int n;
	char floor[] = "GET\0TH\0TAR\0AWAKE\0IS\0XXX\0";
	
	while (true)
	{
		INBox(&n);
		while (true)
		{
			OUTBox(false, floor[n]);
			n++;
			if (floor[n] == '\0') { break; }		// 注：C语言中，'\0'等于0 
		}
	}
}

int main(int argc, char *argv[])
{
	// 执行哪一关就调用该关卡的函数，比如Level2()、Level14()，另外要记得修改输入数据inbox[]（去掉函数前面的注释即可） 
	Level30();
	
	system("PAUSE");
	return 0;
}

/////////// 公用函数 //////////////////////// 
int _input_index = 0;

bool INBox(int* out)
{
	if (!INBoxNotEmpty())
	{
		exit(0);
	}
	
	char* s = inbox[_input_index];
	_input_index++;
	
	char c = s[0];
	if ( (c>='A' && c<='Z') || (c>='a' && c<='z') )
	{
		// 是字符，返回false 
		*out = (int)c;
		return false;
	}
	// 分析数字，赋值给out，并返回true 
	sscanf(s, "%d", out);
	return true;
}

bool INBoxNotEmpty()
{
	return _input_index < sizeof(inbox) / sizeof(char*);
}

void OUTBox(bool b, int n)
{
	if (b)
	{
		printf("%d, ", n);
	}
	else
	{
		printf("%c, ", (char)n);
	}
}
 

