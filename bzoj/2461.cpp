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

char str[55];
int len;

ll f[55][55][55][55];

// SSDSDDDSDS
//  ^~~ p
//  ((( <- x   y -> ))) (( <- z
ll dfs(int p, int x, int y, int z) {
  if (p == len + 1) {
    return x == y && !z;
  }
  ll &ans = f[p][x][y][z];
  if (~ ans) return ans;
  ans = 0;
  if (str[p] == 'S') {
    // put '('
    ans += dfs(p + 1, x + 1, y, z + 1);
    // put ')'
    if (x) {
      if (z) {
        ans += dfs(p + 1, x - 1, y, z - 1);
      } else {
        ans += dfs(p + 1, x - 1, y + 1, z);
      }
    }
  } else {
    // put '('
    if (z) {
      ans += dfs(p + 1, x + 1, y, z - 1);
    } else {
      ans += dfs(p + 1, x + 1, y + 1, z);
    }
    // put ')'
    if (x) {
      ans += dfs(p + 1, x - 1, y, z + 1);
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  // freopen("../tmp/.in", "r", stdin);

  int T = read();

  while (T --) {
    scanf("%s", str + 1);
    len = strlen(str + 1);
    memset(f, -1, sizeof f);
    printf("%lld\n", dfs(1, 0, 0, 0));
  }

  return 0;
}