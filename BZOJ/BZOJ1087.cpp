#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, dp[10][110][1010], ans;
int cal(int x){
	int ans = 0;
	for(int i = 0; i < 20; i++)
		if(x&(1<<i)) ans++;
	return ans;
}
int pd(int x, int y){
	for(int i = 0; i < 20; i++)
		if(x&(1<<i) && y&(1<<i)) return 0;
	int z = x | y;
	for(int i = 0; i < 20; i++)
		if(z&(1<<i) && z&(1<<(i+1))) return 0;
	return 1;
}
int main(){
	scanf("%d%d", &n, &k);
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k; j++)
			for(int h = 0; h < (1<<n); h++)
				if(j >= cal(h))
					for(int l = 0; l < (1<<n); l++)
						if(pd(l, h))
							dp[i][j][h] += dp[i-1][j-cal(h)][l];
	for(int i = 0; i < (1<<n); i++) ans += dp[n][k][i];
	return printf("%lld", ans)*0;
}
/*
#include<map>  
#include<set>  
#include<cmath>  
#include<queue>  
#include<bitset>  
#include<math.h>  
#include<cstdio>  
#include<vector>  
#include<string>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
const int N=1000010;  
const int MAX=151;  
const int MOD1=1000007;  
const int MOD2=100000009;  
const double EPS=0.00000001;  
typedef long long ll;  
const ll MOD=1000000009;  
const ll INF=10000000010;  
typedef double db;  
typedef unsigned long long ull;  
ll dp[10][110][1010];  
int cal(int x) {  
    int i,ret=0;  
    for (i=0;i<10;i++)  
    if (x&(1<<i)) ret++;  
    return ret;  
}  
int can(int x,int y) {  
    for (int i=0;i<10;i++)  
    if ((x&(1<<i))&&(y&(1<<i))) return 0;  
    int z=x|y;  
    for (int i=0;i<10;i++)  
    if ((z&(1<<i))&&(z&(1<<(i+1)))) return 0;  
    return 1;  
}  
int main()  
{  
    int i,j,h,l,k,n;  
    ll ans=0;  
    scanf("%d%d", &n, &k);  
    memset(dp,0,sizeof(dp));  
    dp[0][0][0]=1;  
    for (i=1;i<=n;i++)  
        for (j=0;j<=k;j++)  
            for (h=0;h<(1<<n);h++)  
            if (j>=cal(h)) {  
                for (l=0;l<(1<<n);l++)  
                if (can(l,h)) dp[i][j][h]+=dp[i-1][j-cal(h)][l];  
            }  
    for (j=0;j<(1<<n);j++) ans+=dp[n][k][j];  
    printf("%lld\n", ans);  
    return 0;  
}  */
