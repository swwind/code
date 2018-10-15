#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

int ans, n, k, inq[N];
int head[N], to[N<<1], nxt[N<<1], cnt;
void insert(int x, int y) {
  ++ inq[x]; ++ inq[y];
  to[++ cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
  to[++ cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

int dfs(int x, int f) {
  if (inq[x] == 1) {
    return 0;
  }
  vector<int> vec;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == f) {
      continue;
    }
    vec.push_back(1 + dfs(to[i], x));
  }
  sort(vec.begin(), vec.end());
  while (vec.size() >= 2 && vec[vec.size() - 1] + vec[vec.size() - 2] > k) {
    vec.pop_back();
    ++ ans;
  }
  return vec.back();
}

int main(int argc, char const *argv[]) {
  n = read(); k = read();
  for (int i = 1; i < n; ++ i) {
    insert(read(), read());
  }

  for (int i = 1; i <= n; ++ i) {
    if (inq[i] > 1) {
      dfs(i, 0);
      break;
    }
  }

  printf("%d\n", ans + 1);

  return 0;
}
