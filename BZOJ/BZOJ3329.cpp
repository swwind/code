#include <bits/stdc++.h>
#define ll long long
#define N 2
#define mod 1000000007
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct Matrix{
	int num[N][N];
	void clear(){memset(num, 0, sizeof num);}
	Matrix(){clear();}
	Matrix(bool flag){clear();for(int i = 0; i < N; i++)num[i][i]=1;}
	int* operator [] (int i) {return num[i];}
	friend Matrix operator * (Matrix &a, Matrix &b){
		Matrix c;
		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++) if(a[i][k])
				for(int j = 0; j < N; j++) if(b[k][j])
					c[i][j] = (c[i][j]+(ll)a[i][k]*b[k][j])%mod;
		return c;
	}
	friend Matrix operator ^ (Matrix a, ll b){
		Matrix c(true);
		for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
		return c;
	}
};
ll f[64], g[64];
ll work1(ll x){
	ll ans = 0;
	for(int i = 60, flag = 0; i; i--)
		if(x&(1ll<<i-1)){
			ans += f[i];
			if(flag) return ans-1;
			flag = 1;
		} else flag = 0;
	return ans-1;
}
ll work2(ll x){
	Matrix ans;
	ans[0][1] = ans[1][0] = ans[1][1] = 1;
	ans = ans^x;
	return (ans[0][1]+ans[1][1])%mod;
}
int main(){
	f[0] = f[1] = 1;
	for(int i = 2; i < 64; i++)
		f[i] = f[i-1]+f[i-2];
	int T = read();
	while(T--){
		ll n = read();
		printf("%lld\n", work1(n+1));
		printf("%lld\n", work2(n));
	}
}