#include<iostream>
using namespace std;
int* A;
int max2(int a, int b)
{
	if (A[a] > A[b])
		return a;
	else return b;
}
int maxt(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}
int min2(int a, int b)
{
	if (A[a] < A[b])
		return a;
	else return b;
}
int max3(int a, int b, int c)
{
	int t = maxt(a, b);
	return maxt(t, c);
}
void guge(int i, int j, int& max, int& min, int& jie)
{
	int lmax, lmin, rmax, rmin,m,ljie,rjie;
	if (i == j)
	{
		max = min = i;
		jie = 0;
	}
	else
	{
		m = (i + j) / 2;
		guge(i, m, lmax, lmin, ljie);
		guge(m + 1, j, rmax, rmin, rjie);
		max = max2(lmax, rmax);
		min = min2(lmin, rmin);
		jie = max3(ljie, rjie, A[rmax] - A[lmin]);
	}
}
int main()
{
	int n,i;
	cout << "����������������������ݸ�����";
	cin >> n;
	A = new int[n+1];
	cout << "�����������ݣ�";
	for (i = 1; i < n+1; i++)
		cin >> A[i];
	int max, min, jie;
	guge(1,n,max,min,jie);
	cout << "��߹�Ʊ�۸�����ڵ�" << max << "�죬��ֵΪ��" << A[max] << "\n��͹�Ʊ�۸�����ڵ�" << min << "�죬��ֵΪ��" << A[min] << "\n����Ƿ�Ϊ��" << jie << endl;
	return 0;
}