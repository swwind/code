#include <bits/stdc++.h>
#define zyy 100000009
#define N 10000020
#define ll long long
using namespace std;
int mu[N], pri[N], cnt;
ll s[N];
bool mark[N];
ll x, y;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll sum(ll a, ll b){
	return (a*(a+1)/2%zyy)*(b*(b+1)/2%zyy)%zyy;
}
ll f(ll a, ll b){
	ll ans = 0;
	for(ll i = 1, last; i <= a; i = last+1){
		last = min(a/(a/i), b/(b/i));
		ans = (ans+(s[last]-s[i-1]+zyy)%zyy*sum(a/i, b/i)%zyy)%zyy;
		// printf("ans  = %d\n", ans);
	}
	return ans;
}
int main(){
	mu[1] = s[1] = 1;
	for(int i = 2; i < N; i++){
		if(!mark[i])pri[++cnt]=i,mu[i]=-1,s[i]=1-i;
		for(int j = 1; j <= cnt && i*pri[j] < N; j++){
			mark[pri[j]*i] = 1;
			if(i%pri[j]==0){mu[pri[j]*i] = 0; s[i*pri[j]]=s[i]; break;}
			s[i*pri[j]] = (s[i]*s[pri[j]])%zyy; mu[pri[j]*i] = -mu[i];
		}
	}
	for(int i = 1; i < N; i++)
		s[i] = (s[i-1]+i*s[i]%zyy)%zyy;
	int T = read();
	while(T--){
		x = read(); y = read();
		if(x > y) swap(x, y);
		printf("%lld\n", (f(x, y)+zyy)%zyy);
	}
}
