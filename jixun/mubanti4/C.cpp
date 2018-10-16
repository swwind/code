#include <bits/stdc++.h>
#define ll long long
#define mod 1000000009
using namespace std;
struct Matrix{
	#define MSZ 2
	ll num[MSZ][MSZ];
	void clear(){memset(num, 0, sizeof num);}
	Matrix(){clear();}
	Matrix(bool flag){clear();for(int i = 0; i < MSZ; i++)num[i][i]=1;}
	ll* operator [] (int i) {return num[i];}
	friend Matrix operator * (Matrix &a, Matrix &b){
		Matrix c;
		for(int k = 0; k < MSZ; k++)
			for(int i = 0; i < MSZ; i++) if(a[i][k])
				for(int j = 0; j < MSZ; j++) if(b[k][j])
					c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
		return c;
	}
	friend Matrix operator ^ (Matrix a, ll b){
		Matrix c(true);
		for(;b;b/=2,a=a*a)if(b&1)c=c*a;
		return c;
	}
};
int main(int argc, char const *argv[]) {
	ll x;
	cin >> x;
	Matrix ans;
	ans[0][0] = ans[0][1] = ans[1][0] = 1;
	ans = ans ^ (x - 1);
	printf("%lld\n", ans[0][0]);
	return 0;
}