#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define fs first
#define sc second
#define M (1 << 8)
#define update(a, b) a = (a + b) % mod
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}
const int PRI[] = {2, 3, 5, 7, 11, 13, 17, 19};
vector<vector<int> > v;
vector<pair<int, int> > tmp;
int f[M][M], g[2][M][M];
int main(int argc, char const *argv[]) {
	int n = read(), mod = read();
	for (int i = 2; i <= n; i++) {
		int x = i, t = 0;
		for (int j = 0; j < 8; j++) {
			if (x % PRI[j] == 0) {
				while (x % PRI[j] == 0)
					x /= PRI[j];
				t |= 1 << j;
			}
		}
		tmp.push_back(make_pair(x, t));
	}
	sort(tmp.begin(), tmp.end());
	for (std::vector<pair<int, int> >::iterator it = tmp.begin(); it != tmp.end(); ++it) {
		if (it == tmp.begin() || it -> fs == 1 || it -> fs != (it - 1) -> fs)
			v.push_back(vector<int>());
		v.back().push_back(it -> sc);	
	}
	f[0][0] = 1;
	for (std::vector<std::vector<int> >::iterator i = v.begin(); i != v.end(); ++i) {
		memcpy(g[0], f, sizeof f);
		memcpy(g[1], f, sizeof f);
		for (std::vector<int>::iterator it = i -> begin(); it != i -> end(); ++it) {
			for (int a = M - 1; ~a; a--) {
				for (int b = M - 1; ~b; b--) {
					if ((b & * it) == 0) update(g[0][a | * it][b], g[0][a][b]);
					if ((a & * it) == 0) update(g[1][a][b | * it], g[1][a][b]);
				}
			}
		}
		for (int a = M - 1; ~a; a--)
			for (int b = M - 1; ~b; b--)
				f[a][b] = ((g[0][a][b] + g[1][a][b] - f[a][b]) % mod + mod) % mod;
	}
	int ans = 0;
	for (int a = M - 1; ~a; a--)
		for (int b = M - 1; ~b; b--)
			if ((a & b) == 0) update(ans, f[a][b]);
	printf("%d\n", ans);
	return 0;
}
