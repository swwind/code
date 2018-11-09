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
	int x = read(), y = read();
	if(y%x) return puts("0")&0;
	int g = y/x, ans = 0;
	for(int i = 1; i <= g; i++)
		if(g%i == 0 && gcd(i, g/i) == 1) ans++;
	printf("%d\n", ans);
	return 0;
}