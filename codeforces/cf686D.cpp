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
#define N 300005

using namespace std;

int n, f[N], ans[N], son[N], m, fuck;
vector<int> g[N];

void dfs(int x){
	ans[x] = x;
	son[x] = 1;
	for(int i = 0; i < g[x].size(); i++){
		fuck = g[x][i]; dfs(fuck); son[x] += son[fuck];}
	for(int i = 0; i < g[x].size(); i++)
		if(son[g[x][i]] * 2 > son[x])
			ans[x] = ans[g[x][i]];
	while((son[x] - son[ans[x]]) * 2 > son[x])
		ans[x] = f[ans[x]];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; i++) scanf("%d", &f[i]), g[f[i]].push_back(i);
	dfs(1);
	for(int i = 0; i < m; i++) scanf("%d", &fuck), printf("%d\n", ans[fuck]);
	return 0;
}

