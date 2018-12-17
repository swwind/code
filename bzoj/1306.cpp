#include <bits/stdc++.h>
#define N 10000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[10], b[10], n, ans;
int f[] = {3, 1, 0, 0};
void dfs(int x, int y){
	if(b[x] > a[x]) return;
	if(b[x] + (n-y+1)*3 < a[x]) return;
	if(x == n){ans++; return;}
	if(y == n){
		int t = a[x]-b[x];
		if(t == 2) return;
		b[y] += f[t];
		dfs(x+1, x+2);
		b[y] -= f[t];
	}
	else{
		b[x] += 3; dfs(x, y+1); b[x] -= 3;
		b[y] += 3; dfs(x, y+1); b[y] -= 3;
		b[x]++, b[y]++; dfs(x, y+1); b[x]--, b[y]--;
	}
}
int main(){
	n = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	dfs(1, 2);
	printf("%d\n", ans);
	return 0;
}
