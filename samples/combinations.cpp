// 组合数（暴力求

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
int c[101][101];
int main(int argc, char const *argv[]){
	printf("Please input n(n <= 100): ");
	int n = read();
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	for (int i = 0; i <= n; i++, puts(""))
		for (int j = 0; j <= i; j++)
			printf("%5d", c[i][j]);
	return 0;
}
