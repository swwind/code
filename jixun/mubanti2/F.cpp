#include <bits/stdc++.h>
#define N 400020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int q[N];
int main(int argc, char const *argv[]) {
	int n = read(), l = 200001, r = 200000;
	for (int i = 1; i <= n; i++)
		if (i & 1) q[++r] = read();
		else q[--l] = read();
	if (~ n & 1) for (int i = l; i <= r; i++) printf("%d ", q[i]);
	else for (int i = r; i >= l; i --) printf("%d ", q[i]);
	return 0;
}
