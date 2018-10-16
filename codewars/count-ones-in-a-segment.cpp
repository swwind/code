#include <iostream>
using namespace std;

long long work(int x) {
	long long res = 0;
	for (int i = 1; i < 32; i++) {
		res += x >> i << i - 1;
		res += max(0, x - (x >> i << i) - (1 << i - 1) + 1);
	}
	return res;
}

long long countOnes(int left, int right) {
	return work(right) - work(left - 1);
}

int main(int argc, char const *argv[]) {
	int l, r;
	cin >> l >> r;
	cout << work(l - 1) << endl;
	cout << work(r) << endl;
	cout << countOnes(l, r) << endl;
	return 0;
}