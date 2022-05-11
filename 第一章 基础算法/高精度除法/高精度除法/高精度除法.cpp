#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//C= A / B 商是C，余数是r
vector<int> div(vector<int>& A, int b, int& r) {//r是引用
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i-- ) {
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0)//去除前导0
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
		printf("商是：%d", C[i]);
	}
	cout << endl;
	cout <<"余数是：" << r << endl;
	return 0;
}