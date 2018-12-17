#include <bits/stdc++.h>
#define N 200100
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fri[N], val[N], ans[N];
void dfs(int x){
	ans[x] = 2; ans[x^1] = 3;
	if(!ans[fri[x^1]]) dfs(fri[x^1]);
}
int main(){
	int n = read(), n2 = n*2;
	for(int i = 0, x, y; i < n; i++){
		x = read()-1; y = read()-1;
		val[i<<1] = x; val[i<<1|1] = y;
		fri[x] = y; fri[y] = x;
	}
	for(int i = 0; i < n2; i++)
		if(!ans[i]) dfs(i);
	for(int i = 0; i < n; i++)
		printf("%d %d\n", ans[val[i<<1]]-1, ans[val[i<<1|1]]-1);
	return 0;
}