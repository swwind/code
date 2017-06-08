#include <bits/stdc++.h>
#define N 300020
#define block 507
#define inf (1e9+7)
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int fa[N], x, mn[N], flag[N], a[N], ans[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	int n = read();
	memset(mn, 127, sizeof mn);
	for(int i = 0; i < N; i++) fa[i] = i+1;
	for(int i = 1; i <= n; i++){
		char ch = getchar(); while(ch<'A'||ch>'B') ch = getchar();
		int x = read();
		flag[i] = (ch == 'A');
		if(flag[i]){
			a[i] = fa[x] = x;
			for(int i = 1; i <= block; i++)
				mn[i] = min(mn[i], x%i);
		}
		else{
			a[i] = x;
			if(a[i] <= block)
				ans[i] = mn[a[i]];
		}
	}
	for(int i = N-1; i >= 0; i--) fa[i] = find(fa[i]);
	for(int i = n; i; i--){
		if(flag[i]) fa[find(a[i])] = fa[find(a[i]+1)];
		else if(a[i] > block){
			ans[i] = inf;
			for(int j = 0; j < N; j += a[i]){
				if(find(j) == N) continue;
				ans[i] = min(ans[i], find(j)%a[i]);
			}
			if(ans[i] == inf) ans[i] = a[i]-1;
		}
	}
	for(int i = 1; i <= n; i++)
		if(flag[i]) printf("%d\n", ans[i]);
	return 0;
}