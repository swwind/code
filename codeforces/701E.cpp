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
#define M 35
using namespace std;

ll f[N][M], mn[N][M], n, k, sum[N][M];

int main(){
	scanf("%I64d%I64d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &f[i][0]);
	for(int i = 0; i < n; i++) scanf("%d", &mn[i][0]), sum[i][0] = mn[i][0];
	for(int i = 1; i < M; i++) for(int j = 0; j < n; j++)
		f[j][i] = f[f[j][i-1]][i-1],
		sum[j][i] = sum[f[j][i-1]][i-1] + sum[j][i-1],
		mn[j][i] = min(mn[f[j][i-1]][i-1], mn[j][i-1]);
	ll ans;
	for(int i = 0; i < n; i++){
		ll v = i, mins = inf;
		ans = 0LL;
		for(int j = M - 1; j >= 0; j--){
			ll x = 1; x <<= j;
			if(k & x)
				ans += sum[v][j],
				mins = min(mins, mn[v][j]),
				v = f[v][j];
		}
		printf("%I64d %I64d\n", ans, mins);
	}
	return 0;
}

