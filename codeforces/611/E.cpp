#include <bits/stdc++.h>
#define N 1000020
#define ll long long
#define mod 10000
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int k[N], cnt, ans;
bitset<200020> bit[16], used;
int main(int argc, char const *argv[]) {
	int n = read(), a = read(), b = read(), c = read();
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	int sum = a + b + c;
	int szb_ak_wang = b + c;
	for (int i = 1; i <= n; i++) {
		int k[i] = read(), flag = 0;
		if (k[i] > sum)
			return puts("-1")&0;
		if (k[i] <= a) bit[1][i] = 1;
		if (k[i] <= b) bit[2][i] = 1;
		if (k[i] <= c) bit[4][i] = 1;
		if (k[i] > c) {
			for (int j = 3; j < 15; j++) {
				if (j == 4)
					continue;
				int _sum = sum;
				if (~ j & 1) sum -= a;
				if (~ j & 2) sum -= b;
				if (~ j & 4) sum -= c;
				if (k[i] <= sum) {
					bit[j][i] = 1;
					flag = 1;
				}
			}
		}
		if (!flag)
			ans ++;
	}
	return 0;
}