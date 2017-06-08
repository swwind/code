#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[100020];
int main(){
	int n = read(), k = read();
	for(int i = 1; i <= k; i++)
		for(int j = 1; j <= n; j++)
			a[j] += read();
	for(int i = 1; i <= n; i++)
		printf("%.3lf ", 1.0*a[i]/k);
}