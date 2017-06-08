#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int c[3], a[N], s[3];
int main(){
	int n = read(), n2 = n >> 1;
	for(int i = 1; i <= n; i++)s[a[i]=read()]++;s[0]/=2,s[1]/=2,s[2]/=2;
	for(int i = 1; i <= n2; i++)c[a[i]]++;
	if(c[0] == s[0] && c[1] == s[1] && c[2] == s[2]) return putchar('1')&0;
	for(int i = 1; i <= n2; i++){
		c[a[i]]--; c[a[i+n2]]++;
		if(c[0] == s[0] && c[1] == s[1] && c[2] == s[2]) return putchar('2')&0;
	}
	putchar('3');
}