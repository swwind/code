#include <bits/stdc++.h>
#define N 3
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll mod;
ll mul(ll a, ll b) {
	ll c = 0;
	for(;b;b/=2,a=a*2%mod)if(b&1)c=c+a%mod;
	return c;
}
struct Matrix{
	ll num[N][N];
	void clear(){memset(num, 0, sizeof num);}
	Matrix(){clear();}
	Matrix(bool flag){clear();for(int i = 0; i < N; i++)num[i][i]=1;}
	ll* operator [] (int i) {return num[i];}
	friend Matrix operator * (Matrix a, Matrix b){
		Matrix c;
		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++) if(a[i][k])
				for(int j = 0; j < N; j++) if(b[k][j])
					c[i][j] = (c[i][j]+mul(a[i][k], b[k][j]))%mod;
		return c;
	}
	friend Matrix operator ^ (Matrix a, ll b){
		Matrix c(true);
		for(;b;b/=2,a=a*a)if(b&1)c=c*a;
		return c;
	}
}ans(true);
void zhe_xue(ll now, ll pre){
	Matrix c;
	c[0][0] = now;
	c[1][0] = c[1][1] = c[2][0] = c[2][1] = c[2][2] = 1;
	ll b = pre-now/10+1;
	for(;b;b/=2,c=c*c)if(b&1)ans=ans*c;
}
int main(){
	ll n = read(), t = 10; mod = read();
	while(t <= n) zhe_xue(t, t-1), t *= 10;
	zhe_xue(t, n);
	printf("%lld\n", ans[2][0]);
	return 0;
}
