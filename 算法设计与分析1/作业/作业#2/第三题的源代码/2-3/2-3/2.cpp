#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
    double x;
    double y;
    char flag;
};
int partition(point* p, int q, int r)
{
    point zx;
    int i = q, j = r + 1;
    point t = p[i];
    while (true)
    {
        while ((p[++i].x < t.x) && i < r);
        while (p[--j].x > t.x);
        if (i >= j)
            break;
        zx.x = p[i].x;
        zx.y = p[i].y;
        zx.flag = p[i].flag;
        p[i].x = p[j].x;
        p[i].y = p[j].y;
        p[i].flag = p[j].flag;
        p[j].x=zx.x;
        p[j].y=zx.y;
        p[j].flag=zx.flag;
    }
    p[q].x = p[j].x;
    p[q].y = p[j].y;
    p[q].flag = p[j].flag;
    p[j].x = t.x;
    p[j].y = t.y;
    p[j].flag = t.flag;
    return j;
}
void zcysort(point* p, int q, int r)
{
    if (q < r)
    {
        int m = partition(p, q, r);
        zcysort(p, q, m - 1);
        zcysort(p, m + 1, r);
    }
}
double zcy(int begin, int end,point*p)
{
    int mid = (begin + end) / 2;
    double left = 9999999, right = 9999999, inter = 9999999;

    if (begin >= end)
        return 9999999;
    left = zcy(begin, mid,p);
    right = zcy(mid + 1, end,p);
    for (int i = begin; i <= mid; i++)
    {
        for (int j = mid + 1; j <= end; j++)
        {
            if (p[i].flag != p[j].flag)
            {
                if (p[j].x - p[i].x > inter * 2)
                    break;
                double dis = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
                if (dis < inter)
                    inter = dis;
            }
        }
    }

    return min(min(left, right), inter);
}

int main()
{
    int N,i;
    cout << "请您输入特工\\核电站个数：";
    cin >> N;
    point* p = new point[2 * N];
    cout << "请您输入N个核电站的坐标：\n";
    for (i = 0; i < N; i++)
    {
            cin >> p[i].x;
            cin >> p[i].y;
            p[i].flag = 'a';
    }
    cout << "请您输入N个特工此时的坐标：\n";
    for (i = N; i < N * 2; i++)
    {
        cin >> p[i].x;
        cin >> p[i].y;
        p[i].flag = 'b';
    }
    zcysort(p, 0, 2 * N - 1);
    double min_dis = zcy(0, 2 * N - 1, p);
    cout << "最短距离为：" << min_dis << endl;
    return 0;
}
