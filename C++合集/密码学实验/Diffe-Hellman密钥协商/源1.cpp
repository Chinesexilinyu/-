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
	cout << "���������û�A����������ֻ����֪����x����ע�⣺x����ֵӦ��С�ڣ�" << p << ")" << endl;
	cin >> x;
	int i;
	char g;
	hx = h;
	for (i = 0; i < x - 1; i++)
		hx = (hx * h) % p;
	cout << "�û�A���Ƿ���Ҫ�鿴Ŀǰ����֪����Ϣ���ǣ�������y����������n��";
	cin >> g;
	if (g == 'y')
		cout <<"����Ҫ�����û�B����Ϣ�ǣ�" << hx << endl;
}
void B1(int hx, int&hy, int&kb,int&y,int h,int p)
{
	cout << "���������û�B����������ֻ����֪����y����ע�⣺y����ֵӦ��С�ڣ�" << p << ")" << endl;
	cin >> y;
	int i;
	char g;
	hy = h;
	for (i = 0; i < y - 1; i++)
		hy = (hy * h) % p;
	kb = hx;
	for (i = 0; i < y - 1; i++)
		kb = (kb * hx) % p;
	cout << "�û�B���Ƿ���Ҫ�鿴Ŀǰ����֪����Ϣ���ǣ�������y����������n��";
	cin >> g;
	if (g == 'y')
		cout << "����Ҫ�����û�A����Ϣ�ǣ�" << hy<<"  ���������յ�AB˫���Ĺ�����ԿKΪ"<<kb<< endl;
}
void A2(int p, int hy, int& ka, int x)
{
	int i;
	ka = hy;
	for (i = 0; i < x - 1; i++)
		ka = (ka * hy) % p;
	cout << "���������û�A���������յ�AB˫���Ĺ�����Կ��"<<ka<<endl;
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
	cout << "Ŀǰ������֪���ǣ�����pΪ" << p<< "   ��ʹ�õ�����ԪΪ" << h << endl;
	do
	{
		A1(p, h, hx, x);
		B1(hx,hy,kb,y,h,p);
		A2(p, hy, ka, x);
		cout << "�������鿴�û�A���յ���Ϣ�Ļ���������A���������鿴�û�B���յ���Ϣ�Ļ���������B������㻹�����½���һ�����ӵĻ���������y�������������Ļ���������n:";
		cin >> Z;
		while (Z == 'A' || Z == 'B')
		{
			if (Z == 'A')
			{
				cout << "���������û�A���������յ���ϢΪ��" << endl;
				cout << "ֻ����֪����x:" << x << "\n��֮ǰ����B����Ϣ��" << hx << "\n����B֮��Ĺ�����Կ��" << ka << endl;
			}
			else
			{
				cout << "���������û�B���������յ���ϢΪ��" << endl;
				cout << "ֻ����֪����y:" << y << "\n��֮ǰ����A����Ϣ��" << hy << "\n����A֮��Ĺ�����Կ��" << kb << endl;
			}
			cout << "�������鿴�û�A���յ���Ϣ�Ļ���������A���������鿴�û�B���յ���Ϣ�Ļ���������B������㻹�����½���һ�����ӵĻ���������y�������������Ļ���������n:";
			cin >> Z;
		}
	} while (Z == 'y');
	return 0;
}