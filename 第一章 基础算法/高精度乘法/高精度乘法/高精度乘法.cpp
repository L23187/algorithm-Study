#include<iostream>
#include<vector>

using namespace std;

//C = A * b		意思是一个很高位数的数乘以一个整数
vector<int> mul(vector<int>& A, int b) {
	vector<int> C;
	int t = 0;//进位
	for (int i = 0; i < A.size() || t; i++) {//如果A没有遍历完或者进位没有计算完，则一直循环
		if(i < A.size()) t += A[i] * b;//当i小于A的位数时，继续计算
		C.push_back(t % 10);//每一位都是乘完之后取余，然后进位是整除10
		t /= 10;//进位是整除10
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