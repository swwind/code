#include <bits/stdc++.h>
#define N 10007
#define zyy 1000000007
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
int x[N], y[N], t[N], f[N], mx[N];
int main(){ read();
	int n = read(); mx[1] = 1;
	for(int i = 1; i <= n; i++){
		t[i] = read(); x[i] = read();
		y[i] = read(); f[i] = 1;
	}
	for(int i = 2; i <= n; i++){
		for(int j = i-1; j; j--){
			if(mx[j] < f[i]) break;
			if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= t[i]-t[j])
				f[i] = max(f[i], f[j]+1);
		}
		mx[i] = max(f[i], mx[i-1]);
	}
	printf("%d\n", mx[n]);
}