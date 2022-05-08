#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

//快速排序算法
void quick_sort(int q[], int l, int r)
{
    //当l大于等于r时停止递归
    if (l >= r) return;

    //定义i和j两个指针，x为数组的中间点
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    //双指针开始排序，当i与j重合时停止排序
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    //递归处理左半边
    quick_sort(q, l, j);
    //递归处理右半边
    quick_sort(q, j + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) 
        printf("%d ", q[i]);

    return 0;
}