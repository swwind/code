#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
inline int read(){
	int x=0, f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0', ch=getchar();
	return f?x:-x;
}
int n, m;
char a[110][110];
int cnt, vis[110][110];
map<double, int>mp;
map<int, double>num;
double dis;
double get_dis(int x1, int y1, int x2, int y2){
	return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}
struct T{
	int l, r;
}q[100000];
int ff;
void dfs(int x, int y){
	if(vis[x][y])return ;
	if(x < 1 || x > n || y < 1 || y > m || a[x][y] != '1')return ;
	vis[x][y] = 1;
	q[++ff].l = x, q[ff].r = y;
	//cout<<x<<" "<<y<<endl;
	dfs(x-1, y);dfs(x+1, y);dfs(x, y+1);dfs(x, y-1);
	dfs(x-1, y+1);dfs(x-1, y-1);dfs(x+1, y+1);dfs(x+1, y-1);
}
void pre_hand(){
	for(int i = 1; i <= ff; i++)
		for(int j = 1; j <= ff; j++){
			if(i == j) continue;
			dis += get_dis(q[i].l, q[i].r, q[j].l, q[j].r);
		}
}
void change(int x){
	for(int i = 1; i <= ff; i++)
		a[q[i].l][q[i].r] = char(x + 'a'-1);
}
int pd(){
	for(int i = 1; i <= cnt; i++){
		double ans = abs(num[i] - dis);
		if(ans <= 1e-3)return i;
	}
	num[++cnt] = dis;
	return cnt;
}
int main(){
	m = read(), n = read();
	for(int i = 1; i <= n; i++)
		scanf("%s", a[i]+1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == '1' && !vis[i][j]){
				memset(q, 0, sizeof(q));
				dis = 0;ff = 0;
				dfs(i, j);
				pre_hand();
				change(pd());
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}