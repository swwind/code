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
struct edge{
	int lp, rp, len, ren, val;
	bool ls[120], rs[120];
}e[120];
int cnt, dis[120][120], mp[120][120];
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++){
		int x = read();
		e[x].val = read();
		e[x].len = read();
		e[x].ren = read();
		for(int i = 1, flag = 0; i <= e[x].len; i++){
			int y = read(); e[x].ls[y] = 1;
			if(!flag && e[y].len || e[y].ren)
				if(e[y].ls[x]) flag = e[x].lp = e[y].lp;
				else flag = e[x].lp = e[y].rp;
		}
		if(!e[x].lp) e[x].lp = ++cnt;
		for(int i = 1, flag = 0; i <= e[x].ren; i++){
			int y = read(); e[x].rs[y] = 1;
			if(!flag && e[y].len || e[y].ren)
				if(e[y].ls[x]) flag = e[x].rp = e[y].lp;
				else flag = e[x].rp = e[y].rp;
		}
		if(!e[x].rp) e[x].rp = ++cnt;
	}
	memset(mp, 63, sizeof mp);
	memset(dis, 63, sizeof dis);
	// for(int i = 1; i <= n; i++) mp[i][i] = 0;
	for(int i = 1; i <= n; i++)
		dis[e[i].lp][e[i].rp] = dis[e[i].rp][e[i].lp] =
		mp[e[i].lp][e[i].rp] = mp[e[i].rp][e[i].lp] = e[i].val;
	int ans = 1<<30;
	for(int k = 1; k <= cnt; k++){
		for(int i = 1; i < k; i++)
			for(int j = 1; j < i; j++)
				ans = min(0ll+ans, 0ll+dis[i][j]+mp[i][k]+mp[k][j]);
		for(int i = 1; i <= cnt; i++)
			for(int j = 1; j <= cnt; j++)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	}
	printf("%d\n", ans);
	return 0;
}