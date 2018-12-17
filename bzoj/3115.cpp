#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
ll c[2][N], a[N];
ll ask(int t, int x){
	ll ans = 0;
	for(;x;x^=x&-x)ans+=c[t][x];
	return ans;
}
void add(int t, int x, ll val){
	for(;x<N;x+=x&-x)c[t][x]+=val;
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		add(0, i, a[i]);
		add(1, i, (ll)a[i]*(n-i+1));
	}
	char str[20];
	while(m--){
		scanf("%s", str);
		if(str[0] == 'Q'){
			int x = read();
			printf("%lld\n", ask(1, x)-ask(0, x)*(n-x));
		}
		else{
			int x = read(), y = read();
			add(0, x, y-a[x]);
			add(1, x, (ll)(n-x+1)*(y-a[x]));
			a[x] = y;
		}
	}
	return 0;
}