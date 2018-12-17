// 愚蠢至极

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
const vector<vector<string>> items = {
  {
    "###",
    ".#.",
    ".#.",
  }, {
    "..#",
    "###",
    "..#",
  }, {
    "#..",
    "###",
    "#..",
  }, {
    ".#.",
    ".#.",
    "###",
  }
};
bool mp[15][15];
int n, m, ans;
bool valid(vector<string> item, int x, int y) {
  for (int i = 0; i < 3; ++ i) {
    for (int j = 0; j < 3; ++ j) {
      if (item[i][j] == '#' && mp[x + i][y + j]) {
        return false;
      }
    }
  }
  return true;
}
void put(vector<string> item, int x, int y) {
  for (int i = 0; i < 3; ++ i) {
    for (int j = 0; j < 3; ++ j) {
      if (item[i][j] == '#') {
        mp[x + i][y + j] ^= 1;
      }
    }
  }
}
void dfs(int x, int y, int z) {
  if (z < ans) return;
  if (y == m) {
    y = 0;
    ++ x;
  }
  if (x == n) {
    ans = max(ans, z);
    return;
  }
  if (x <= n - 3 && y <= m - 3) {
    for (auto item : items) {
      if (valid(item, x, y)) {
        put(item, x, y);
        dfs(x, y + 1, z + 1);
        put(item, x, y);
      }
    }
  }
  dfs(x, y + 1, z);
}
int main(int argc, char const *argv[]) {
  n = read();
  m = read();
  dfs(0, 0, 0);
  printf("%d\n", ans);
  return 0;
}
