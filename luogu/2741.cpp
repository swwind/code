#include <bits/stdc++.h>
#define N 50
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int u[N], d[N], l[N], r[N], in[N], a[N], vis[N], sum;
char ch[N][N];
vector<int>to[N];
map<int, bool>mp[N];
int apr[N];
void dfs(int x){
	if(!x){
		for(int i = sum; i; i--)
			putchar('A'+a[i]); puts("");
		return;
	}
	for(int i = 0; i < 26; i++) if(apr[i])
		if(!in[i] && !vis[i]){
			a[x] = i;
			for(vector<int>::iterator it = to[i].begin(); it != to[i].end(); it++)
				in[*it]--; vis[i] = 1;
			dfs(x-1);
			for(vector<int>::iterator it = to[i].begin(); it != to[i].end(); it++)
				in[*it]++; vis[i] = 0;
		}
}
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	memset(u, 63, sizeof u);
	memset(l, 63, sizeof l);
	for(int i = 1; i <= n; i++){
		scanf("%s", ch[i]+1);
		for(int j = 1; j <= m; j++){
			if(ch[i][j] == '.') continue;
			int x = ch[i][j]-'A';
			apr[x] = 1;
			u[x] = min(u[x], i); d[x] = max(d[x], i);
			l[x] = min(l[x], j); r[x] = max(r[x], j);
		}
	}
	for(int i = 0; i < 26; i++) sum += apr[i];
	// for(int i = 0; i < p; i++)
		// printf("%d %d %d %d\n", u[i], d[i], l[i], r[i]);
	for(int x = 0; x < 26; x++) if(apr[x]){
		for(int i = l[x]; i <= r[x]; i++){
			if(ch[u[x]][i] != '.' && ch[u[x]][i]-'A' != x && !mp[x][ch[u[x]][i]-'A'])
				mp[x][ch[u[x]][i]-'A'] = 1, in[ch[u[x]][i]-'A']++, to[x].push_back(ch[u[x]][i]-'A');
			if(ch[d[x]][i] != '.' && ch[d[x]][i]-'A' != x && !mp[x][ch[d[x]][i]-'A'])
				mp[x][ch[d[x]][i]-'A'] = 1, in[ch[d[x]][i]-'A']++, to[x].push_back(ch[d[x]][i]-'A');
		}
		for(int i = u[x]; i <= d[x]; i++){
			if(ch[i][l[x]] != '.' && ch[i][l[x]]-'A' != x && !mp[x][ch[i][l[x]]-'A'])
				mp[x][ch[i][l[x]]-'A'] = 1, in[ch[i][l[x]]-'A']++, to[x].push_back(ch[i][l[x]]-'A');
			if(ch[i][r[x]] != '.' && ch[i][r[x]]-'A' != x && !mp[x][ch[i][r[x]]-'A'])
				mp[x][ch[i][r[x]]-'A'] = 1, in[ch[i][r[x]]-'A']++, to[x].push_back(ch[i][r[x]]-'A');
		}
	}
	dfs(sum);
	return 0;
}