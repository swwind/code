#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int Q, a[120], q[120], n, k;
bool f[N];
bool check(){
	memset(f, 0, sizeof(bool)*N);
	f[0] = 1;
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= Q/a[q[i]]; j++)
			f[j*a[q[i]]] = 1;
	for(int i = 1; i <= k; i++)
		for(int j = a[q[i]]; j <= Q; j++)
			f[j] = f[j] || f[j-a[q[i]]];
	return f[Q];
}
bool dfs(int x){
	if(x == k+1) return check();
	for(q[x] = q[x-1]+1; q[x] <= n-k+x; q[x]++)
		if(dfs(x+1)) return 1;
	return 0;
}
int main(int argc, char const *argv[]){
	Q = read(); n = read();
	for(int i = 1; i <= n; i++) a[i] = read(); sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++) if((k = i) && dfs(1)) break;
	printf("%d", k);
	for(int i = 1; i <= k; i++)
		printf(" %d", a[q[i]]);
	puts("");
	return 0;
}
// working on...