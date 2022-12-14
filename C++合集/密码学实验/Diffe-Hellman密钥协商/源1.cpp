#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define N 1000
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
void A1(int p,int h,int&hx,int&x)
{
	cout << "现在您是用户A，请您输入只有您知道的x：（注意：x的数值应该小于：" << p << ")" << endl;
	cin >> x;
	int i;
	char g;
	hx = h;
	for (i = 0; i < x - 1; i++)
		hx = (hx * h) % p;
	cout << "用户A您是否想要查看目前您已知的信息？是，请输入y；否，请输入n：";
	cin >> g;
	if (g == 'y')
		cout <<"您将要发给用户B的信息是：" << hx << endl;
}
void B1(int hx, int&hy, int&kb,int&y,int h,int p)
{
	cout << "现在您是用户B，请您输入只有您知道的y：（注意：y的数值应该小于：" << p << ")" << endl;
	cin >> y;
	int i;
	char g;
	hy = h;
	for (i = 0; i < y - 1; i++)
		hy = (hy * h) % p;
	kb = hx;
	for (i = 0; i < y - 1; i++)
		kb = (kb * hx) % p;
	cout << "用户B您是否想要查看目前您已知的信息？是，请输入y；否，请输入n：";
	cin >> g;
	if (g == 'y')
		cout << "您将要发给用户A的信息是：" << hy<<"  您现在掌握的AB双方的共享密钥K为"<<kb<< endl;
}
void A2(int p, int hy, int& ka, int x)
{
	int i;
	ka = hy;
	for (i = 0; i < x - 1; i++)
		ka = (ka * hy) % p;
	cout << "您现在是用户A，您所掌握的AB双方的共享密钥："<<ka<<endl;
}
int main()
{
	int p, h,i,hx,x,hy,y,kb,ka;
	char Z;
	srand(time(0));
	p = rand() % (N - 100) + 100;
	while (!sushu(p))
	{
		p = rand() % (N - 100) + 100;
	}
	h = rand() % (p - 1) + 1;
	cout << "目前公共可知的是：质数p为" << p<< "   所使用的生成元为" << h << endl;
	do
	{
		A1(p, h, hx, x);
		B1(hx,hy,kb,y,h,p);
		A2(p, hy, ka, x);
		cout << "如果您想查看用户A掌握的信息的话，请输入A，如果您想查看用户B掌握的信息的话，请输入B，如果你还想重新建立一次链接的话，请输入y，如果您想结束的话，请输入n:";
		cin >> Z;
		while (Z == 'A' || Z == 'B')
		{
			if (Z == 'A')
			{
				cout << "现在您是用户A，您所掌握的信息为：" << endl;
				cout << "只有您知道的x:" << x << "\n您之前发给B的信息：" << hx << "\n您与B之间的共享密钥：" << ka << endl;
			}
			else
			{
				cout << "现在您是用户B，您所掌握的信息为：" << endl;
				cout << "只有您知道的y:" << y << "\n您之前发给A的信息：" << hy << "\n您与A之间的共享密钥：" << kb << endl;
			}
			cout << "如果您想查看用户A掌握的信息的话，请输入A，如果您想查看用户B掌握的信息的话，请输入B，如果你还想重新建立一次链接的话，请输入y，如果您想结束的话，请输入n:";
			cin >> Z;
		}
	} while (Z == 'y');
	return 0;
}