#include <bits/stdc++.h>
#define N 100020
#define ll long long
#define mod 1000000007
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

std::vector<pair<int, int>> adj[N];
int ty[N][2], vis[N], kind[(N << 1) + 3], need = 1, num[2], deg[N];

void deal(int i) {
	static int nxt_num[2];
	memset(nxt_num, 0, sizeof nxt_num);
	for (int j = 0; j < 2; j++) {
		static int dp[2][2];
		memset(dp, 0, sizeof dp);
		int what = 0;
		if (ty[i][0]) what ^= j;
		if (ty[i][1]) what ^= !j;
		dp[j][what] = 1;
		int u = i;
		int lste = -1;
		while (1) {
			// printf("%d\n", u);
			vis[u] = 1;
			int nxt = -1;
			int nxt_kind = -1;
			for (auto v : adj[u]) {
				if ((v.second ^ 1) != lste) {
					nxt = v.first;
					nxt_kind = kind[v.second];
					lste = v.second;
					break;
				}
			}
			if (!~nxt)
				break;
			u = nxt;
			static int nxt_dp[2][2];
			memset(nxt_dp, 0, sizeof nxt_dp);
			for (int k = 0; k < 2; k++) {
				int tmp = 0;
				if (u == i) {
					if (k != j)
						continue;
				} else {
					if (ty[u][0]) tmp ^= k;
					if (ty[u][1]) tmp ^= !k;
				}
				for (int lst = 0; lst < 2; lst++) {
					for (int val = 0; val < 2; val++) {
						if (dp[lst][val]) {
							int nxt_val = val ^ tmp;
							what = 0;
							if (nxt_kind & 1) what |= !lst;
							else what |= lst;
							if (nxt_kind & 2) what |= !k;
							else what |= k;
							nxt_val ^= what;
							nxt_dp[k][nxt_val] = (nxt_dp[k][nxt_val] + dp[lst][val]) % mod;
						}
					}
				}
			}
			memcpy(dp, nxt_dp, sizeof dp);
			if (u == i)
				break;
		}
		for (int k = 0; k < 2; k++)
			for (int a = 0; a < 2; a++)
				for (int b = 0; b < 2; b++)
					nxt_num[b ^ k] = (nxt_num[b ^ k] + 1ll * num[k] * dp[a][b] % mod) % mod;
	}
	memcpy(num, nxt_num, sizeof num);
}

int main(int argc, char const *argv[]) {
	int n = read(), m = read();
	for (int i = 0; i < n; i++) {
		if (read() == 1) {
			int x = read();
			if (x > 0) ty[x - 1][0] ^= 1;
			else ty[- x - 1][1] ^= 1;
		} else {
			int x = read(), y = read();
			if (x == y) {
				if (x > 0) ty[x - 1][0] ^= 1;
				else ty[- x - 1][1] ^= 1;
			} else if (x == -y) {
				need ^= 1;
			} else {
				kind[i << 1] = kind[i << 1 | 1] = 0;
				if (x < 0) {
					x = -x;
					kind[i << 1] |= 1;
					kind[i << 1 | 1] |= 2;
				}
				if (y < 0) {
					y = -y;
					kind[i << 1] |= 2;
					kind[i << 1 | 1] |= 1;
				}
				-- x;
				-- y;
				adj[x].push_back(make_pair(y, i << 1));
				adj[y].push_back(make_pair(x, i << 1 | 1));
				++ deg[x];
				++ deg[y];
			}
		}
	}
	num[0] = 1;
	for (int i = 0; i < m; i++)
		if (!vis[i] && deg[i] == 1)
			deal(i);
	for (int i = 0; i < m; i++)
		if (!vis[i])
			deal(i);
	printf("%d\n", (num[need] + mod) % mod);
	return 0;
}