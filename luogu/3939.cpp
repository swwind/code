#include <bits/stdc++.h>
#define N 300020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[N];
std::vector<int> pos[N];
int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		pos[a[i]].push_back(i);
	}
	while (m --) {
		int op = read();
		if (op == 1) {
			int l = read(), r = read(), c = read();
			int st = upper_bound(pos[c].begin(), pos[c].end(), r) - pos[c].begin();
			int ed = upper_bound(pos[c].begin(), pos[c].end(), l - 1) - pos[c].begin();
			printf("%d\n", st - ed);
		} else {
			int x = read();
			if (a[x] == a[x + 1]) continue;
			int px = lower_bound(pos[a[x]].begin(), pos[a[x]].end(), x) - pos[a[x]].begin();
			// printf("[%d]\n", px);
			pos[a[x]][px] ++;
			px = lower_bound(pos[a[x+1]].begin(), pos[a[x+1]].end(), x+1) - pos[a[x+1]].begin();
			// printf("[%d]\n", px);
			pos[a[x+1]][px] --;
			swap(a[x], a[x + 1]);
		}
	}
	return 0;
}