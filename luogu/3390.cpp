#include <bits/stdc++.h>
#define ll long long
#define N 100
#define mod 1000000007
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int sz = read();
ll k = read();
struct Matrix{
	int num[N][N];
	void clear(){memset(num, 0, sizeof num);}
	Matrix(){clear();}
	Matrix(bool flag){clear();for(int i = 0; i < sz; i++)num[i][i]=1;}
	int* operator [] (int i) {return num[i];}
	friend Matrix operator * (Matrix a, Matrix b){
		Matrix c;
		for(int k = 0; k < sz; k++)
			for(int i = 0; i < sz; i++) if(a[i][k])
				for(int j = 0; j < sz; j++) if(b[k][j])
					c[i][j] = (c[i][j]+(ll)a[i][k]*b[k][j])%mod;
		return c;
	}
	friend Matrix operator ^ (Matrix a, ll b){
		Matrix c(true);
		for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
		return c;
	}
	void print(){
		for(int i = 0; i < sz; i++, puts(""))
			for(int j = 0; j < sz; j++)
				printf("%d ", num[i][j]);
	}
}ans;
int main() {
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			ans[i][j] = read();
	(ans^k).print();
}