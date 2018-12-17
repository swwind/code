#include <bits/stdc++.h>
#define N 5020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[2][N], a[N], ans;
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	for(int i = 1, now = 1, pre = 0; i <= n-4; i++, now ^= 1, pre ^= 1)
		for(int j = i+1; j <= n; j++){
			if(a[i]-a[i-1] == a[j]-a[j-1] && j-i > f[pre][j-1]) f[now][j] = f[pre][j-1]+1;
			else f[now][j] = 1;
			ans = max(ans, f[now][j]);
		}
	printf("%d\n", ans < 5 ? 0 : ans);
	return 0;
}