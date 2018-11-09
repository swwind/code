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
int n;
int pw(int y, int x = 2){
	int z = 1;
	for(;y;y>>=1, x=x*x%n) if(y&1) z=z*x%n;
	return z;
}
int main(int argc, char const *argv[]){
	while(cin >> n){
		if(~n&1 || n == 1){printf("2^? mod %d = 1\n", n); continue;}
		int ans = 0;
		while(pw(++ans) != 1);
		printf("2^%d mod %d = 1\n", ans, n);
	}
	return 0;
}