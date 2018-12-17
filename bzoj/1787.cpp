///////////////////////////////////////////////////////////////////
//                            _ooOoo_                            //
//                           o8888888o                           //
//                           88" . "88                           //
//                           (| ^_^ |)                           //
//                           O\  =  /O                           //
//                        ____/`---'\____                        //
//                      .'  \\|     |//  `.                      //
//                     /  \\|||  :  |||//  \                     //
//                    /  _||||| -:- |||||-  \                    //
//                    |   | \\\  -  /// |   |                    //
//                    | \_|  ''\---/''  |   |                    //
//                    \  .-\__  `-`  ___/-. /                    //
//                  ___`. .'  /--.--\  `. . ___                  //
//               ."" '<  `.___\_<|>_/___.'  >'"".                //
//              | | :  `- \`.;`\ _ /`;.`/ - ` : | |              //
//              \  \ `-.   \_ __\ /__ _/   .-` /  /              //
//       ========`-.____`-.___\_____/___.-`____.-'========       //
//                            `=---='                            //
//       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^       //
//                    佛祖保佑       永无BUG                     //
///////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h> 
#include <queue>
#include <cmath>
#include <math.h>
#include <vector>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <set>
#include <map>
#include <fstream>
#include <bits/stdc++.h>
#define ll long long
#define oo 1<<30
#define ESP 1e-9
#define read(a) scanf("%d", &a)
#define write(a) printf("%d ", a)
#define writeln(a) printf("%d\n", a)
#define obs(a) a&1
#define mst(a, b) memset(a, b, sizeof a)
#define rep(a, b, c) for(int a = b; a < c; a ++)
#define MOD 1000000007

using namespace std;

const int maxn = 500006, inf = 0x7fffffff;
struct FuckYourSister{
	int to, next;
} e[2*maxn];
int n, cnt, x, y, z, m, k, t, head[maxn], dep[maxn], f[maxn][20], vis[maxn];
void insert(int a, int b){
	e[++cnt].to = a;e[cnt].next = head[b];head[b] = cnt;
}
void dfs(int x){
	vis[x] = 1;
	for(int i = 1; i <= 18 && dep[x]>=(1<<i); i++) 
		f[x][i] = f[f[x][i-1]][i-1];//初始化x的爸爸
	for(int i = head[x]; i; i = e[i].next){
		if(vis[e[i].to])continue;
		dep[e[i].to] = dep[x] + 1;
		f[e[i].to][0] = x;
		dfs(e[i].to);
	}
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	int t = dep[x] - dep[y];
	for(int i = 0; i <= 18; i++)
		if(t&(1<<i)) x=f[x][i];
	for(int i = 18; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x=f[x][i], y=f[y][i];
	return x == y ? x : f[x][0];
}
void solve(int a, int b, int c){
	int p1 = lca(a, b), p2 = lca(b, c), p3 = lca(a, c);
	int ans = inf, tmp, t;
	int q1 = lca(p1, c), q2 = lca(p2, a), q3 = lca(p3, b);
	tmp = dep[a] + dep[b] + dep[c] - dep[p1] - 2 * dep[q1];
	if(tmp < ans) ans = tmp, t = p1;
	tmp = dep[a] + dep[b] + dep[c] - dep[p2] - 2 * dep[q2];
	if(tmp < ans) ans = tmp, t = p2;
	tmp = dep[a] + dep[b] + dep[c] - dep[p3] - 2 * dep[q3];
	if(tmp < ans) ans = tmp, t = p3;
	printf("%d %d\n", t, ans);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i++)
		scanf("%d%d", &x, &y),
		insert(x, y), insert(y, x);
	dfs(1);
	for(int i = 0; i < m; i++)
		scanf("%d%d%d", &x, &y, &z),
		solve(x, y, z);
	return 0;
}
