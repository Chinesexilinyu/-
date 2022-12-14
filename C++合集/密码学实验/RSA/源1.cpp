#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
#define N 200
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	if (b == 1)
		return b;
	int x, y, r;
	x = a;
	y = b;
	r = x % y;
	x = y;
	y = r;
	return gcd(x, y);
}
bool sushu(int p)
{
	int i,j=sqrt((double)p);
	for (i = 2; i < j; i++)
		if (p % i == 0) break;
	if (i>=j)
		return true;
	else
		return false;
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
int RSA(int n, int e, long long mm)
{
	int i;
	long long cc = mm;
	for (i = 0; i < e-1; i++)
		cc = (cc * mm) % n;
	return cc;
}
int _RSA(int d, long int cc,long long n)
{
	int i;
	long long mm = cc;
	for (i = 0; i < d - 1; i++)
		mm = (mm * cc) % n;
	return mm;
}
int main()
{
	int e,p, q,n,u,d;
	srand(time(0));
	p = rand() % (N-100)+100;
	while (!sushu(p))
	{
		p = rand()%(N-100)+101;
	}
	q = p + 1;
	while (!sushu(q))
	{
		q = q + 1;
	}
	n = p * q;
	u = (p - 1) * (q - 1);
	e = rand() % u;
	while (gcd(u,e) != 1)
	{
		e = rand() % u;
	}
	d = exgcd(u,e);
	while (d < 0)
	{
		d = d + u;
	}
	cout << p << ' ' << q << ' ' << n << ' ' << u << ' ' << e << ' ' << d << endl;
	int m, i;
	long long* a;
	long long* b;
	cout << "请您输入希望的数据个数：" << endl;
	cin >> m;
	a = new long long[m];
	b = new long long[m];
	cout << "请您输入数据：(注意应该小于：" <<n<<')'<< endl;
	for (i = 0; i < m; i++)
		cin >> a[i];
	for (i = 0; i < m; i++)
		b[i] = RSA(n, e, a[i]);
	cout << "密文是：" << endl;
	for (i = 0; i < m; i++)
		cout << b[i] << '\t';
	cout << endl;
	for (i = 0; i < m; i++)
		a[i] = _RSA(d, b[i],n);
	cout << "解密后的明文是：";
	for (i = 0; i < m; i++)
		cout << a[i] << '\t';
	cout << endl;
	delete[]a;
	delete[]b;
	return 0;
}