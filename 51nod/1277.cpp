#include <bits/stdc++.h>
#define ll long long
#define N 100050
using namespace std;
char B[N];
ll nxt[N], cnt[N], ans;
int main(){
	scanf("%s", B+1);
	int n = strlen(B+1);
	for(int i = 2, j = 0; i <= n; i++){
		while(j && B[i] != B[j+1]) j = nxt[j];
		if(B[i] == B[j+1]) j++; nxt[i] = j; cnt[j]++;
	}
	for(int i = n; i; i--){
		ans = max(ans, (ll)i*cnt[i]+i);
		cnt[nxt[i]] += cnt[i];
	}
	printf("%lld", ans);
	return 0;
}

