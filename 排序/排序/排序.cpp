#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];

//�����㷨ģ��
void quick_sort(int q[], int l, int r) {
	if (l >= r)return;//ȷ���߽�
	int x = q[l], i = l - 1, j = r + 1;//ȡ�ֽ��X��i��j��ָ��
	while (i < j) {
		do i++; while (q[i] < x);
		do j--; while (q[i] > x);
		if (i < j)swap(q[i], q[j]);//swap()����������
	}
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}


int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i]);
	}

	quick_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", q[i]);
	}
	return 0;
}