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
//                    佛祖保佑       永无BUG             (然并卵)//
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

char ch[2];
int last_move, n, ans, mov[6][2], mp[3][35];

void print(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j <= mp[i][0]; j++)
			cout << mp[i][j] << " ";
		cout << "\n";
	}
}
int check(){
	int flagb = 1, flagc = 1, kkk = n, kkc = n;
	if(mp[1][0] != n) flagb = 0; else for(int i = 1; i <= mp[1][0]; i++) if(mp[1][i] != kkk--) flagb = 0;
	if(mp[2][0] != n) flagc = 0; else for(int i = 1; i <= mp[2][0]; i++) if(mp[2][i] != kkc--) flagc = 0;
	return flagb || flagc;
}

int canMove(int a){
	if(mp[mov[a][0]][mp[mov[a][0]][0]] == last_move) return 0;
	int len[3]; for(int i = 0; i < 3; i++) len[i] = mp[i][0], mp[i][0] = n + 1;
	int res = mp[mov[a][0]][len[mov[a][0]]] < mp[mov[a][1]][len[mov[a][1]]];
	for(int i = 0; i < 3; i++) mp[i][0] = len[i];
	return res;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < 6; i++)
		scanf("%s", ch), mov[i][0] = ch[0] - 'A', mov[i][1] = ch[1] - 'A';
	for(int i = n; i; i--) mp[0][++mp[0][0]] = i;
	while(!check())
		for(int i = 0; i < 6; i++)
			if(canMove(i)){
			//	cout << "Put " << mov[i][0] << " To " << mov[i][1] << " last = " << last_move << endl;
			//	print();
				mp[mov[i][1]][++mp[mov[i][1]][0]] = mp[mov[i][0]][mp[mov[i][0]][0]];
				mp[mov[i][0]][0]--;
				last_move = mp[mov[i][1]][mp[mov[i][1]][0]];
				ans++;
				break;
			}
	printf("%d", ans);
	return 0;
}

