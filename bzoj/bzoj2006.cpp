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
ll f[N][20], sum[N], ans;
int Max(int a, int b){return sum[a] > sum[b] ? a : b;}
int ask(int l, int r){int k = log2(r-l+1); return Max(f[l][k], f[r-(1<<k)+1][k]);}
struct node{
	int st, l, r, p;
	ll sum;
	node(int st = 0, int l = 0, int r = 0, int p = 0, ll sum = 0):st(st),l(l),r(r),p(p),sum(sum){}
	friend bool operator < (const node &a, const node &b){return a.sum < b.sum;}
};
priority_queue<node> q;
int main(int argc, char const *argv[]){
	int n = read(), k = read(), l = read(), r = read();
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+read();
	for(int i = 1; i <= n; i++) f[i][0] = i;
	for(int j = 1; j <= 19; j++)
		for(int i = 1; i <= n; i++)
			if(i+(1<<j) > n+1) break;
			else f[i][j] = Max(f[i][j-1], f[i+(1<<j-1)][j-1]);
	for(int i = 1; i <= n-l+1; i++){
		int ls = i+l-1, rs = min(n, i+r-1);
		int p = ask(ls, rs);
		q.push(node(i, ls, rs, p, sum[p]-sum[i-1]));
	}
	while(k--){
		node now = q.top(); q.pop();
		ans += now.sum;
		if(now.l < now.p){
			int w = ask(now.l, now.p-1);
			q.push(node(now.st, now.l, now.p-1, w, sum[w]-sum[now.st-1]));
		}
		if(now.p < now.r){
			int w = ask(now.p+1, now.r);
			q.push(node(now.st, now.p+1, now.r, w, sum[w]-sum[now.st-1]));
		}
	}
	printf("%lld\n", ans);
	return 0;
}