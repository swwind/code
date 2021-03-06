#include <bits/stdc++.h>
#define N 1000007
#define ll long long
#define id(i, j) (i-1)*m+j
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N], nxt[N], head[N], val[N], dep[N], cnt = 1, st, ed, q[N];
void ins(int x, int y, int z){
	to[++cnt] = y; nxt[cnt] = head[x]; val[cnt] = z; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; val[cnt] = 0; head[y] = cnt;
}
int bfs(){
	memset(dep, 0, sizeof dep);
	int l = 0, r = 1; q[1] = st; dep[st] = 1;
	while(l < r){
		int x = q[++l];
		for(int i = head[x]; i; i = nxt[i])
			if(val[i] && !dep[to[i]]){
				q[++r] = to[i];
				dep[to[i]] = dep[x]+1;
			}
	}
	return dep[ed];
}
int dfs(int x, int f){
	if(x == ed) return f;
	int sum = 0;
	for(int i = head[x]; i; i = nxt[i]){
		if(val[i] && dep[to[i]] == dep[x]+1){
			int w = dfs(to[i], min(f-sum, val[i]));
			val[i] -= w; val[i^1] += w;
			sum += w; if(sum == f) return f;
		}
	}
	if(!sum) dep[x] = 0;
	return sum;
}
char ch[50];
int mp[50][50], p;
int check(int x1, int y1, int x2, int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) <= p*p;
}
int main(){
	int n = read(), m = read(); p = read();
	int nm = n*m, ans = 0; ed = nm<<1|1;
	for(int i = 1; i <= n; i++){
		scanf("%s", ch+1);
		for(int j = 1; j <= m; j++)
			mp[i][j] = ch[j]-'0';
	}
	for(int i = 1; i <= n; i++){
		scanf("%s", ch+1);
		for(int j = 1; j <= m; j++)
			if(ch[j] == 'L')
				ans++, ins(st, id(i, j), 1);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(min(min(i, n-i+1), min(j, m-j+1)) <= p)
				ins(id(i, j)+nm, ed, 1<<30);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int ii = max(1, i-p); ii <= min(n, i+p); ii++)
				for(int jj = max(1, j-p); jj <= min(m, j+p); jj++)
					if(check(i, j, ii, jj) && mp[i][j] && mp[ii][jj] && (i != ii || j != jj))
						ins(id(i, j)+nm, id(ii, jj), 1<<30);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(mp[i][j]) ins(id(i, j), id(i, j)+nm, mp[i][j]);
	while(bfs())ans-=dfs(st, 1<<30);
	printf("%d\n", ans);
}