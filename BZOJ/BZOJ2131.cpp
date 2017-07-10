#include <bits/stdc++.h>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{
	int x, y, v;
	friend bool operator < (const node &a, const node &b){
		return a.x == b.x ? a.y > b.y : a.x < b.x;
	}
}a[N];
int y[N], ans, c[N];
int ask(int x){int mx=0;for(;x;x^=x&-x)mx=max(mx,c[x]);return mx;}
void add(int x, int v){for(;x<N;x+=x&-x)c[x]=max(c[x],v);}
int main(int argc, char const *argv[]){
	int w = read(), n = read();
	for(int i = 1; i <= n; i++){
		int t = read(), p = read();
		a[i].x = (t<<1)+p;
		a[i].y = y[i] = (t<<1)-p;
		a[i].v = read();
	}
	sort(y+1, y+n+1);
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)
		a[i].y = lower_bound(y+1, y+n+1, a[i].y)-y;
	for(int i = 1, k; i <= n; i++){
		ans = max(ans, k = a[i].v+ask(a[i].y));
		add(a[i].y, k);
	}
	printf("%d\n", ans);
	return 0;
}	