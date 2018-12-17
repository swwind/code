#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	ll x, y, id;
}a[100020], b[100020];
ll cnt1, cnt2;
bool cmp1(node a, node b){
	return a.x < b.x;
}
bool cmp2(node a, node b){
	return a.y > b.y;
}
int main(){
	ll n = read(), z = read();
	for(ll i = 1,x,y; i <= n; i++){
		x = read(); y = read();
		if(x <= y) a[++cnt1] = (node){x, y, i};
		else b[++cnt2] = (node){x, y, i};
	}
	sort(a+1, a+cnt1+1, cmp1);
	sort(b+1, b+cnt2+1, cmp2);
	for(ll i = 1; i <= cnt1; i++){
		if(z <= a[i].x) return puts("NIE")&0;
		z += a[i].y - a[i].x;
	}
	for(ll i = 1; i <= cnt2; i++){
		if(z <= b[i].x) return puts("NIE")&0;
		z += b[i].y - b[i].x;
	}
	puts("TAK");
	for(ll i = 1; i <= cnt1; i++) printf("%lld ", a[i].id);
	for(ll i = 1; i <= cnt2; i++) printf("%lld ", b[i].id);
}