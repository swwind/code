#include <bits/stdc++.h>
#define ll long long
#define read(a) scanf("%d", &a)
#define write(a) printf("%d\n", a);
using namespace std;
int ans[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1},
	{0, 0, 1, 1, 1, 1},
	{0, 0, 0, 2, 1, 1},
	{0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0}};
int mp[6][6], k;
int sx[8] = {1, 1,-1,-1, 2, 2,-2,-2};
int sy[8] = {2,-2, 2,-2, 1,-1, 1,-1};
int ok(){
	for(int i = 1; i <= 5; i++)
	for(int j = 1; j <= 5; j++)
	if(ans[i][j] != mp[i][j]) return 0;
	return 1;
}
int get(){
	int sum = 0;
	for(int i = 1; i <= 5; i++)
	for(int j = 1; j <= 5; j++)
	sum += ans[i][j] != mp[i][j];
	return sum;
}
int dfs(int step, int x, int y){
	if(step == k) return ok();
	for(int i = 0; i < 8; i++){
		int xx = x+sx[i], yy = y+sy[i];
		if(xx>5||xx<1||yy>5||yy<1)continue;
		swap(mp[xx][yy], mp[x][y]);
		if(get()+step <= k)if(dfs(step+1, xx, yy))return 1;
		swap(mp[xx][yy], mp[x][y]);
	}
	return 0;
}
int main(){
	int T, x, y; read(T);
	while(T--){
		char ch;
		for(int i = 1; i <= 5; i++)for(int j = 1; j <= 5; j++){
			ch=getchar();
			while(ch!='0'&&ch!='1'&&ch!='*')ch=getchar();
			if(ch == '*') mp[x=i][y=j] = 2;
			else mp[i][j] = ch-'0';
		}
		int flag = 0;
		for(k = 1; k <= 15; k++)
			if(dfs(0, x, y)){
				write(k);
				flag = 1;
				break;
			}
		if(!flag) puts("-1");
	}
}