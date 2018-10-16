#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t[15], n, m;
struct node{
	ll a[10];
	void print(){
		for(int i = 0; i < 9; i++) printf("%lld ", a[i]);
		printf("%lld\n", a[9]);
	}
	node operator + (const node &b) const {
		node c;
		for(int i = 0; i < 10; i++)
			c.a[i] = a[i] + b.a[i];
		return c;
	}
	node operator - (const node &b) const {
		node c;
		for(int i = 0; i < 10; i++)
			c.a[i] = a[i] - b.a[i];
		return c;
	}
}f[25][10];
node get(ll x){
	node ans;
	for(int i = 0; i < 10; i++) ans.a[i] = 0;
	if(!x){
		ans.a[0]++;
		return ans;
	}
	int len = 12;
	while(t[len] > x) len--;
	for(int i = 1; i < len; i++)
		for(int j = 1; j < 10; j++)
			ans = ans + f[i][j];
	ans.a[0]++;
	int cur = x / t[len];
	for(int i = 1; i < cur; i++)
		ans = ans + f[len][i];
	x %= t[len];
	ans.a[cur] += x+1;
	for(int i = len - 1; i; i--){
		cur = x / t[i];
		for(int j = 0; j < cur; j++)
			ans = ans + f[i][j];
		x %= t[i];
		ans.a[cur] += x+1;
	}
	return ans;
}
int main(){
	t[1] = 1;
	for(int i = 2; i < 15; i++) t[i] = t[i-1]*10;
	for(int i = 0; i < 10; i++) f[1][i].a[i] = 1;
	for(int i = 2; i < 15; i++) for(int j = 0; j < 10; j++)
	for(int k = 0; k < 10; k++) f[i][k] = f[i][k] + f[i-1][j],
	f[i][k].a[k] += t[i-1];
	scanf("%lld%lld", &n, &m);
	(get(m) - get(n-1)).print();
	return 0;
}

