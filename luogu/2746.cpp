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
int cnt, low[N], dfn[N], que[N], qnt, blo[N], bnt;
vector<int>son[N];
int in[N], out[N], inc, outc;
void tarjan(int x){
	low[x] = dfn[x] = ++cnt;
	que[++qnt] = x;
	for(int i = 0; i < son[x].size(); i++){
		int y = son[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(!blo[y]) low[x] = min(low[x], dfn[y]);
	}
	if(low[x] == dfn[x] && ++bnt)
		while(que[qnt+1] != x)
			blo[que[qnt--]] = bnt;
}
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++)
		while(int x = read())
			son[i].push_back(x);
	for(int i = 1; i <= n; i++)
		if(!dfn[i]) tarjan(i);
	if(bnt == 1) return puts("1\n0")&0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < son[i].size(); j++)
			if(blo[son[i][j]] != blo[i]){
				in[blo[son[i][j]]]++;
				out[blo[i]]++;
			}
	for(int i = 1; i <= bnt; i++)
		inc += !in[i], outc += !out[i];
	printf("%d\n%d\n", inc, max(inc, outc));
	return 0;
}
