#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

//判断是否 A >= B
bool cmp(vector<int>& A, vector<int>& B) {
	if (A.size() != B.size())
		return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; i--) {
		if (A[i] != B[i])
			return A[i] > B[i];
	}
	return true;
}

vector<int> sub(vector<int>& A, vector<int>& B) {
	vector<int> C;//定义结果

	int t = 0;

	for (int i = 0, t = 0; i < A.size(); i++) {
		t = A[i] - t;//算A[i]减去B[i]
		if (i < B.size())//判断B[i]是否存在，如果B的位数比A少，可能不存在，所以要写i < B.size()
			t -= B[i];//计算A[i] - B[i],并且将进位也算进去
		C.push_back((t + 10) % 10);//当t >= 0 就为t，如果t < 0 则为 t+10 , 将结果结合一下则是 (t + 10) % 10
		if (t < 0)
			t = 1;
		else
			t = 0;
	}

	while (C.size() > 1 && C.back() == 0)//去掉前导0
		C.pop_back();
	return C;
}

int main(void) {
	string a, b;
	vector<int> A, B;
	cin >> a >> b;//a = “123456”
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');//A = [6，5,4,3,2,1]
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

	if (cmp(A, B)) {
		auto C = sub(A, B);//auto可以让编译器自己判断是什么变量类型
		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}
	else {
		auto C = sub(B, A);
		printf("-");
		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}

	return 0;
}