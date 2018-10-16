#include <bits/stdc++.h>
#define N 50020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n, m, a[N], b[N], val[N];
int pos[N], st[N], rst[250][N], btb[250][250];
void add(int x){
	for(;x<=n;x+=x&-x)++val[x];
}
int ask(int x){
	int ans = 0;
	for(;x;x-=x&-x)ans+=val[x];
	return ans;
}
int work(int l, int r){
	memset(val, 0, sizeof val);
	if(pos[l]==pos[r]){
		int ans = 0;
		for(;l<=r;--r)
			ans += ask(a[r]-1), add(a[r]);
		return ans;
	}
	int ans = btb[pos[l]+1][pos[r]-1], cnt = st[pos[r]]-st[pos[l]+1];
	for(int i = st[pos[l]+1]-1; l <= i; --i){
		ans += ask(a[i]-1)+rst[pos[r]-1][a[i]-1]-rst[pos[l]][a[i]-1];
		add(a[i]); ++cnt;
	}
	for(int i = st[pos[r]]; i <= r; i++){
		ans += cnt-ask(a[i])-rst[pos[r]-1][a[i]]+rst[pos[l]][a[i]];
		add(a[i]); ++cnt;
	}
	return ans;
}
int main(){
	n = read();
	for(int i = 1; i <= n; i++)
		a[i] = b[i] = read();
	sort(b+1, b+n+1);
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(b+1, b+n+1, a[i])-b;
	int size = sqrt(n);
	for(int i = 1; i <= n; i++)
		pos[i] = (i-1)/size+1;
	int block = pos[n];
	for(int i = 1; i <= block; i++)
		st[i] = size*(i-1)+1;
	st[block+1] = n+1;
	for(int i = 1, cnt1=0,cnt2=0; i <= block;
			i++, cnt1=cnt2=0, memcpy(rst[i], rst[i-1], sizeof rst[i]), memset(val, 0, sizeof val))
		for(int j = i; j <= block; j++)
			for(int k = st[j]; k < st[j+1]; k++){
				btb[i][j] = (cnt1 += cnt2-ask(a[k]));
				add(a[k]); ++cnt2, ++rst[j][a[k]];
			}
	for(int i = 1; i <= block; i++)
		for(int j = 2; j <= n; j++)
			rst[i][j] += rst[i][j-1];
	int m = read(), lastans = 0;
	while(m--){
		int l=read()^lastans, r=read()^lastans;
		printf("%d\n", lastans = work(l, r));
	}
	return 0;
}