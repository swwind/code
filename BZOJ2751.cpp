#include <bits/stdc++.h>
#define ll long long
#define zyy 1000000007
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct data{
	int pos, val;
	friend bool operator < (data a, data b){
		if(a.pos == b.pos) return a.val < b.val;
		return a.pos < b.pos;
	}
}a[100005];
int POW(ll a, ll b){
	ll ans = 1;
	for(int i = b; i; i/=2, a=a*a%zyy)
		if(i&1) ans = ans*a%zyy;
	return ans;
}
int main(){
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= k; i++)
		a[i].pos = read(), a[i].val = read();
	sort(a+1, a+k+1);
	int tot = m;
	int sum = (ll)n*(n+1)/2%zyy, tmp = sum;
	ll ans = 1;
	for(int i = 1; i <= k; i++){
		if(a[i].pos != a[i-1].pos && i > 1)
		   ans = ans*tmp%zyy, tmp = sum, tot--;
		if(a[i].pos != a[i-1].pos || a[i].val != a[i-1].val){
			tmp -= a[i].val;
			if(tmp < 0) tmp += zyy;
		}
	}
	ans = ans*tmp%zyy;
	printf("%lld\n", ans*POW(sum, tot-1)%zyy);
	return 0;
}