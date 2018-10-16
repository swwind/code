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
char ch[520][520], chr[520][520], chb[520][520];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
		scanf("%s", ch[i] + 1);
	memcpy(chb, ch, sizeof ch);
	memcpy(chr, ch, sizeof ch);
	for (int i = 1; i <= m; i++)
		chr[1][i] = chb[n][i] = '#';
	for (int i = 2; i < n; i++)
		chr[i][m] = chb[i][1] = '#';
	for (int i = 2; i < n; i += 2)
		for (int j = 2; j < m; j++)
			chr[i][j] = '#';
	for (int i = 3; i < n; i += 2)
		for (int j = 2; j < m; j++)
			chb[i][j] = '#';
	for (int i = 1; i <= n; i++)
		printf("%s\n", chr[i] + 1);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%s\n", chb[i] + 1);
	return 0;
}
