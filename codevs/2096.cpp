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
int ch[1<<20|5][2], cnt = 1, ps[N], a[N];
int push(int x, int k){
	int now = 1;
	for(int i = 19; ~i; i--){
		int c = x>>i&1;
		if(!ch[now][c]) ch[now][c] = ++cnt;
		now = ch[now][c];
	}
	ps[now] = k;
	now = 1;
	for(int i = 19; ~i; i--){
		int c = x>>i&1;
		now = ch[now][!c] ? ch[now][!c] : ch[now][c];
	}
	return ps[now];
}
int main(int argc, char const *argv[]){
	int n = read(), ans = 0, l, r;
	for(int i = 1; i <= n; i++) a[i] = read()^a[i-1];
	for(int i = 1; i <= n; i++){
		int k = push(a[i], i);
		if(a[i]^a[k] > ans)
			ans = a[i]^a[k], l = k, r = i;
	}
	printf("%d %d %d\n", ans, l+1, r);
	return 0;
}