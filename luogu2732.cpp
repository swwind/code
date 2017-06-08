#include <bits/stdc++.h>
#define rep(a, b) for(int a = 0; a <= b; a++)
#define inf (1<<30)
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(ll x){
	if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10);
    putchar(x%10+'0');
}
void writeln(ll x){
	write(x);
	printf("\n");
}
int name[1000], a[6], sale[105][6], s, b, t, f[6][6][6][6][6];
int main(){
	s = read();
	for(int i = 1; i <= s; i++){
		int n = read();
		for(int j = 1; j <= n; j++){
			int c = read();
			int k = read();
			if(!name[c]) name[c] = ++t;
			sale[i][name[c]] = k;
		}
		sale[i][0] = read();
	}
	b = read();
	for(int i = 1; i <= b; i++){
		int c = read();
		a[i] = read();
		int p = read();
		if(!name[c]) name[c] = ++t;
		sale[s+i][name[c]] = 1;
		sale[s+i][0] = p;
	}
	rep(i, a[1]) rep(j, a[2]) rep(k, a[3]) rep(l, a[4]) rep(m, a[5]) if(i+j+k+l+m){
		f[i][j][k][l][m] = inf;
		for(int n = 1; n <= s+b; n++)
			if(i >= sale[n][1] && j >= sale[n][2] && k >= sale[n][3] && l >= sale[n][4] && m >= sale[n][5])
				f[i][j][k][l][m] = min(f[i][j][k][l][m], f[i-sale[n][1]][j-sale[n][2]][k-sale[n][3]][l-sale[n][4]][m-sale[n][5]]+sale[n][0]);
	}		printf("%d", f[a[1]][a[2]][a[3]][a[4]][a[5]]);
	return 0;
}

