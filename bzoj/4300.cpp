#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int dp[31];
int main(){
	int n = read(), ans = 0;
	for(int i = 1; i <= n; i++){
		int tmp = 0, x = read();
		for(int j = 0; j <= 30; j++)
			if(x>>j&1) tmp = max(tmp, dp[j]+1);
		for(int j = 0; j <= 30; j++)
			if(x>>j&1) dp[j] = tmp;
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
}