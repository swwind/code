#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[25];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++)
		a[i] = a[i-1]+read();
	int m = a[n]>>1, ans = 0;
	if(a[n]&1)return puts("0")&0;
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			if(a[j]-a[i] == m) ans++;
	printf("%d\n", ans*(ans-1)/2);
}