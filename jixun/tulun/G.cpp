#include <bits/stdc++.h>
#define N 512
#define ll long long
#define misaka 250
#define rep(i, h) for (int i = misaka - h; i <= h + misaka; i++) if (i)
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int fa[N], sz[N], out[N], ini[N], vis[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x, int y) {
	int xx = find(x), yy = find(y);
	if (xx == yy) ++ sz[xx];
	else fa[xx] = yy, sz[yy] += sz[xx] + 1;
}
int main(int argc, char const *argv[]) {
	int n = read(), h = read();
	rep(i, h) fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= n; i++) {
		int a = read(), b = read(), c = read(), d = read();
		int x = (c ? -c : a) + misaka;
		int y = (d ? d : -b) + misaka;
		out[x] ++; ini[y] ++;
		merge(x, y);
	}
	for (int i = 1 + misaka; i <= h + misaka; i++)
		if (out[i] < ini[i]) return puts("NO") & 0;
	for (int i = misaka - h; i <= misaka - 1; i++)
		if (ini[i] < out[i]) return puts("NO") & 0;
	rep(i, h) vis[find(i)] |= (out[i] != ini[i]);
	rep(i, h)
		if (sz[find(i)] > 1 && find(i) == i && !vis[i])
			return puts("NO") & 0;
	puts("YES");
	return 0;
}
