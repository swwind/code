#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{
	int t, s;
	bool operator < (const node &b) const {
		return s == b.s ? t > b.t : s > b.s;
	}
};
priority_queue<node>a,b;
int c[N];
int main(int argc, char const *argv[]){
	int n = read(), m1 = read(), m2 = read();
	for(int i = 1, x; i <= m1; i++) x = read(), a.push((node){x, x});
	for(int i = 1; i <= n; i++){
		node x = a.top(); a.pop();
		// printf("{%d, %d}\n", x.t, x.s);
		c[i] = x.s;
		x.s += x.t;
		a.push(x);
	}
	sort(c+1, c+n+1);
	printf("%d ", c[n]);
	for(int i = 1, x; i <= m2; i++) x = read(), b.push((node){x, x});
	int ans = 0;
	for(int i = 1; i <= n; i++){
		node x = b.top(); b.pop();
		// printf("%d -> %d", x.s, x.t);
		ans = max(ans, x.s+c[n-i+1]);
		x.s += x.t;
		// printf(" || %d\n", x.s);
		b.push(x);
	}
	printf("%d\n", ans);
	return 0;
}