#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int fa[N], fl[N], ans[N], _fa[N], cnt;
int n, m;
vector<int> son[N];
struct ask{
	char type;
	int val;
}qus[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	n=read(); m=read();
	for(int i = 1, x, y; i < n; i++){
		x=read(); y=read();
		son[x].push_back(y);
		fa[y] = _fa[y] = x;
	}fa[1]=1; fl[1]=1;
	for(int i = 1, x; i <= m; i++){
		char ch=getchar();
		while(ch!='C'&&ch!='Q')ch=getchar(); x=read();
		qus[i].type = ch; qus[i].val = x;
		if(ch=='C')fl[x]++, fa[x]=x;
	}
	for(int i = m; i; i--)
		if(qus[i].type=='C'){
			fl[qus[i].val]--;
			if(!fl[qus[i].val])fa[qus[i].val]=_fa[qus[i].val];
		}
		else ans[i] = find(qus[i].val);
	for(int i = 1; i <= m; i++)
	if(ans[i]) printf("%d\n", ans[i]);
}