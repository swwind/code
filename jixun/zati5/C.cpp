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
std::map<int, bool> mp;
int main(int argc, char const *argv[]) {
	int n = read(), ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = read();
		if (mp[x]) ans --, mp[x] = 0;
		else       ans ++, mp[x] = 1;
	}
	printf("%d\n", ans);
	return 0;
}