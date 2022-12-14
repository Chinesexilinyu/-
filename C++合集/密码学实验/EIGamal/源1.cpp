#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define N 1000
void EIGamal(int mm, int& y, int& x,int p,int h,int ha)
{
	int k = rand() % (p - 2) + 1,i;
	y = h;
	x = ha;
	for (i = 0; i < k-1; i++)
	{
		y = (y * h)%p;
		x = (x * ha) % p;
	}
	x = (x * mm) % p;
}
int jiemi(int y, int x, int p, int a)
{
	int cc = y,i,m=p-2-a;
	for (i = 0;i<m; i++)
		cc = (cc * y) % p;
	cc = (cc * x) % p;
	return cc;
}
bool sushu(int p)
{
	int i, j = sqrt((double)p);
	for (i = 2; i < j; i++)
		if (p % i == 0) break;
	if (i >= j)
		return true;
	else
		return false;
}
int main()
{
	int i,p,h,a,ha,n;
	srand(time(0));
	p = rand() % (N - 100) + 100;
	while (!sushu(p))
	{
		p = rand() % (N - 100) + 100;
	}
	h = rand() % (p-1) + 1;
	a = rand() % (p - 2) + 1;
	ha = h;
	for (i = 0; i < a - 1; i++)
		ha = (ha * h) % p;
	char z;
	do
	{
		int* c1, * m, * c2;
		cout << "����ѡ����ܻ��ǽ��ܣ�����A�Ǽ��ܣ�����B�ǽ��ܡ�";
		cin >> z;
		if (z == 'A')
		{
			cout << "�����������ݸ�����";
			cin >> n;
			m = new int[n];
			c1 = new int[n];
			c2 = new int[n];
			cout << "�����������ݣ�(ע��Ӧ��С�ڣ�" << p << ')';
			for (i = 0; i < n; i++)
				cin >> m[i];
			for (i = 0; i < n; i++)
				EIGamal(m[i], c1[i], c2[i], p, h, ha);
			cout << "�����ǣ�";
			for (i = 0; i < n; i++)
				cout << c1[i] << ' ' << c2[i] << endl;
		}
		else
		{
			cout << "��������������Ŀ��ע�⣺�ǳɶԵģ�ֻҪ��������Ϳ����ˣ���";
			cin >> n;
			m = new int[n];
			c1 = new int[n];
			c2 = new int[n];
			cout << "�����������ģ�(ע��Ӧ��С�ڣ�" << p << ')';
			for (i = 0; i < n; i++)
			{
				cin >> c1[i];
				cin >> c2[i];
			}
			for (i = 0; i < n; i++)
				m[i] = jiemi(c1[i], c2[i], p, a);
			cout << "����֮��������ǣ�";
			for (i = 0; i < n; i++)
				cout << m[i] << '\t';
			cout << endl;
		}
		delete[]m;
		delete[]c1;
		delete[]c2;
		cout << "����ѡ���Ƿ�Ҫ������ȥ������y����������n�˳���" << endl;
		cin >> z;
	} while (z == 'y');
	return 0;
}