#include <bits/stdc++.h>
#define N 150020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int mp[50][50], sum[2];
int main(){
	int T = read();
	while(T--){
		int n = read(), m = read();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				sum[i&1^j&1] += mp[i][j] = read();
		if(sum[0] == sum[1]) 
	}
	return 0;
}
