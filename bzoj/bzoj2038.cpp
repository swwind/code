#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, fuck[50002], c[50002];
ll s[50002], ans;
struct node{
	int l, r, id;
	ll a, b;
}a[50002];
ll gcd(ll a, ll b){
   return a%b ? gcd(b, a%b) : b;
}
ll sqr(ll a){
	return a*a;
}
int cmp(node a, node b){
	return fuck[a.l] == fuck[b.l] ? a.r < b.r : a.l < b.l;
}
int recmp(node a, node b){
	return a.id < b.id;
}
void update(int x, int add){
	ans -= sqr(s[c[x]]);
	s[c[x]] += add;
	ans += sqr(s[c[x]]);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", c+i);
	int g = (int)sqrt(n);
	for(int i = 1; i <= n; i++)
		fuck[i] = (i-1)/g + 1;
	for(int i = 1; i <= m; i++)
		scanf("%d%d", &a[i].l, &a[i].r),
		a[i].id = i;
	sort(a+1, a+m+1, cmp);
	for(int i = 1, l = 1, r = 0; i <= m; i++){
		for(;r<a[i].r;r++)update(r+1,1);
		for(;r>a[i].r;r--)update(r,-1);
		for(;l<a[i].l;l++)update(l,-1);
		for(;l>a[i].l;l--)update(l-1,1);
		if(a[i].l == a[i].r){
			a[i].a = 0, a[i].b = 1;
			continue;
		}
		a[i].a = ans - a[i].r + a[i].l - 1;
		a[i].b = (ll)(a[i].r-a[i].l+1)*(a[i].r-a[i].l);
		ll k = gcd(a[i].a, a[i].b);
		a[i].a/=k;
		a[i].b/=k;
	}
	sort(a+1, a+m+1, recmp);
	for(int i = 1; i <= m; i++)
		printf("%lld/%lld\n", a[i].a, a[i].b);
	return 0;
}

