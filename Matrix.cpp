#include <bits/stdc++.h>
#define ll long long
#define N 4
#define mod 1000000007
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
		for(;b;b/=2,a=a*a)if(b&1)c=c*a;
		return c;
	}
};
int main(){
	ll n;
	scanf("%lld", &n);
	Matrix ans;
	ans[0][0] = 2;
	ans[1][1] = ans[1][0] = ans[0][1] = 1;
	ans = ans^n;
	printf("%d\n", ans[0][0]);
}