#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(int argc, char const *argv[]) {
	ll x = read();
	if (x == 5) return puts("3\n1 1 3")&0;
	printf("%d\n", (int)log2(x)+1);
	for (int i = 1; i <= x; x -= i, i <<= 1)
		printf("%d ", i);
	if (x) printf("%d\n", x);
	return 0;
}