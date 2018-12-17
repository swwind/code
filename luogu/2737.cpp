#include <bits/stdc++.h>
#define N 256
#define M 65536
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[M+5], a[15];
int find(){for(int i = M; i; i--) if(!f[i]) return i;}
int main(int argc, char const *argv[]){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a+1, a+n+1);
	if(a[1] == 1) return puts("0")&0;
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = a[i]; j <= M; j++)
			if(f[j-a[i]]) f[j] = 1;
	int x = find();
	if(x > M-N*2) x = 0;
	printf("%d\n", x);
	return 0;
}