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
	cout << "请您构建您的数组包含数据个数：";
	cin >> n;
	A = new int[n+1];
	cout << "请您输入数据：";
	for (i = 1; i < n+1; i++)
		cin >> A[i];
	int max, min, jie;
	guge(1,n,max,min,jie);
	cout << "最高股票价格出现在第" << max << "天，其值为：" << A[max] << "\n最低股票价格出现在第" << min << "天，其值为：" << A[min] << "\n最大涨幅为：" << jie << endl;
	return 0;
}