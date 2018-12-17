#include <bits/stdc++.h>
#define N 10020
#define M 50020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node {
	int x, y, z;
	friend bool operator < (const node &a, const node &b) {
		return a.z < b.z;
	}
}e[M];
int fa[N], ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		e[i].x = read();
		e[i].y = read();
		e[i].z = read();
	}
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int x = find(e[i].x);
		int y = find(e[i].y);
		if (x == y) continue;
		fa[x] = y;
		ans += e[i].z;
	}
	printf("%d\n", ans);
	return 0;
}