#include <bits/stdc++.h>
#define mod 10000
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
int n, m, st, ed, k, f[5];
struct Claris{
	int num[55][55];
	void clear(){memset(num, 0, sizeof num);}
	Claris(){clear();}
	Claris(bool flag){clear();for(int i = 0; i < n; i++)num[i][i]=1;}
}g[13];
Claris operator *(const Claris &a, const Claris &b){
	Claris c;
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++) if(a.num[i][k])
			for(int j = 0; j < n; j++) if(b.num[k][j])
				c.num[i][j] = (c.num[i][j]+a.num[i][k]*b.num[k][j])%mod;
	return c;
}
Claris operator ^(Claris a, int b){
	Claris c(true);
	for(;b;a=a*a,b/=2)if(b&1)c=c*a;
	return c;
}
int main(){
	n = read(); m = read(); st = read(); ed = read(); k = read();
	for(int i = 1, x, y; i <= m; i++){
		x = read(); y = read();
		for(int i = 1; i <= 12; i++)
			g[i].num[x][y] = g[i].num[y][x] = 1;
	}
	int fi = read();
	for(int i = 1; i <= fi; i++){
		int T = read();
		for(int j = 1; j <= T; j++) f[j] = read();
		for(int j = 1; j <= 12; j++)
			for(int k = 0; k < n; k++)
				g[j].num[k][f[j%T+1]] = 0;
	}
	Claris ans(true);
	for(int i = 1; i <= 12; i++)
		ans = ans*g[i];
	ans = ans^(k/12);
	for(int i = 1; i <= k%12; i++)
		ans = ans*g[i];
	printf("%d\n", ans.num[st][ed]);
}
