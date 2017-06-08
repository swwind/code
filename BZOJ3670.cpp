#include <bits/stdc++.h>
#define ll long long
#define N 1000050
#define MOD 1000000007
using namespace std;
char B[N]; ll ans;
int T, nxt[N], cnt[N];
int main(){
	scanf("%d", &T);
	while(T--){
		ans = cnt[1] = 1;
		scanf("%s", B+1);
		int n = strlen(B+1);
		for(int i = 2, j = 0; i <= n; i++){
			while(j && B[i] != B[j+1]) j = nxt[j];
			if(B[i] == B[j+1]) j++; nxt[i] = j; cnt[i] = cnt[j]+1;
		}
		for(int i = 2, j = 0; i <= n; i++){
			while(j && B[i] != B[j+1]) j = nxt[j];
			if(B[i] == B[j+1]) j++;
			while(j*2 > i) j = nxt[j];
			ans *= cnt[j] + 1;
			ans %= MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

