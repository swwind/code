#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int vis[N], n, c[N], cnt, ans;
void add(int x, int y){
	for(;x;x^=x&-x)c[x]+=y;
}
int ask(int x){
	int ans = 0;
	for(;x<=n;x+=x&-x)ans+=c[x];
	return ans;
}
int main(int argc, char const *argv[]){
	n = read();
	for(int i = 1, n2 = n<<1; i <= n2; i++){
		int x = read();
		if(!vis[x]){
			vis[x] = ++cnt;
			add(cnt, 1);
		}
		else{
			ans += ask(vis[x]+1);
			add(vis[x], -1);
		}
		// printf("%d -> %d\n", x, ans);
	}
	printf("%d\n", ans);
	return 0;
}