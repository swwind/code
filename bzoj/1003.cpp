#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
bool flag[120][21];
ll q, t[120][120], f[120], n, m, k, cnt, val[1000], to[1000], nxt[1000], head[1000];
void insert(int x, int y, int w){
	to[++cnt] = y; nxt[cnt] = head[x];
	head[x] = cnt; val[cnt] = w;
}
ll spfa(ll a, ll b){
	bool block[21];
	ll dis[21], q[500], inq[21];
	memset(block, 0, sizeof(block));
	memset(inq, 0, sizeof(inq));
	for (int i = 0; i <= 20; i++) dis[i]=1<<30;
	for (int i = a; i <= b; i++)
		for (int j=1;j<=m;j++)
			if (flag[i][j])block[j]=1;
	q[0]=1; inq[1]=1; dis[1]=0;
	ll t=0, w=1;
	while(t < w){
		for(int p = head[q[t]]; p; p = nxt[p]){
			if(!block[to[p]] && dis[to[p]] > dis[q[t]]+val[p]){
				dis[to[p]] = dis[q[t]]+val[p];
				if(!inq[to[p]]){
					q[w++] = to[p];
					inq[to[p]] = 1;
				}
			}
		}
		inq[q[t]] = 0; t++;
	}
	return dis[m];
}
void dp(){
	for (ll i=1;i<=n;i++){
		f[i]=t[1][i]*i;
		for (ll j=1;j<i;j++)
			f[i]=min(f[i], f[j]+k+t[j+1][i]*(i-j));
	}
}
int main(){
	n=read(); m=read(); k=read(); q=read();
	for (ll i=1;i<=q;i++){
		ll x=read(), y=read(), z=read();
		insert(x, y, z); insert(y, x, z);
	}
	ll d=read();
	for (ll i=1;i<=d;i++){
		ll x=read(), y=read(), z=read();
		for (ll j=y;j<=z;j++) flag[j][x]=1;
	}
	for (ll i=1;i<=n;i++)
		for (ll j=i;j<=n;j++)
			t[i][j]=spfa(i, j);
	dp();
	printf("%lld\n", f[n]);
}