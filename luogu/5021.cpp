#include <bits/stdc++.h>
#define N 50020
using namespace std;
inline int read() {
  int x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9')ch=='-'&&(f=0)||(ch=getchar());
  while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return f?x:-x;
}

typedef int ll;

int to[N<<1], nxt[N<<1], head[N], cnt, len[N<<1];
void insert(int x, int y, int z) {
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt; len[cnt] = z;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt; len[cnt] = z;
}

ll swwind;
int ans;

ll dfs(int x, int f) {
  multiset<ll> st;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    ll w = dfs(to[i], x) + len[i];
    if (w >= swwind) {
      ++ ans;
      continue;
    }
    st.insert(w);
  }
  ll res = 0;
  while (st.size() >= 2) {
    ll mx = *st.begin();
    st.erase(st.begin());
    multiset<ll>::iterator it = st.lower_bound(swwind - mx);
    if (it != st.end()) {
      ++ ans;
      st.erase(it);
    } else {
      res = max(res, mx);
    }
  }
  if (st.size()) {
    res = max(res, *st.rbegin());
  }
  return res;
}
int n, m;

int check(ll mid) {
  swwind = mid;
  ans = 0;
  dfs(n, 0);
  return ans;
}

int main(int argc, char const *argv[]) {

  n = read(); m = read();
  ll sum = 0;
  for (int i = 1; i < n; ++ i) {
    int a = read(), b = read(), c = read();
    insert(a, b, c);
    sum += c;
  }

  ll l = 0, r = sum;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid) < m) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  printf("%lld\n", l - 1);
  
  return 0;
}
/*
每个点决策的时候需要考虑一下
我怀疑是能选就选（最大和最小能匹配的选，直到不能选，然后返回最大值
fake 掉了
*/