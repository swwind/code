#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[N], sum[N], st[N], top, ans;
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	while(m--){
		ll k = read();
		for(int i = 1; i <= n; i++)
			sum[i] = sum[i-1]+a[i]-k;
		st[top=1] = ans = 0;
		for(int i = 1; i <= n; i++)
			if(sum[i] < sum[st[top]]) st[++top] = i;
		for(int i = n; ~i; i--){
			while(top && sum[i] >= sum[st[top]]) top--;
			ans = max(ans, i-st[top+1]);
		}
		printf(m ? "%lld " : "%lld", ans);
	}
	puts("");
	return 0;
}