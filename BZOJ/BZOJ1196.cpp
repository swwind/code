#include <bits/stdc++.h>
#define N 20020
using namespace std;
inline int read(){
	int x = 0; char ch = getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
struct node{
	int x, y, c1, c2;
	void read(){
		x = ::read(); y = ::read();
		c1 = ::read(); c2 = ::read();
	}
}e[N];
int fa[N], n, k, m;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int check(int xs){
	int ans = 0;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1,x,y; i < m; i++){
		if(e[i].c1 > xs) continue;
		x = find(e[i].x); y = find(e[i].y);
		if(x == y) continue;
		fa[x] = y; ans++;
	}
	if(ans < k) return 0;
	for(int i = 1, x, y; i < m; i++){
		if(e[i].c2 > xs) continue;
		x = find(e[i].x); y = find(e[i].y);
		if(x == y) continue;
		fa[x] = y; ans++;
	}
	return ans == n-1;
}
int main(){
	n = read(); k = read(); m = read();
	for(int i = 1; i < m; i++) e[i].read();
	int l = 1, r = 30000, mid;
	while(l < r){
		mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	printf("%d\n", l);
	return 0;
}