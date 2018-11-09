#include <bits/stdc++.h>
#define N 200007
#define M 500007
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int x[M], y[M], a[N], b[N], op[M];
int main() {
	int n = read(), m = read();
	for (int i = 1; i <= m; i++){
		op[i] = getchar(); x[i] = read();
		if(op[i] != '!') y[i] = read();
	}
	for(int i = m; i; i--)
		if(op[i] == '!') b[x[i]]++;
		else if(op[i] == '+') a[x[i]] += b[y[i]], a[y[i]] += b[x[i]];
		else a[x[i]] -= b[y[i]], a[y[i]] -= b[x[i]];
	printf("%d", a[1]);
	for(int i = 2; i <= n; i++)
		printf(" %d", a[i]);
}
