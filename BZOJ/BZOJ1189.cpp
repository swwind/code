#include <bits/stdc++.h>
#define N 1000007
#define id(i, j) (i-1)*m+j
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N], nxt[N], head[N], val[N], dep[N], cnt = 1, st = 1, ed = 1001, q[N], ans, nm;
void ins(int x, int y, int z){
	to[++cnt] = y; nxt[cnt] = head[x]; val[cnt] = z; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; val[cnt] = z; head[y] = cnt;
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
char str[50];
int mp[30][30], door, sum, n, m;
int dis[900][30][30];
int vis[30][30];
struct node{
	int x, y;
	node(int x = 0, int y = 0):x(x),y(y){}
}dr[900], qs[1000];
int sx[] = {0, 1, 0, -1};
int sy[] = {1, 0, -1, 0};
int bfs(int x){
	int l = 0, r = 1;
	qs[1] = dr[x]; dis[x][qs[1].x][qs[1].y] = 0;
	memset(vis, 0, sizeof vis); vis[qs[1].x][qs[1].y] = 1;
	while(l < r){
		int nx = qs[++l].x, ny = qs[l].y;
		for(int i = 0; i < 4; i++){
			int xx = nx+sx[i], yy = ny+sy[i];
			if(!xx || !yy || xx > n || yy > m || mp[xx][yy] || vis[xx][yy]) continue;
			vis[xx][yy] = 1;
			dis[x][xx][yy] = dis[x][nx][ny]+1;
			qs[++r].x = xx; qs[r].y = yy;
		}
	}
	dis[x][qs[1].x][qs[1].y] = dis[0][0][0];
}
int check(int x){
	cnt = 1; memset(head, 0, sizeof head);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(!mp[i][j]) ins(st, id(i, j)+1, 1);
	for(int i = 1; i <= door; i++) ins(nm+i+2, ed, x);
	for(int i = 1; i <= door; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= m; k++)
				if(dis[i][j][k] <= x) ins(id(j, k)+1, nm+i+2, x);
	int ans = 0;
	while(bfs())ans+=dfs(st, 1<<30);
	return ans == sum;
}
int main(){
	n = read(); m = read(); nm = n*m;
	for(int i = 1; i <= n; i++){
		scanf("%s", str+1);
		for(int j = 1; j <= m; j++)
			if(str[j] == 'D') dr[++door] = node(i, j), mp[i][j] = 1;
			else if(str[j] == 'X') mp[i][j] = 1;
			else sum++;
	}
	memset(dis, 127/3, sizeof dis);
	for(int i = 1; i <= door; i++) bfs(i);
	int l = 0, r = 400;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)) ans = mid, r = mid-1;
		else l = mid+1;
	}
	if(~ans)printf("%d\n", ans);
	else puts("impossible");
}

// ++, hzwer's code has been hacked...