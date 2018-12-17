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
int s[N], ans;
int main(int argc, char const *argv[]){
	int n = read(), m = read(), d = read(), l = read();
	for(int i = 1; i <= n; i++) s[i] = read();
	sort(s+1, s+n+1);
	for(int i = 1; i <= n; i++)
		if(s[i]-(ans/m)*d >= l) ans++;
	printf("%d\n", ans);
	return 0;
}