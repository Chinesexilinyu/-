#include<iostream>
using namespace std;
int main()
{
	int x = 0, n, m, k, i = 0, j = 0;
	cin >> n >> m >> k;
	int* a = new int[n], * b = new int[m], * c = new int[m * n];
	for (; i < n; i++)
		cin >> a[i];
	for (; j < m; j++)
		cin >> b[j];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++, x++)
			c[x] = a[i] * b[j];
	for (i = 0; i < n * m; i++)
		for (j = i + 1; j < n * m; j++)
			if (c[i] >c[j])
				x = c[i], c[i] = c[j], c[j] = x;
	for (i = 0; i < m * n; i++)
		cout << c[i] << ' ';
	cout << endl;
	cout << c[k - 1];
	delete[]a;
	delete[]b;
	delete[]c;
	return 0;
}