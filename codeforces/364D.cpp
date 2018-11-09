#include <bits/stdc++.h>
#define N 1000020
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll x[N], n2, sum, ans, c[N], d[N];
int cnt;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
int main(){
	int n = read(); srand(time(0)); n2 = n/2;
	for(int i = 1; i <= n; i++)
		x[i] = read();
	for(int t = 1; t <= 15; t++){
		int k = rand()%n+1; cnt = 0;
		memset(c, 0, sizeof c);
		for(ll i = 1; i*i <= x[k]; i++) if(x[k]%i == 0){
			d[++cnt] = i;
			if(i*i != x[k]) d[++cnt] = x[k]/i;
		}
		sort(d+1, d+cnt+1);
		for(int i = 1; i <= n; i++)
			c[lower_bound(d+1, d+cnt+1, gcd(x[i], x[k]))-d]++;
		for(int i = 1; i <= cnt; i++)
			for(int j = i+1; j <= cnt; j++)
				if(d[j]%d[i] == 0) c[i] += c[j];
		for(int i = 1; i <= cnt; i++)
			if(c[i] >= n2) ans = max(ans, d[i]);
	}
	printf("%I64d\n", ans);
}