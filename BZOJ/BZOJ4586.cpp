#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
priority_queue<ll>ok,no;
ll a[100020];
int main(int argc, char const *argv[]){
	int n = read(), x = read(), y = read(), z = read();
	for(int i = 1; i <= n; i++) a[i] = read()-read();
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > 0){
			for(int j = 1; j <= a[i]; j++)
				if(ok.empty()) ans += y, no.push(i*z+y);
				else{
					int w = -ok.top();
					if(i*z+w < y) ans += i*z+w, ok.pop(), no.push(i*z*2+w);
					else ans += y, no.push(i*z+y);
				}
		}
		else{
			for(int j = 1; j <= -a[i]; j++)
				if(no.empty()) ans += x, ok.push(i*z+x);
				else{
					int w = -no.top();
					if(i*z+w < x) ans += i*z+w, no.pop(), ok.push(i*z*2+w);
					else ans += x, ok.push(i*z+x);
				}
		}
	}
	printf("%lld\n", ans);
	return 0;
}