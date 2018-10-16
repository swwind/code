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
std::map<int, bool> to1, to2;
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	while (m --) {
		int x = read(), y = read();
		if (x > y) swap(x, y);
		if (x == 1) to2[y] = 1;
		if (y == n) to1[x] = 1;
	}
	for (int i = 2; i < n; i++)
		if (to1[i] && to2[i])
			return puts("POSSIBLE")&0;
	puts("IMPOSSIBLE");
	return 0;
}
