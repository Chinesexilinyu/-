#include<iostream>
#include<stdlib.h>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	if (b == 1)
		return b;
	int x, y,r;
	x = a;
	y = b;
	r = x % y;
	x = y;
	y = r;
	return gcd(x, y);
}
int exgcd(int a, int b)
{
	int x1 = 1, x2 = 0, x3 = a, y1 = 0, y2 = 1, y3 = b, q, t1, t2, t3;
	while (y3 != 1)
	{
		q = x3 / y3;
		t1 = x1 - q * y1;
		t2 = x2 - q * y2;
		t3 = x3 - q * y3;
		x1 = y1;
		x2 = y2;
		x3 = y3;
		y1 = t1;
		y2 = t2;
		y3 = t3;
	}
	return y2;
}
int main()
{
	char ch,ch1;
	do
	{
		int a, b, g;
		cout << "�������������Ĳ�����A�������������,B��������Ԫ��";
		cin >> ch1;
		if (ch1 == 'A')
		{
			cout << "������������Ҫ�������������������������";
			cin >> a;
			cin >> b;
			if (a > b)
				g = gcd(a, b);
			else
				g = gcd(b, a);
			cout << "\n��������ǣ�" << g << endl;
		}
		else
		{
			cout << "������������Ҫ������Ԫ��������������";
			cin >> a;
			cin >> b;
			if (a > b)
				g = gcd(a, b);
			else
				g = gcd(b, a);
			if (g != 1)
				cout << "��Ǹ�����������������ݣ��������޷������Ԫ��" << endl;
			else
			{
				int f = g;
				if (a > b)
					g = exgcd(a, b);
				else
					g = exgcd(b, a);
				cout << "\n���������Ԫ�ǣ�" << g << endl;
				cout << "�������Ƿ���ͬʱ��֪����������ǵĻ�������1������������0";
				cin >> g;
				if(g==1)
					cout << "\n��������ǣ�" << f<< endl;
			}
		}
		cout << "��������<y/n>���Խ��л��ս᣺";
		cin >> ch;
	} while (ch == 'y');
	return 0;
}