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
#define rep(a, b) for(int a = 1; a <= b; a ++)
#define MOD 1000000007

using namespace std;

int wall[60][60][4], vis[60][60], p[3000], m, n, k, tot, maxn, ai, aj, aw; 
int y[4] = {0, 1, 0, -1}, x[4] = {-1, 0, 1, 0};
char c[4] = {'N', 'E', 'S', 'W'};

void dfs(int i, int j){
	//printf("Run: %d %d %d", i, j, tot);
	vis[i][j] = tot;
	p[tot]++;
	for(int w = 0; w < 4; w++)
		if(!vis[i+x[w]][j+y[w]] && !wall[i][j][w])
			dfs(i+x[w], j+y[w]);
}

int bigger(int a, int b){
	if(a == 1 || a == 3) return 0;
	else if(b == 1 || b == 3) return 1;
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	rep(i, m) rep(j, n){
		scanf("%d", &k);
		if(k >= 8) wall[i][j][2] = 1, k -= 8;
		if(k >= 4) wall[i][j][1] = 1, k -= 4;
		if(k >= 2) wall[i][j][0] = 1, k -= 2;
		if(k) wall[i][j][3] = 1;
	}
	//rep(i, m) rep(j, n) rep(k, 4) if(wall[i][j][k-1]) printf("%d %d %d\n", i, j, k-1);
	rep(i, m) rep(j, n)
		if(!vis[i][j]) tot++, dfs(i, j);
	printf("%d\n", tot);
	for(int i = 1; i <= tot; i++)
		maxn = max(maxn, p[i]);
	printf("%d\n", maxn);
	rep(i, m) rep(j, n) for(int w = 0; w < 4; w++)
		if(wall[i][j][w] && vis[i][j] != vis[i+x[w]][j+y[w]])
			if(p[vis[i][j]] + p[vis[i+x[w]][j+y[w]]] > maxn)
				maxn = p[vis[i][j]] + p[vis[i+x[w]][j+y[w]]],
				ai = i, aj = j, aw = w;
			else if(p[vis[i][j]] + p[vis[i+x[w]][j+y[w]]] == maxn)
				if(j < aj) ai = i, aj = j, aw = w;
				else if(j == aj && i > ai) ai = i, aw = w;
				else if(j == aj && i == ai && bigger(w, aw)) aw = w;
	printf("%d\n", maxn);
	if(aw == 3) aj--, aw = 1;
	if(aw == 2) ai++, aw = 0; 
	printf("%d %d %c", ai, aj, c[aw]);
	return 0;
}
