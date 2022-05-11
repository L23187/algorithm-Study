#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//C= A / B ����C��������r
vector<int> div(vector<int>& A, int b, int& r) {//r������
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i-- ) {
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0)//ȥ��ǰ��0
		C.pop_back();
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

	int r;
	auto C = div(A, b, r);

	for (int i = C.size() - 1; i >= 0; i--) {
		printf("���ǣ�%d", C[i]);
	}
	cout << endl;
	cout <<"�����ǣ�" << r << endl;
	return 0;
}