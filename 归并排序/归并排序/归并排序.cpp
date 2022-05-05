#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

const int N = 1000010;

int n;
int q[N], tmp[N];

//归并排序
void merge_sort(int q[], int l, int r) {//l 和 r 是要排序数组的左右边界
	if (l >= r) return;//当数组内只有一个数或没有数时就不用排序了

	int mid = (l + r) >> 1;//取当前数组的中点

	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//递归排序左边，递归排序右边

	int k = 0, i = l, j = mid + 1;
	//归并的过程
	while (i <= mid && j <= r) {//i是从数组开头开始的指针，j是从中点处开始的指针，mid将数组划为两个部分
		//当i指向的数小于等于j指向的数时将i指向的数放入tmp数组中
		if (q[i] <= q[j])
			tmp[k++] = q[i++];
		else
			tmp[k++] = q[j++];
	}
	//当前半部分数组没有循环完时，将剩下的数放入tmp数组中
	while (i <= mid)
		tmp[k++] = q[i++];
	//当后半部分数组没有循环完时，将剩下得到数放入tmp数组中
	while (j <= r)
		tmp[k++] = q[j++];
	//最后将tmp数组赋值给原数组
	for (i = l, j = 0; i <= r; i++, j++)
		q[i] = tmp[j];
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &q[i]);

	merge_sort(q, 0, n - 1);

	for (int i = 0; i < n; i++) printf("%d ", q[i]);
	return 0;
}