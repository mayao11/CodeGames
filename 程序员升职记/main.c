#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����������ȡ��һ�����ݣ����������п��������֣�Ҳ�������ַ�����������bool���� 
// �������ֵ��true����out������
// �������ֵ��false����outҪתΪ�ַ�ʹ�� 
bool INBox(int* out); 

// �������Ƿ������� 
bool INBoxNotEmpty(); 

// ģ����Ϸ�����OutBox 
void OUTBox(bool b, int n);

///////////////////////////////////////////////////////////////////////////////////////

// ģ����Ϸ�������� 
//char* inbox[] = {"A", "U", "T", "O", "E", "X", "E"};
void Level2()
{
	while(true)
	{
		bool b = false;
		int out = 0;
		
		// b�����������ֻ�����ĸ 
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

// ģ����Ϸ��������  
// char* inbox[] = {"8", "6", "-3", "-7", "7", "-6", "6", "6"};
void Level14()
{
	// �����ֵ��ֻ�����ֺ�һ��ذ� 
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

// ģ����Ϸ�������� 
// char* inbox[] = {"4", "4", "1", "4", "1"};
void Level29()
{
	// ȡ�ذ���ĳһ����Ϊ��ʱ���� 
	int n;
	
	// �ذ��ϵ��ַ�
	char floor[] = "NKAERDOLYJ";
	while (true)
	{
		INBox(&n);
		// n ����Ϊ�±�ʹ�� 
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
		// ��floor��ͷƫ��n�ĵط� 
		char c = *(floor + n);
		OUTBox(false, c);
	}
}

char* inbox[] = {"4", "15", "7", "0", "21", "17", "11", "20", "2", "13", "4", "17", "21"};
void Level30()
{
	char* data[] = {"4", "15", "7", "0", "21", "17", "11", "20", "2", "13", "4", "17", "21"};
	
	
	// �������� 
	int n;
	char floor[] = "GET\0TH\0TAR\0AWAKE\0IS\0XXX\0";
	
	while (true)
	{
		INBox(&n);
		while (true)
		{
			OUTBox(false, floor[n]);
			n++;
			if (floor[n] == '\0') { break; }		// ע��C�����У�'\0'����0 
		}
	}
}

int main(int argc, char *argv[])
{
	// ִ����һ�ؾ͵��øùؿ��ĺ���������Level2()��Level14()������Ҫ�ǵ��޸���������inbox[]��ȥ������ǰ���ע�ͼ��ɣ� 
	Level30();
	
	system("PAUSE");
	return 0;
}

/////////// ���ú��� //////////////////////// 
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
		// ���ַ�������false 
		*out = (int)c;
		return false;
	}
	// �������֣���ֵ��out��������true 
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
 

