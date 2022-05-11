#include<iostream>
#include<vector>

using namespace std;

//C = A * b		��˼��һ���ܸ�λ����������һ������
vector<int> mul(vector<int>& A, int b) {
	vector<int> C;
	int t = 0;//��λ
	for (int i = 0; i < A.size() || t; i++) {//���Aû�б�������߽�λû�м����꣬��һֱѭ��
		if(i < A.size()) t += A[i] * b;//��iС��A��λ��ʱ����������
		C.push_back(t % 10);//ÿһλ���ǳ���֮��ȡ�࣬Ȼ���λ������10
		t /= 10;//��λ������10
	}
	return C;
}

int main(void) {
	string a;
	int b;
	cin >> a >> b;

	vector<int> A;
	for (int i = a.size() - 1; i >= 0; i--) {
		A.push_back(a[i] - '0');
	}

	auto C = mul(A, b);

	for (int i = C.size() - 1; i >= 0; i--) {
		printf("%d", C[i]);
	}

	return 0;
}