#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main(void) {
	double x;
	cin >> x;

	double l = 0, r = x;
	while (r - l > 1e-9) {
		double mid = (l + r) / 2;
		if (mid * mid >= x)
			r = mid;
		else
			l = mid;
	}
	printf("%lf\n", l);
	return 0;
}