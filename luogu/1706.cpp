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
int a[10];
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++) printf("%5d", a[i] = i); puts("");
	for(;next_permutation(a+1, a+n+1);puts(""))
		for(int i = 1; i <= n; i++) printf("%5d", a[i]);
	return 0;
}