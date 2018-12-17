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
int gcd(int a, int b){return b?gcd(b, a%b):a;}
int main(int argc, char const *argv[]){
	int T = read();
	while(T--) puts(gcd(read(), read()) == 1 ? "NO" : "YES");
	return 0;
}