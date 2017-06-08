#include <bits/stdc++.h>
#define N 100020
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int inf = 1 << 30;
int a[N], b[N], c[N], d[N], A, B, C, D;
int main(){
	int T = read();
	while(T--){
		int n = read();
		A = C = inf; B = D = -inf;
		for(int i = 1; i <= n; i++){
			A = min(A, a[i] = read());
			B = max(B, b[i] = read());
			C = min(C, c[i] = read());
			D = max(D, d[i] = read());
		}
		int flag = 0;
		for(int i = 1; i <= n && !flag; i++)
			if(a[i] == A && b[i] == B && c[i] == C && d[i] == D)
				flag = 1;
		puts(flag?"TAK":"NIE");
	}
}