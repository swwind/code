#include <bits/stdc++.h>
#define N 5007
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int mp[N][N];
int main(){
	int n = read(), a = read(), ans = 0;
	for(int i = 1, x, y; i <= n; i++){
		x = read(); y = read();
		mp[x+1][y+1] = read();
	}
	for(int i = 1; i <= 5000; i++)
		for(int j = 1; j <= 5000; j++)
			mp[i][j] = mp[i][j]+mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
	for(int i = 0; i <= 5000-a; i++)
		for(int j = 0; j <= 5000-a; j++)
			ans = max(ans, mp[i][j]-mp[i+a][j]-mp[i][j+a]+mp[i+a][j+a]);
	printf("%d\n", ans);
	return 0;
}