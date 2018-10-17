#include <bits/stdc++.h>
using namespace std;
int a[4]={0, 1, 0,-1};
int b[4]={1, 0,-1, 0};
int n, nn, mp[10][10], vis[10][10], ans,flag=0;
int ok(int x){
	return x && x <= n;
}
void findfs(int x, int y){
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++)
		if(ok(x+a[i])&&ok(y+b[i])&&mp[x+a[i]][y+b[i]]==mp[x][y]&&!vis[x+a[i]][y+b[i]])
			findfs(x+a[i], y+b[i]);
}
int count(){
	int sum=0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			sum+=vis[i][j];
	return sum;
}
int size(){
	memset(vis, 0, sizeof vis);
	findfs(1, 1);
	return count();
}
int get(){
	memset(vis, 0, sizeof vis);findfs(1,1);
	int sum = 0,a[6]={0,0,0,0,0,0};
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!vis[i][j])a[mp[i][j]]=1;
	for(int i = 0; i < 6; i++) sum+=a[i];
	return sum;
}
void dfs(int dep, int h){
	int g=get();
	if(!g)flag=1;
	if(dep+g>h||flag)return;
	int mmp[10][10], re=mp[1][1];
	memset(vis, 0, sizeof vis);
	int sz = size();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			mmp[i][j] = vis[i][j];
	for(int i = 0; i < 6; i++){
		if(i==re)continue;
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				if(mmp[j][k])mp[j][k]=i;
		memset(vis, 0, sizeof vis);
		if(size()==sz)continue;
		dfs(dep+1, h);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(mmp[i][j])mp[i][j] = re;
}
int main(){
	while(scanf("%d", &n)!=EOF&&(ans=n*n)){
		flag=0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				scanf("%d", &mp[i][j]);
		for(int i = 0; i <= ans&&!flag; i++){
			dfs(0, i);
			if(flag) printf("%d\n", i);
		}
	}
}
