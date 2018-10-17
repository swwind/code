#include <bits/stdc++.h>
#define N 320
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
	int T = read();
	while(T--){
		int n = read(), m = read(), ans = 1;
		memset(mp, 0, sizeof mp);
		for(int i = 1, x, y; i <= m; i++){
			x = read()+1; y = read()+1;
			mp[x][y] = 1;
		}
		for(int i = 1; i <= n && ans; i++)
			for(int j = 1, f1 = 0, f2 = 0; j <= n && ans; j++, f1=f2=0)
				for(int k = 1; k <= n && ans; k++){
					if(mp[i][k] && mp[j][k]) f1 = 1;
					if(mp[i][k] != mp[j][k]) f2 = 1;
					if(f1 && f2) ans = 0;
				}
		puts(ans?"Yes":"No"); // mikoto
	}
	return 0;
}