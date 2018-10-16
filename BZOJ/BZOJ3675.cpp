#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll sum[N], q[N], f[2][N], g[2][N];
int main(int argc, char const *argv[]){
	int n = read(), k = read();
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+read(), g[0][i] = sum[i]*sum[i];
	int now = 0, last = 1;
	for(int i = 1; i <= k; i++){
		swap(now, last);
		int l = 1, r = 1;
		q[1] = i;
		memset(g[now], 0, sizeof(int)*N);
		memset(f[now], 0, sizeof(int)*N);
		for(int j = i+1; j <= n; j++){
			while(l < r && g[last][q[l]]-g[last][q[l+1]] >= sum[j]*(sum[q[l]]-sum[q[l+1]])) l++;
			f[now][j] = f[last][q[l]]+sum[q[l]]*(sum[j]-sum[q[l]]);
			g[now][j] = sum[j]*sum[j]-f[now][j];
			while(l < r
				&& (g[last][q[r-1]]-g[last][q[r]])*(sum[q[r]]-sum[j])
				>= (g[last][q[r]]-g[last][j])*(sum[q[r-1]]-sum[q[r]])) r--;
			q[++r] = j;
		}
	}
	printf("%lld\n", f[now][n]);
	return 0;
}
