#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int ans1, ans2;
int main(int argc, char const *argv[]) {
	int l = read(), n = read();
	for (int i = 1; i <= n; i++) {
		int x = read();
		ans1 = max(ans1, min(x, l-x+1));
		ans2 = max(ans2, max(x, l-x+1));
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}