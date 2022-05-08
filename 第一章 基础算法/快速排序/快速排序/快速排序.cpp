#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

//���������㷨
void quick_sort(int q[], int l, int r)
{
    //��l���ڵ���rʱֹͣ�ݹ�
    if (l >= r) return;

    //����i��j����ָ�룬xΪ������м��
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    //˫ָ�뿪ʼ���򣬵�i��j�غ�ʱֹͣ����
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    //�ݹ鴦������
    quick_sort(q, l, j);
    //�ݹ鴦���Ұ��
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