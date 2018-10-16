#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

vector<int> mp[N];
int rt;

int dfs(int x, int fa) {
  set<int> s;
  for (auto v : mp[x]) {
    if (v != fa){
      int tmp = dfs(v, x);
      if (tmp == -1) return -1;
      else s.insert(tmp + 1);
    }
  }

  switch (s.size()) {
    case 0u:
      return 0;
    case 1u:
      return *s.begin();
    case 2u:
      return fa ? rt = x, -1 : *s.begin() + *s.rbegin();
    default:
      return -1;
  }

}
int main(int argc, char* const argv[]) {
  int n = read();
  for (int i = 1; i < n; ++ i){
    int x = read(), y = read();
    mp[x].push_back(y);
    mp[y].push_back(x);
  }

  int ans = dfs(1, 0);
  if (ans == -1 && rt) ans = dfs(rt, 0);
  while (!(ans & 1)) {
    ans >>= 1;
  }

  printf("%d\n", ans);

  return 0;
}