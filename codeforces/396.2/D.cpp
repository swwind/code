#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
map<string, int> mp;
string str;
int fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}
int main(int argc, char const *argv[]) {
	int n = read(), m = read(), k = read();
	for (int i = 0; i < n << 1; i ++)
		fa[i] = i;
	for (int i = 0; i < n; i ++) {
		cin >> str;
		mp[str] = i << 1;
	}
	while (m --) {
		int op = read();
		cin >> str;
		int x = mp[str];
		cin >> str;
		int y = mp[str];
		if (op == 1) {
			if (find(x ^ 1) == find(y)) puts("NO");
			else puts("YES"), merge(x, y), merge(x ^ 1, y ^ 1);
		} else {
			if (find(x) == find(y)) puts("NO");
			else puts("YES"), merge(x ^ 1, y), merge(x, y ^ 1);
		}
	}
	while (k --) {
		cin >> str;
		int x = mp[str];
		cin >> str;
		int y = mp[str];
		if (find(x) == find(y)) puts("1");
		else if (find(x ^ 1) == find(y)) puts("2");
		else puts("3");
	}
	return 0;
}