#include <bits/stdc++.h>
#define N 50
#define inf (1ll<<60)
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N*N<<2], nxt[N*N<<2], head[N*N], cnt;
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
int mp[N][N];
int px[] = {0, 1, 0, -1};
int py[] = {1, 0, -1, 0};
bool vis[N*N], ret[N*N];
int chw[N*N], match[N*N], ans[N*N], sx, sy;
char ch[N];
bool find(int x, int f){
	if(!vis[x]) return false;
	for(int i = head[x]; i; i = nxt[i])
		if(chw[to[i]] != f && vis[to[i]]){
			chw[to[i]] = f;
			if(!match[to[i]] || find(match[to[i]], f)){
				match[to[i]] = x; match[x] = to[i];
				return true;
			}
		}
	return false;
}
int main(){
	int n = read(), m = read(), nm = n*m;
	for(int i = 1; i <= n; i++){
		scanf("%s", ch+1);
		for(int j = 1; j <= m; j++)
			if(ch[j] == 'X') mp[i][j] = 0;
			else if(ch[j] == 'O') mp[i][j] = 1;
			else mp[sx=i][sy=j] = 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 0; k < 4; k++){
				int x = i+px[k], y = j+py[k];
				if(!x || x > n || !y || y > m) continue;
				if(mp[i][j] == mp[x][y]) continue;
				ins((i-1)*m+j, (x-1)*m+y);
			}
	int faq = 0;
	memset(vis, 1, sizeof(bool)*N*N);
	for(int i = 1; i <= nm; i++)
		if(!match[i]) find(i, ++faq);
	int q = read()<<1;
	for(int i = 1; i <= q; i++){
		vis[(sx-1)*m+sy] = 0;
		if(match[(sx-1)*m+sy]){
			int it = match[(sx-1)*m+sy];
			match[it] = match[(sx-1)*m+sy] = 0;
			ret[i] = !find(it, ++faq);
		} else ret[i] = 0;
		sx = read(), sy = read();
	}
	for(int i = 1; i <= q; i+=2)
		if(ret[i] && ret[i+1]) ans[++ans[0]] = i+1>>1;
	printf("%d\n", ans[0]);
	for(int i = 1; i <= ans[0]; i++)
		printf("%d\n", ans[i]);
	return 0;
}