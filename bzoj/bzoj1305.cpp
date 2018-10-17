#include <bits/stdc++.h>
#define N 1000007
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N<<3], nxt[N<<3], head[N], val[N<<3], dep[N], cnt, nm, q[N], ans;
char ch[60];
int mp[60][60];
void ins(int x, int y, int z){
	to[++cnt] = y; nxt[cnt] = head[x]; val[cnt] = z; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; val[cnt] = z; head[y] = cnt;
}
int bfs(){
	memset(dep, 0, sizeof dep);
	int l = 0, r = 1; q[1] = 1; dep[1] = 1;
	while(l < r){
		int x = q[++l];
		for(int i = head[x]; i; i = nxt[i])
			if(val[i] && !dep[to[i]]){
				q[++r] = to[i];
				dep[to[i]] = dep[x]+1;
			}
	}
	return dep[nm];
}
int dfs(int x, int f){
	if(x == nm) return f;
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
int main(){
	int n = read(), k = read(); nm = 1002;
	for(int i = 1; i <= n; i++){
		scanf("%s", ch+1);
		for(int j = 1; j <= n; j++)
			mp[i][j] = ch[j] == 'Y';
	}
	int l = 0, r = 50, ans;
	while(l <= r){
		int mid = l + r >> 1;
		cnt = 1; memset(head, 0, sizeof head);
		for(int i = 1; i <= n; i++) ins(1,i+1,mid);
		for(int i = 1; i <= n; i++) ins(i+1,i+501,k);
		for(int i = 1; i <= n; i++) ins(n+i+501,n+i+1,k);
		for(int i = 1; i <= n; i++) ins(n+i+1,nm,mid);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(mp[i][j]) ins(i+1,n+j+1,1);
				else ins(i+501,n+j+501,1);
		int sum = 0;
		while(bfs())sum+=dfs(1, 1<<30);
		if(sum < n*mid) r = mid-1;
		else l = mid+1, ans = mid;
	}
	printf("%d\n", ans);
}
