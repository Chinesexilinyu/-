#include<iostream>
using namespace std;
#define N 5
#define boss 500
int zcy(int m[][N+1], int s[][N+1], int e[][N+1], int w[N+1])
{
	int i,j,k,cost,t;
	for (i = 1; i <= N; i++)
		for (j = i; j <= N; j++)
			m[i][j] = m[i][j - 1] + w[j];
	for (j = 1; j <= N-1; j++)
	{
		for (i = 1; i <= N - j ; i++)
		{
			for (k = 0; k <= j - 1; k++)
			{
				if (m[i][i + k] > m[i + k + 1][i + j])
					t = m[i][i + k];
				else
					t = m[i + k + 1][i + j];
				cost = s[i][i + k] + s[i + k + 1][i + j] + t;
				if (s[i][i + j] > cost)
				{
					s[i][i + j] = cost;
					e[i][i + j] = i + k;
				}
			}
		}
	}
	return s[1][N];
}
int main()
{
	int w[N + 1], m[N + 1][N + 1], s[N + 1][N + 1], e[N + 1][N + 1];
	int i, j,min;
	cout << "请输入数据（个数为：" << N << "):";
	for (i = 1; i <= N; i++)
		cin >> w[i];
	for (i = 0; i <= N; i++)
		for (j = 0; j <= N; j++)
		{
			m[i][j] = 0;
			if (i == j)
				s[i][j] = 0;
			else
				s[i][j] = boss;
		}
	min = zcy(m, s, e, w);
	cout << "最小代价为：" << min << endl;
	return 0;
}