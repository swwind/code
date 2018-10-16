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
int cnt2, cnt4;
int main(int argc, char const *argv[]) {
	int n = read();
	for (int i = 1; i <= n; i++) {
		int x = read();
		if (x % 4 == 0) cnt4 ++;
		else if (x % 2 == 0) cnt2 ++;
	}
	if (cnt4 * 2 + (cnt2 ? cnt2 : 1) >= n) puts("Yes");
	else puts("No");
	return 0;
}
