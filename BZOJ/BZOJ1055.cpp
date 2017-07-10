#include <bits/stdc++.h>
#define N 205
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int f[N][N][4];
int a[N], t[4], len, flag;
char str[N], ch[4][20][2];
inline int calc(char ch){
	if(ch == 'W') return 0;
	if(ch == 'I') return 1;
	if(ch == 'N') return 2;
	if(ch == 'G') return 3;
}
inline char revcalc(int x){
	if(x == 0) return 'W';
	if(x == 1) return 'I';
	if(x == 2) return 'N';
	if(x == 3) return 'G';
}
int dfs(int l, int r, int k){
	if(l == r) return a[l] == k;
	int &ans = f[l][r][k];
	if(ans != -1) return ans;
	for(int i = 1; i <= t[k]; i++)
		for(int j = l; j < r; j++)
			if(dfs(l, j, calc(ch[k][i][0])) && dfs(j+1, r, calc(ch[k][i][1])))
				return ans = 1;
	return ans = 0;
}
int main(){
	memset(f, -1, sizeof f);
	for(int i = 0; i < 4; i++) t[i] = read();
	for(int i = 0; i < 4; i++)
		for(int j = 1; j <= t[i]; j++)
			scanf("%s", ch[i][j]);
	scanf("%s", str+1); len = strlen(str+1);
	for(int i = 1; i <= len; i++) a[i] = calc(str[i]);
	for(int i = 0; i < 4; i++)
		if(dfs(1, len, i))
			flag = putchar(revcalc(i));
	if(!flag) puts("The name is wrong!");
	return 0;
}