#include <bits/stdc++.h>
#define N 1020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int h[N], l[N], x[N];
bool cmp1(int a, int b){return h[a] > h[b];}
bool cmp2(int a, int b){return l[a] > l[b];}
int main(int argc, char const *argv[]){
	int n = read(), m = read(), a = read(), b = read(), t = read();
	while(t--){
		int x1 = read(), y1 = read(), x2 = read(), y2 = read();
		if(x1 == x2) l[min(y1, y2)]++;
		else h[min(x1, x2)]++;
	}
	for(int i = 1; i <= n; i++) x[i] = i;
	sort(x+1, x+n+1, cmp1);
	sort(x+1, x+a+1);
	if(a) printf("%d", x[1]);
	for(int i = 2; i <= a; i++) printf(" %d", x[i]);puts("");
	for(int i = 1; i <= m; i++) x[i] = i;
	sort(x+1, x+m+1, cmp2);
	sort(x+1, x+b+1);
	if(b) printf("%d", x[1]);
	for(int i = 2; i <= b; i++) printf(" %d", x[i]);puts("");
	return 0;
}