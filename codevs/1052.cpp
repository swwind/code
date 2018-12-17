#include <bits/stdc++.h>
#define N 120
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{
	int t, g;
	friend bool operator < (const node &a, const node &b){
		return a.g > b.g;
	}
}a[N];
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(int argc, char const *argv[]){
	int n = read(), ans = 0;
	for(int i = 1; i <= n; i++) a[i].t = read();
	for(int i = 1; i <= n; i++) a[i].g = read();
	sort(a+1, a+n+1);
	for(int i = 1; i < N; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) if(int x = find(a[i].t))
		fa[x] = find(fa[x-1]), ans += a[i].g;
	printf("%d\n", ans);
	return 0;
}
