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
#define write(a) printf("%d ", a)
#define writeln(a) printf("%d\n", a)
#define obs(a) a&1
#define mst(a, b) memset(a, b, sizeof a)
#define rep(a, b, c) for(int a = b; a < c; a ++)
#define MOD 1000000007

using namespace std;
int n,m,cnt,tot,ans=1,sum;
int fa[105];
struct edge{int x,y,v;bool operator<(const edge B)const{return v<B.v;}}e[1005];
struct data{int l,r,v;}a[1005];
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0', ch=getchar();
	return x;
}

int find(int x){
	return x == fa[x] ? x : find(fa[x]);
}

void dfs(int x, int now, int k){
	if(now == a[x].r + 1){
		if(k == a[x].v) sum++;
		return;
	}
	int p = find(e[now].x), q = find(e[now].y);
	if(p != q)
		fa[p] = q,
		dfs(x, now + 1, k + 1),
		fa[p] = p, fa[q] = q;
	dfs(x, now + 1, k);
}

int main(){
	n = read(); m = read();
	for(int i = 1; i <= n; i++)
	fa[i] = i;
	for(int i = 1; i <= m; i++)
		e[i].x = read(), e[i].y = read(), e[i].v = read();
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; i++){
		if(e[i].v != e[i-1].v)
			a[++cnt].l = i,
			a[cnt-1].r = i - 1;
		int p = find(e[i].x), q = find(e[i].y);
		if(p != q)
			fa[p] = q,
			a[cnt].v++,
			tot++;
	}
	a[cnt].r = m;
	if(tot != n - 1){
		printf("0");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= cnt; i++){
		sum = 0;
		dfs(i, a[i].l, 0);
		ans = (ans * sum) % MOD;
		for(int j = a[i].l; j <= a[i].r; j++){
			int p = find(e[j].x), q = find(e[j].y);
			if(p != q)
				fa[p] = q;
		}
	}
	printf("%d", ans);
	return 0;
}
