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
int a[N], st[N], top;
int main(int argc, char const *argv[]){
	int n = read(), ans = 0;
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++){
		while(top && st[top] < a[i]) top--;
		if(top) ans = max(ans, st[top]^a[i]);
		st[++top] = a[i];
	}
	top = 0;
	for(int i = n; i; i--){
		while(top && st[top] < a[i]) top--;
		if(top) ans = max(ans, st[top]^a[i]);
		st[++top] = a[i];
	}
	printf("%d\n", ans);
	return 0;
}