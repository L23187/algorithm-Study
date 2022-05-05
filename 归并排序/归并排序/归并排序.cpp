#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

const int N = 1000010;

int n;
int q[N], tmp[N];

//�鲢����
void merge_sort(int q[], int l, int r) {//l �� r ��Ҫ������������ұ߽�
	if (l >= r) return;//��������ֻ��һ������û����ʱ�Ͳ���������

	int mid = (l + r) >> 1;//ȡ��ǰ������е�

	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//�ݹ�������ߣ��ݹ������ұ�

	int k = 0, i = l, j = mid + 1;
	//�鲢�Ĺ���
	while (i <= mid && j <= r) {//i�Ǵ����鿪ͷ��ʼ��ָ�룬j�Ǵ��е㴦��ʼ��ָ�룬mid�����黮Ϊ��������
		//��iָ�����С�ڵ���jָ�����ʱ��iָ���������tmp������
		if (q[i] <= q[j])
			tmp[k++] = q[i++];
		else
			tmp[k++] = q[j++];
	}
	//��ǰ�벿������û��ѭ����ʱ����ʣ�µ�������tmp������
	while (i <= mid)
		tmp[k++] = q[i++];
	//����벿������û��ѭ����ʱ����ʣ�µõ�������tmp������
	while (j <= r)
		tmp[k++] = q[j++];
	//���tmp���鸳ֵ��ԭ����
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