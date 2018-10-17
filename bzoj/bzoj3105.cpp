#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){ch=='-'&&(f=1);ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[120], b[50];
ll sum, ans;
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++) sum += a[i] = read();
	sort(a+1, a+n+1); reverse(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		int t = a[i];
		for(int j = 31; ~j; j--) if(a[i]>>j&1)
			if(!b[j]){b[j] = i; break;}
			else a[i] ^= a[b[j]];
		if(a[i]) ans += t;
	}
	printf("%lld\n", sum == ans ? -1ll : sum-ans);
	return 0;
}