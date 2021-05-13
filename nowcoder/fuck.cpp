#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
#define N 100020

char s[N];
int now, n, point;

int head[N], nxt[N], to[N], cnt;
void link_tree(int x, int y) {
	// printf("linking %d %d\n", x, y);
	to[++ cnt] = y;
	nxt[cnt] = head[x];
	head[x] = cnt;
}

int next_plus();

int next_number() {
	char c = s[now ++];
	if (c == '(') return next_plus();
	else return ++ point;
}

// parse string with 1+1+1*2*2+2*3+2+2..

int next_plus() {
	int x = ++ point;
	int last_mul_child = 0;
	while (true) {
		int v = next_number();
		if (now > n || s[now] == ')') {
			if (last_mul_child) {
				link_tree(last_mul_child, v);
			} else {
				link_tree(x, v);
			}
			if (now <= n) ++ now;
			break;
		}
		char op = s[now ++];

		if (op == '*') {
			// 1*
			if (!last_mul_child) {
				// 1+1*
				last_mul_child = ++ point;
				link_tree(x, last_mul_child);
			}
			// 1*1*
			link_tree(last_mul_child, v);
		}

		if (op == '+') {
			// 1+
			if (last_mul_child) {
				link_tree(last_mul_child, v);
				last_mul_child = 0;
			} else {
				link_tree(x, v);
			}
		}
	}
	return x;
}

void print(int x) {
	printf("%d", x);
		putchar('(');
	for (int i = head[x]; i; i = nxt[i]) {
		print(to[i]);
		putchar(',');
	}
	putchar(')');
}

int Pow(int a,int n){
	int Ans=1;
	for(;n;n>>=1,a=a*1ll*a%mod)if(n&1)Ans=Ans*1ll*a%mod;
	return Ans;
}

int frac[N], inv[N];
int dp[5050][5050];
int f[5050];

// return { sz[x], h[x] }
pair<int, int> dfs(int x) {
	vector<int> val, siz;
  int len = 0;
	for (int i = head[x]; i; i = nxt[i]) {
    pair<int, int> pr = dfs(to[i]);
		val.push_back(pr.second);
    siz.push_back(pr.first);
		++len;
	}
	if (!len) return {0, 1};

	for (int i = 1; i < len; ++ i) {
		siz[i] += siz[i-1];
	}
  for (int i = 0; i < len; ++ i) {
    dp[i][i] = val[i];
  }
	for (int n = 2; n <= len; ++ n) {
		for (int r = n - 1; r < len; ++ r) {
			int l = r - n + 1;
      dp[l][r] = 0;
			for (int k = l; k < r; ++ k) {
        dp[l][r] = (dp[l][r] + (long long) dp[l][k] * dp[k+1][r] % mod) % mod;
			}
      dp[l][r] = (long long) dp[l][r] * Pow((l>0?siz[r]-siz[l-1]:siz[r]) + r-l, mod-2) % mod;
		}
	}
	return { siz[len-1]+len-1, dp[0][len-1] };
}

int main() {
	int T; scanf("%d", &T);
	frac[0] = 1;
	for (int i = 1; i <= 10000; ++ i) {
		frac[i] = frac[i-1]*1ll*i%mod;
	}
	// inv[10000]=Pow(frac[10000],mod-2);
	// for(int i=9999;~i;i--)inv[i]=inv[i+1]*(i+1ll)%mod;

	for (int i = 1; i <= T; ++ i) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		now = 1;
		memset(head, 0, sizeof head);
		point = 0;
		int rt = next_plus();
		// print(rt);
		// puts("");
		pair<int, int> res = dfs(rt);
    // printf("%d, %d\n", res.first, res.second);
		printf("%d\n", (long long) res.second * frac[res.first] % mod);
	}
}
