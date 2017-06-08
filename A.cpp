#include <bits/stdc++.h>
#define N 10
#define mod 2
struct Matrix{
	int num[N][N];
	void clear(){memset(num, 0, sizeof num);}
	Matrix(){clear();}
	Matrix(bool flag){clear();for(int i = 0; i < N; i++)num[i][i]=1;}
	int* operator [] (int &i) {return num[i];}
	friend Matrix operator * (Matrix &a, Matrix &b){
		Matrix c;
		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++) if(a[i][k])
				for(int j = 0; j < N; j++) if(b[k][j])
					c[i][j] = (c[i][j]+a[i][k]*b[k][j])%mod;
		return c;
	}
	friend Matrix operator ^ (Matrix a, int b){
		Matrix c(true);
		for(;b;b/=2,a=a*a)if(b&1)c=c*a;
		return c;
	}
};
int main(){}