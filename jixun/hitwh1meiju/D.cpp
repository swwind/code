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

char str[2020][2020];
int cnt[2020];

int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    scanf("%s", str[i] + 1);
    for (int j = 1; j <= m; ++ j) {
      if (str[i][j] == '1') ++ cnt[j];
    }
  }
  for (int i = 1; i <= n; ++ i) {
    bool allow = true;
    for (int j = 1; j <= m; ++ j) {
      allow &= (cnt[j] - (str[i][j] == '1')) > 0;
    }
    if (allow) return puts("YES"), 0;
  }
  puts("NO");
}