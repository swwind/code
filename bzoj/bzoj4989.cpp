#include <bits/stdc++.h>
#define N 100020
#define int long long
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int c[N], n;
int ask(int x){
	int ans = 0;
	for(;x<=n;x+=x&-x)ans+=c[x];
	return ans;
}
void add(int x, int y){
	for(;x;x^=x&-x)c[x]+=y;
}
int c_[N];
int ask_(int x){
	int ans = 0;
	for(;x;x^=x&-x)ans+=c_[x];
	return ans;
}
void add_(int x, int y){
	for(;x<=n;x+=x&-x)c_[x]+=y;
}
int a[N], b[N], ans, a_[N], b_[N];
signed main(){
	n = read();
	for(int i = 1; i <= n; i++) a_[i] = read();
	for(int i = 1; i <= n; i++) b_[i] = read();
	for(int i = 1; i <= n; i++) a[a_[i]] = i;
	for(int i = 1; i <= n; i++) b[i] = a[b_[i]];
	for(int i = 1; i <= n; i++){
		int x = ask(b[i]); add(b[i], 1);
		ans += x; add_(b[i], x); add_(b[i]+1, -x);
	}
	int sum = ans;
	for(int i = n; i; i--){
		int x = ask_(b[i]); add_(b[i], -x); add_(b[i]+1, x);
		add_(1, 1); add_(b[i], -1); sum = min(sum, ans += b[i]-1-x);
	}
	ans = 0;
	memset(c, 0, sizeof(int)*N);
	memset(c_, 0, sizeof(int)*N);
	for(int i = 1; i <= n; i++) a[b_[i]] = i;
	for(int i = 1; i <= n; i++) b[i] = a[a_[i]];
	for(int i = 1; i <= n; i++){
		int x = ask(b[i]); add(b[i], 1);
		ans += x; add_(b[i], x); add_(b[i]+1, -x);
	}
	sum = min(sum, ans);
	for(int i = n; i; i--){
		int x = ask_(b[i]); add_(b[i], -x); add_(b[i]+1, x);
		add_(1, 1); add_(b[i], -1); sum = min(sum, ans += b[i]-1-x);
	}


	printf("%lld\n", sum);
	return 0;
}