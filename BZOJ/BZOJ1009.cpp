#include <bits/stdc++.h>
#define N 30
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int mod, n, m;
char str[N];
struct Matrix{
	int num[N][N];
	void clear(){memset(num, 0, sizeof num);}
	Matrix(){clear();}
	Matrix(bool flag){clear();for(int i = 0; i < N; i++)num[i][i]=1;}
	friend Matrix operator * (const Matrix &a, const Matrix &b){
		Matrix c;
		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++) if(a.num[i][k])
				for(int j = 0; j < N; j++) if(b.num[k][j])
					c.num[i][j] = (c.num[i][j]+a.num[i][k]*b.num[k][j])%mod;
		return c;
	}
	friend Matrix operator ^ (Matrix a, int b){
		Matrix c(true);
		for(;b;b/=2,a=a*a)if(b&1)c=c*a;
		return c;
	}
};
int main(){
	n = read(); m = read(); k = read(); scanf("%s", str);
	for(int i = 0; i < m; i++) a[i] = str[i]-'0';
	for(int i = 1, j = 0; i < N; i++){
		while(j && B[j] != B[i]) j = nxt[j];
		if(B[j] == B[i]) j++; nxt[i+1] = j;
	}
	return 0;
}