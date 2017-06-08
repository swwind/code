#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
	int x = 0, f = 0; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
char op[N];
int a[N][32], num[32], b[32], sum, ans;
int main(){
	int n = read(), m = read();
	for(int i = 1, x; i <= n; i++){
		op[i] = getchar(); x = read();
		for(int j = 0; j < 32; j++)
			a[i][j] = x>>j&1;
	}
	for(int i = 0; i < 32; i++){
		int x = 0, y = 1;
		for(int j = 1; j <= n; j++){
			if(op[j] == 'X') x ^= a[j][i], y ^= a[j][i];
			if(op[j] == 'A') x &= a[j][i], y &= a[j][i];
			if(op[j] == 'O') x |= a[j][i], y |= a[j][i];
		}
		b[i] = x|y;
		num[i] = !x&&y;
	}
	for(int i = 30; ~i; i--)
		if(sum|(num[i]?1<<i:0) <= m){
			if(num[i]) sum|=1<<i;
			if(b[i]) ans|=1<<i;
		}
	printf("%d\n", ans);
}
