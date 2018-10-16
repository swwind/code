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
map<int, int> mp;
queue<int> q;
int bin[10], ed = 123804765;
// 987
// 654
// 321
int findZero(int x) {
	for (int i = 1; i <= 9; i++)
		if (x/bin[i]%10 == 0) return i;
}
int swap(int x, int fr, int to) {
	int s = x/bin[to]%10;
	int ans = x+s*bin[fr]-s*bin[to];
	return ans;
}
int bfs(int st) {
	q.push(st);
	mp[st] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int zero = findZero(x);
		if (zero < 7) { // is not the top
			int y = swap(x, zero, zero+3);
			if (y == ed)
				return mp[x];
			if (!mp[y]) {
				q.push(y);
				mp[y] = mp[x]+1;
			}
		}
		if (zero%3 != 1) { // is not the right
			int y = swap(x, zero, zero-1);
			if (y == ed)
				return mp[x];
			if (!mp[y]) {
				q.push(y);
				mp[y] = mp[x]+1;
			}
		}
		if (zero%3 != 0) { // is not the left
			int y = swap(x, zero, zero+1);
			if (y == ed)
				return mp[x];
			if (!mp[y]) {
				q.push(y);
				mp[y] = mp[x]+1;
			}
		}
		if (zero > 3) { // is not the top
			int y = swap(x, zero, zero-3);
			if (y == ed)
				return mp[x];
			if (!mp[y]) {
				q.push(y);
				mp[y] = mp[x]+1;
			}
		}
	}
	return -1;
}
int main(int argc, char const *argv[]) {
	bin[1] = 1;
	for (int i = 2; i <= 9; i++)
		bin[i] = bin[i-1]*10;
	printf("%d\n", bfs(read()));
	return 0;
}
