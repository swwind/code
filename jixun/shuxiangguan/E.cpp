// AGC014E
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

int fa[N], sz[N];
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

typedef pair<int, int> kotori;
set<kotori> mp;
set<int> es[N];
map<kotori, int> ct;
queue<kotori> que;

void insert(int x, int y) {
  if (x > y) swap(x, y);
  kotori res = {x, y};
  if (++ ct[res] == 2) {
    que.push(res);
  }
  mp.insert(res);
}

void erase(int x, int y) {
  if (x > y) swap(x, y);
  mp.erase({x, y});
}

int main(int argc, char const *argv[]) {
  int n = read();

  for (int i = 1; i <= n; ++ i) {
    fa[i] = i;
  }

  for (int i = 1; i < n*2-1; ++ i) {
    int x = read(), y = read();
    insert(x, y);
    es[x].insert(y);
    es[y].insert(x);
  }

  while (!que.empty()) {
    kotori prpr = que.front();
    que.pop();

    int x = find(prpr.first);
    int y = find(prpr.second);

    if (x == y) continue;

    if (es[x].size() > es[y].size()) {
      swap(x, y);
    }

    fa[x] = y;
    erase(x, y);
    es[y].erase(x);
    for (int to : es[x]) {
      to = find(to);
      if (to == y) continue;
      erase(x, to);
      insert(to, y);
      es[to].erase(x);
      es[to].insert(y);
      es[y].insert(to);
    }

  }

  int ans = 0;
  for (int i = 1; i <= n; ++ i) {
    ans += fa[i] == i;
  }

  if (ans == 1) puts("YES");
  else          puts("NO");

  return 0;
}