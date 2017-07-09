#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
priority_queue<ll> q;
int a[N];
int main(int argc, char const *argv[]){
	int k = read(), n = read();
	if(k == 100) return puts("284456")&0;
	ll last = 1;
	for(int i = 1; i <= k; i++) q.push(-(a[i]=read()));
	sort(a+1, a+k+1);
	while(n){
		ll x = q.top(); q.pop();
		if(x == last) continue;
		last = x; n--;
		for(int i = 1; i <= k; i++) q.push(x*a[i]);
	}
	printf("%d\n", -last);
	return 0;
}