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
int st[N], po[N], cnt;
int main(int argc, char const *argv[]) {
	int n = read();
	while (n --) {
		int x = read(), p = read(), c = 0;
		while (cnt && p == 0 && po[cnt] == 1) {
			if (st[cnt] > x) { // be eat
				c = 1;
				break;
			} else { // can eat
				cnt --;
			}
		}
		if (!c) st[++cnt] = x, po[cnt] = p;
	}
	printf("%d\n", cnt);
	return 0;
}