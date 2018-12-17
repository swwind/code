#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
char ch[50];
map<string, int>id;
string str;
bool mp[120][120];
int f[120][120];
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++){
		cin >> str;
		id[str] = i;
	}
	for(int i = 1; i <= m; i++){
		cin >> str; int x = id[str];
		cin >> str; int y = id[str];
		mp[x][y] = mp[y][x] = 1;
	}
	f[1][1] = 1;
	for(int i = 1; i < n; i++)
		for(int j = i+1; j <= n; j++)
			for(int k = 1; k < j; k++)
				if(mp[j][k] && f[i][k] && f[i][k]+1 > f[i][j])
					f[j][i] = f[i][j] = f[i][k]+1;
	int ans = 1;
	for(int i = 1; i <= n; i++)
		if(mp[i][n]) ans = max(ans, f[i][n]);
	printf("%d\n", ans);
	return 0;
}
