#include<iostream>
using namespace std;
int tile = 0;
#define N 1000
int Board[N][N] = { 0 };
void puzhuan(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1) return;
	int t = tile++, s = size / 2;
	if (dr < tr + s && dc < tc + s)
		puzhuan(tr, tc, dr, dc, s);
	else
	{
		Board[tr + s - 1][tc + s - 1] = t;
		puzhuan(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if(dr<tr+s&&dc>=tc+s)
		puzhuan(tr,tc+s,dr,dc,s);
	else
	{
		Board[tr+s-1][tc+s]=t;
		puzhuan(tr,tc+s,tr+s-1,tc+s,s);
	}
	if(dr>=tr+s&&dc<tc+s)
		puzhuan(tr+s,tc,dr,dc,s);
	else
	{
		Board[tr + s][tc + s - 1] = t;
		puzhuan(tr + s, tc, tr + s, tc + s - 1, s);
	}
	if (dr >= tr + s && dc >= tc + s)
		puzhuan(tr + s, tc + s, dr, dc, s);
	else
	{
		Board[tr + s][tc + s] = t;
		puzhuan(tr + s, tc + s, tr + s, tc + s, s);
	}
}
int main()
{
	int n, dr, dc, i, j;
	cout << "������nֵ��(����ש��n*n��nֵ��";
	cin >> n;
	cout << "��������Ҫ�ı��ש�����꣺";
	cin >> dr >> dc;
	Board[dr][dc] = N;
	puzhuan(0, 0, dr, dc, n);
	cout <<N<< "���������Ҫ�任��ש����ͬ���ִ������һ����Ҫ�̵Ĵ�ש���ϣ�" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << Board[i][j]<<'\t';
		cout << '\n';
	}
	return 0;
}