#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}s
int main(int argc, char const *argv[]) {
	int n = read();
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		int x = read(), y = read();
		if (x >= 2400 && y > x)
			return puts("YES")&0;
	}
	puts("NO");
	return 0;
}