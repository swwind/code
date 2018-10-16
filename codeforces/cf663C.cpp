// WA & faq
#include <bits/stdc++.h>
#define N 100010
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int vis[N], nxt[N<<1], to[N<<1], head[N], val[N], cnt, chs[N];
char str[10];
vector<int> ans[2], tmp[2], cc;
void ins(int x, int y, int v){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}
void find(int x){
	vis[x] = 1; cc.push_back(x);
	for(int i = head[x]; i; i = nxt[i])
		if(!vis[to[i]]) find(to[i]);
}
bool dfs(int x, int v, int t){
	printf("_%d %d %d\n", x,v,chs[x]);
	vis[x] = 1;
	if(chs[x]) tmp[t].push_back(x);
	for(int i = head[x]; i; i = nxt[i]){
		if(vis[to[i]] && (val[i] ^ v ^ chs[x] ^ chs[to[i]]))
			return 0;
		if(!vis[to[i]]){
			chs[to[i]] = val[i] ^ v ^ chs[x];
			if(!dfs(to[i], v, t)) return 0;
		}
	}
	return 1;
}
int solve(int x, int n){
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		cc.clear();
		find(i);
		for(int j = 0; j < cc.size(); j++) vis[cc[j]] = 0;
		tmp[0].clear(); chs[i] = 0;
		bool ok0 = dfs(i, x, 0);
		for(int j = 0; j < cc.size(); j++) vis[cc[j]] = 0;
		tmp[1].clear(); chs[i] = 1;
		bool ok1 = dfs(i, x, 1);
		for(int j = 0; j < cc.size(); j++) vis[cc[j]] = 1;
		if(!ok0 && !ok1) return 1<<30;
		int c = 0;
		if(!ok0) c = 1;
		else if(!ok1) c = 0;
		else c = tmp[0].size() > tmp[1].size();
		ans[x].insert(ans[x].end(), tmp[c].begin(), tmp[c].end());
		printf("%d %d\n", tmp[0].size(), tmp[1].size());
	}
	return ans[x].size();
}
int main(){
	int n = read(), m = read();
	for(int i = 1, x, y; i <= m; i++){
		x = read(); y = read();
		scanf("%s", str);
		ins(x, y, str[0] == 'R');
	}
	int a = solve(0, n);
	int b = solve(1, n);
	int c = a > b;
	if(a == (1<<30) && b == (1<<30)) return puts("-1")&0;
	printf("%d\n", ans[c].size());
	for(int i = 0; i < ans[c].size(); i++)
		printf("%d ", ans[c][i]);
	return 0;
}