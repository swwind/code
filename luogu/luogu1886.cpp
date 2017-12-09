#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int n = read(), m = read();
struct MXT {
	int a[N], cnt, b[N], l, r;
	MXT() {
		l = 1; r = 0;
	}
	void push_back(int x) {
		++ cnt;
		while (l <= r && a[r] > x) r --;
		while (l <= r && b[l] <= cnt - m) l ++;
		a[++ r] = x; b[r] = cnt;
	}
	int top() {
		return a[l];
	}
}mxt;
struct MNT {
	int a[N], cnt, b[N], l, r;
	MNT() {
		l = 1; r = 0;
	}
	void push_back(int x) {
		++ cnt;
		while (l <= r && a[r] < x) r --;
		while (l <= r && b[l] <= cnt - m) l ++;
		a[++ r] = x; b[r] = cnt;
	}
	int top() {
		return a[l];
	}
}mnt;
int a[N];
int main(int argc, char const *argv[]) {
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++) {
		mxt.push_back(a[i]);
		i >= m && printf("%d ", mxt.top());
	}
	puts("");
	for (int i = 1; i <= n; i++) {
		mnt.push_back(a[i]);
		i >= m && printf("%d ", mnt.top());
	}
	puts("");
	return 0;
}