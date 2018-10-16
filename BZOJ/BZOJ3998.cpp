#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int ch[N][30], fa[N], l[N], p, np, last, cnt, q, nq, val[N];
void extend(int c){
	p = last; l[last=np=++cnt]=l[p]+1; val[np] = 1;
	for(;p&&!ch[p][c];p=fa[p]) ch[p][c] = np;
	if(!p) fa[np] = 1;
	else{
		q = ch[p][c];
		if(l[q] == l[p]+1) fa[np] = q;
		else{
			l[nq=++cnt] = l[p]+1;
			memcpy(ch[nq], ch[q], sizeof ch[p]);
			fa[nq] = fa[q];
			fa[q] = fa[np] = nq;
			for(;ch[p][c]==q;p=fa[p]) ch[p][c] = nq;
		}
	}
}
int c[N], sz[N], rk[N];
char str[N];
void dfs(int x, int k){
	if(k <= val[x]) return;
	k -= val[x];
	for(int i = 0; i < 26; i++)if(ch[x][i]){
		if(k <= sz[ch[x][i]]){
			putchar(i+'a');
			return dfs(ch[x][i], k);
		}
		k -= sz[ch[x][i]];
	}
}
int main(){
	scanf("%s", str+1);
	last = ++cnt;
	int T = read(), k = read();
	int n = strlen(str+1);
	for(int i = 1; i <= n; i++) extend(str[i]-'a');
	// printf("%d\n", cnt);
	for(int i = 1; i <= cnt; i++) c[l[i]]++;
	for(int i = 1; i <= n; i++) c[i]+=c[i-1];
	for(int i = cnt; i; i--) rk[c[l[i]]--] = i;
	for(int i = cnt; i; i--){
		int t = rk[i];
		if(T) val[fa[t]] += val[t];
		else val[t] = 1;
	}
	val[1] = 0;
	for(int i = cnt; i; i--){
		int t = rk[i]; sz[t] = val[t];
		for(int j = 0; j < 26; j++)
			sz[t] += sz[ch[t][j]];
	}
	if(k > sz[1]) puts("-1");
	else dfs(1, k);
	return 0;
}