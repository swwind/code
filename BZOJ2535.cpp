#include <bits/stdc++.h>
#define N 30020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int to[N], nxt[N], head[N], cnt, n;
void ins(int x, int y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
}
struct node{
	int id, rk;
	bool operator < (const node &b) const {
		return rk < b.rk;
	}
}a[N];
int rk[N], in[N], q[N*10], tin[N];
int calc(int x){
	int l = 0, r = 0;
	memcpy(in, tin, sizeof tin);
	for(int i = 1, j = 1; i <= n; i++){
		for(;j <= n && a[j].rk < i; j++){
			if(a[j].id == x || in[a[j].id]) continue;
			q[++r] = a[j].id;
			// puts("wfaw");
		}
		// printf("%d %d\n", l, r);
		if(l < r) for(int j = head[q[++l]]; j; j = nxt[j]){
			in[to[j]]--;
			if(to[j] != x && !in[to[j]] && rk[to[j]] < i)
			q[++r] = to[j];
		}
		else return r;
	}
	return r;
}
int main(){
	n = read(); int m = read();
	for(int i = 1; i <= n; i++)
		rk[i] = a[a[i].id=i].rk = n-read();
	sort(a+1, a+n+1);
	for(int i = 1; i <= m; i++){
		int x = read(), y = read();
		ins(y, x); tin[x]++;
	}
	for(int i = calc(0); i; i--) printf("%d ", q[i]);puts("");
	for(int i = 1; i <= n; i++) printf("%d ", n-calc(i));puts("");
	return 0;
}