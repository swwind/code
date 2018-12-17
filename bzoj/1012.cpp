#include <bits/stdc++.h>
#define N 150020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int st[N], top, t, a[N], p;
char str[2];
int main(){
	int m = read(), zyy = read();
	while(m--){
		scanf("%s", str);
		if(str[0] == 'A'){
			int x = (read()+t)%zyy;
			a[++p] = x;
			for(;top&&a[st[top]]<=x;top--);
			st[++top] = p;
		} else
			printf("%d\n", t=a[st[lower_bound(st+1, st+top+1, p-read()+1)-st]]);
	}
}