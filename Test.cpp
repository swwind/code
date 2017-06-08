#include <bits/stdc++.h>
#define ll long long
#define N 100050
#define MOD 1000000007
using namespace std;
char B[N];
ll nxt[N], cnt[N], ans = 1;
int main(){
	scanf("%s", B+1);
	int n = strlen(B+1);
	for(int i = 2, j = 0; i <= n; i++){
		while(j && B[i] != B[j+1]) j = nxt[j];
		if(B[i] == B[j+1]) j++;
		while(j > i/2)j = nxt[j];
		nxt[i] = j; cnt[j]++;
	}
	for(int i = 1; i <= n; i++)
		(ans *= nxt[i]+1) %= MOD;
	printf("%lld", ans);
	return 0;
}

