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
		cout << "请输入您想做的操作：A代表求最大公因数,B代表求逆元：";
		cin >> ch1;
		if (ch1 == 'A')
		{
			cout << "请您输入您想要计算最大公因数的两个正整数：";
			cin >> a;
			cin >> b;
			if (a > b)
				g = gcd(a, b);
			else
				g = gcd(b, a);
			cout << "\n最大公因数是：" << g << endl;
		}
		else
		{
			cout << "请您输入您想要计算逆元的两个正整数：";
			cin >> a;
			cin >> b;
			if (a > b)
				g = gcd(a, b);
			else
				g = gcd(b, a);
			if (g != 1)
				cout << "抱歉，请您重新输入数据，该数据无法求得逆元！" << endl;
			else
			{
				int f = g;
				if (a > b)
					g = exgcd(a, b);
				else
					g = exgcd(b, a);
				cout << "\n您所求的逆元是：" << g << endl;
				cout << "请问您是否还想同时得知最大公因数？是的话请输入1，否则请输入0";
				cin >> g;
				if(g==1)
					cout << "\n最大公因数是：" << f<< endl;
			}
		}
		cout << "请您输入<y/n>，以进行或终结：";
		cin >> ch;
	} while (ch == 'y');
	return 0;
}