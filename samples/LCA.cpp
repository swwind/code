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
#define oo 1<<30
#define ESP 1e-9
#define read(a) scanf("%d", &a)
#define write(a) printf("%d ", a)
#define writeln(a) printf("%d\n", a)
#define obs(a) a&1
#define mst(a, b) memset(a, b, sizeof a)
#define rep(a, b, c) for(int a = b; a < c; a ++)
#define N 233333

using namespace std;

struct Bilibili{
	int to, next;
} e[N];
int vis[N], f[N][20], m, x, y, z, head[N], dep[N], cnt, n;

void insert(int a, int b){
	e[++cnt].to = a;
	e[cnt].next = head[b];
	head[b] = cnt;
}

void dfs(int x){
	vis[x] = 1;
	for(int i = 1; i <= 18 && dep[x]>=(1<<i); i++)
		f[x][i] = f[f[x][i-1]][i-1];
	for(int i = head[x]; i; i = e[i].next){
		if(vis[e[i].to]) continue;
		dep[e[i].to] = dep[x] + 1;
		f[e[i].to][0] = x;
		dfs(e[i].to);
	}
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	int t = dep[x] - dep[y];
	for(int i = 0; i <= 18; i++)
		if(t&(1<<i)) x = f[x][i];
	for(int i = 18; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return x == y ? x : f[x][0];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i++)
		scanf("%d%d", &x, &y),
		insert(x, y), insert(y, x);
	puts("Read Done.");
	dfs(1);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
} 
/***********************************************
Input:
12 1

1 2
1 3
1 4
2 5
2 6
5 10
5 11
3 7
3 8
7 9
7 12

5 6
9 12

Output:
2
7

***********************************************/

