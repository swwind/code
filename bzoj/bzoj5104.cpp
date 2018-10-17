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
int main(int argc, char const *argv[]) {
	int a = 1, b = 1;
	int x = read();
	if (x == 1) return puts("1")&0;
	for (int p = 3; p; p++) {
		int c = a + b;
		if (c >= 1000000009)
			c -= 1000000009;
		if (c == x) return printf("%d\n", p)&0;
		a = b; b = c;	
	}
	return 0;
}