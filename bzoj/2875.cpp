#include <bits/stdc++.h>
#define N 2
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll m;
ll mul(ll a, ll b){
	ll c = 0;
	for(;b;b>>=1,a=(a+a)%m)if(b&1)c=(c+a)%m;
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
					c[i][j] = (c[i][j]+mul(a[i][k], b[k][j]))%m;
		return c;
	}
	friend Matrix operator ^ (Matrix a, ll b){
		Matrix c(true);
		for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
		return c;
	}
};
int main(int argc, char const *argv[]){
	m = read();
	ll a = read(), c = read(), x = read(), n = read(), p = read();
	Matrix ans, tmp;
	tmp[0][0] = a; tmp[1][0] = c; tmp[1][1] = 1;
	ans[0][0] = x; ans[0][1] = 1;
	printf("%lld\n", (ans*(tmp^n))[0][0]%p);
	return 0;
}