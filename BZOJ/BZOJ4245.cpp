#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[500020], ans;
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = a[i-1]^read();
	for(int k = 63; ~k; k--){
		if(a[n]>>k&1){
			ans |= 1ll<<k;
			continue;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] >= 0 && ~a[i]>>k&1) cnt++;
		if(cnt >= m) for(int i = 1; i <= n; i++)
			if(a[i] >= 0 && a[i]>>k&1) a[i] = -a[i]; else;
		else ans |= 1ll<<k;
	}
	printf("%lld\n", ans);
	return 0;
}