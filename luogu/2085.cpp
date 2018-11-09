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
	int i, x, v;
	friend bool operator < (const node &a, const node &b) {
		return a.v > b.v;
	}
};
priority_queue<node>q;
int a[N], b[N], c[N];
inline int calc(int i, int x) {
	return a[i]*x*x+b[i]*x+c[i];
}
int main(int argc, char const *argv[]){
	int n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = read();
		c[i] = read();
		q.push((node){i, 1, calc(i, 1)});
	}
	for (int i = 1; i <= m; i++) {
		node k = q.top(); q.pop();
		printf("%d ", k.v);
		k.v = calc(k.i, ++k.x);
		q.push(k);
	}
	return 0;
}
