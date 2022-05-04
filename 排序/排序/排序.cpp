#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];

//快排算法模板
void quick_sort(int q[], int l, int r) {
	if (l >= r)return;//确定边界
	int x = q[l], i = l - 1, j = r + 1;//取分界点X，i和j是指针
	while (i < j) {
		do i++; while (q[i] < x);
		do j--; while (q[i] > x);
		if (i < j)swap(q[i], q[j]);//swap()交换俩个数
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