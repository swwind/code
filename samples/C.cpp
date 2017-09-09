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
	int n = read(); c[1][0] = 1;
	for(int i = 1; i <= n; i++, puts(""))
		for(int j = 1; j <= n; j++)
			printf("%d ", c[i][j]=c[i-1][j]+c[i][j-1]);
	return 0;
}
