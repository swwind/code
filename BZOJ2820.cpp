#include <bits/stdc++.h>
#define N 10000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int pri[670000], mu[N], cnt, f[N];
bool mark[N];
ll n, m, ans;
int main(){
	mu[1] = 1;
	for(int i = 2; i < N; i++){
		if(!mark[i])pri[++cnt]=i,mu[i]=-1;
		for(int j = 1; j <= cnt && pri[j]*i < N; j++){
			mark[pri[j]*i] = 1;
			if(i%pri[j])mu[pri[j]*i] = -mu[i];
			else{mu[pri[j]*i] = 0; break;}
		}
	}
	for(int i = 1; i <= cnt; i++)
		for(int j = 1; j*pri[i] < N; j++)
			f[pri[i]*j] += mu[j];
	for(int i = 1; i < N; i++)
		f[i] += f[i-1];
	int T = read();
	while(T--){
		n = read(), m = read(), ans = 0;
		if(n > m) swap(n, m);
		for(ll i = 1, last; i <= n; i = last+1){
			last = min(n/(n/i), m/(m/i));
			ans += (n/i)*(m/i)*(f[last]-f[i-1]);
		}
		printf("%lld\n", ans);
		printf("%d\n", pri[-10000000]);
	}
}