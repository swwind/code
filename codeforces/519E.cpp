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
//                    ·ð×æ±£ÓÓ       ÓÀÎÞBUG                     //
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
#define inf 0x7fffffff
#define ESP 1e-9
#define read(a) scanf("%d", &a)
#define write(a) printf("%d ", a)
#define writeln(a) printf("%d\n", a)
#define obs(a) a&1
#define mst(a, b) memset(a, b, sizeof a)
#define rep(a, b, c) for(int a = b; a < c; a ++)
#define N 100005

using namespace std;

int n, m, x, y, tot, point[N], nxt[2*N], v[2*N];
int f[N][20], h[N], size[N];
struct Fuck{
	int pre, pt;
};
void insert(int x, int y){
	nxt[++tot] = point[x]; point[x] = tot; v[tot] = y;
	nxt[++tot] = point[y]; point[y] = tot; v[tot] = x;
}
void build(int x, int fa, int dep){
	h[x] = dep; size[x] = 1;
	for(int i = 1; i < 18 && h[x]-(1<<i) >= 1; i++)
		f[x][i] = f[f[x][i-1]][i-1];
	for(int i = point[x]; i; i = nxt[i])
		if(v[i] != fa)
			f[v[i]][0] = x,
			build(v[i], x, dep + 1),
			size[x] += size[v[i]];
}
int lca(int x, int y){
	if(h[x] < h[y]) swap(x, y);
	int k = h[x] - h[y];
	for(int i = 0; i < 18; i++)
		if(k&(1<<i)) x = f[x][i];
	for(int i = 18; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return x == y ? x : f[x][0];
}
Fuck find(int x, int high){
	int xx = x;
	for(int i = 18; i >= 0; i--)
		while(h[f[x][i]] > high)
			xx = x, x = f[x][i];
	return (Fuck){x, f[x][0]};
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
		scanf("%d%d", &x, &y),
		insert(x, y);
	build(1, 0, 1), scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		if(h[x] < h[y]) swap(x, y);
		if(x == y){
			printf("%d\n", n);
			continue;
		}
		int r = lca(x, y), len = h[x] - 2 * h[r] + h[y];
		if(len&1){
			puts("0");
			continue;
		}
		len >>= 1;
		int high = h[x] - len;
		if(high == h[r])
			printf("%d\n", n - size[find(x, high).pre] - size[find(y, high).pre]);
		else{
			Fuck c = find(x, high);
			printf("%d\n", size[c.pt] - size[c.pre]);
		}
	}
	return 0;
}

















