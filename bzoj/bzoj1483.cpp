#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int fa[N], v[N], ans;
set<int> t[N];
void solve(int a, int b){
	for(set<int>::iterator it = t[a].begin(); it != t[a].end(); it++){
		if(v[*it-1] == b) ans--;
		if(v[*it+1] == b) ans--;
		t[b].insert(*it);
	}
	for(set<int>::iterator it = t[a].begin(); it != t[a].end(); it++)
		v[*it] = b;
	t[a].clear();
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++){
		v[i] = read();
		fa[v[i]] = v[i];
		if(v[i] != v[i-1]) ans++;
		t[v[i]].insert(i);
	}
	for(int i = 1; i <= m; i++){
		if(read() == 2) printf("%d\n", ans);
		else{
			int a = read(), b = read();
			if(a == b) continue;
			if(t[fa[a]].size() > t[fa[b]].size())
				swap(fa[a], fa[b]);
			solve(fa[a], fa[b]);
		}
	}
	return 0;
}