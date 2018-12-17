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
#define N 200005

using namespace std;

int bg, ed, h, xx[4] = {0, 0, 1, -1}, yy[4] = {1, -1, 0, 0}, t, w;
bool ans[5][5], mark[65536];
char ch[5];
struct data{
	bool a[5][5];
	int step;
} q[65536];

int hash(bool a[5][5]){
	int k = 1, s = 0;
	for(int i = 1; i <= 4; i++)
		for(int j = 1; j <= 4; j++)
			s += k * a[i][j], k <<= 1;
	return s;
}
void bfs(){
	int t = 0, w = 1;
	bg = hash(q[t].a);
	ed = hash(ans);
	if(bg == ed){
		printf("0");
		return;
	}
	mark[bg] = 1;
	int x, y;
	while(t < w){
		for(int i = 1; i <= 4; i++) for(int j = 1; j <= 4; j++)
				if(q[t].a[i][j]) for(int k = 0; k < 4; k++){
			x = i + xx[k], y = j + yy[k];
			if(q[t].a[x][y] || x > 4 || y > 4 || x < 1 || y < 1)
				continue;
			swap(q[t].a[i][j], q[t].a[x][y]);
			h = hash(q[t].a);
			if(!mark[h]){
				if(h == ed){
					printf("%d", q[t].step + 1);
					return;
				}
				mark[h] = 1;
				memcpy(q[w].a, q[t].a, sizeof q[w].a);
				q[w++].step = q[t].step + 1;
			}
			swap(q[t].a[i][j], q[t].a[x][y]);
		}
		t++;
	}
}
int main(){
	for(int i = 1; i <= 4; i++){
		scanf("%s", ch);
		for(int j = 1; j <= 4; j++)
			q[0].a[i][j] = ch[j-1] - '0';
	}
	for(int i = 1; i <= 4; i++){
		scanf("%s", ch);
		for(int j = 1; j <= 4; j++)
			ans[i][j] = ch[j-1] - '0';
	}
	bfs();
	return 0;
}

