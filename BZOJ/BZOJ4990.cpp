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
int c[N], n;
int ask(int x){
	int ans = 0;
	for(;x;x^=x&-x)ans=max(ans,c[x]);
	return ans;
}
void add(int x, int y){
	for(;x<=n;x+=x&-x)
		if(c[x] > y) return;
		else c[x] = y;
}
int a[N], b[N], d[N];
int main(int argc, char const *argv[]){
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[read()] = i;
	for(int i = 1; i <= n; i++){
		for(int j = max(1, a[i]-4); j <= min(n, a[i]+4); j++) d[j] = ask(b[j]-1);
		for(int j = max(1, a[i]-4); j <= min(n, a[i]+4); j++) add(b[j], d[j]+1);
	}
	printf("%d\n", ask(n));
	return 0;
}