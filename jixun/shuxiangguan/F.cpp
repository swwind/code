// CF718D
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef ll hash_t;
const int kMaxN = 1e5 + 5;
int n, sz[kMaxN];
vector<int> G[kMaxN];
set<hash_t> S;
map<pii, hash_t> dp;
map<vector<hash_t>, hash_t> H;
const ll kHBase = 31, kHMod = 1610612741LL;
hash_t pcnt = 0;
hash_t GetHash(int x, int f) {
  if (dp[make_pair(x, f)])
    return dp[make_pair(x, f)];
  vector<hash_t> v;
  for (int nxt : G[x]) {
    if (nxt == f)
      continue;
    v.push_back(GetHash(nxt, x));
  }
  sort(v.begin(), v.end());
  if (H.find(v) == H.end())
    H[v] = ++pcnt;
  return dp[make_pair(x, f)] = H[v];
}
int main() {
  scanf("%d", &n);
  for (int i = 1, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    if (G[i].size() < 4) {
      hash_t t = GetHash(i, 0);
      S.insert(t);
      // fprintf(stderr, "%lld\n", t);
    }
  }
  printf("%d\n", (int)S.size());
  return 0;
}