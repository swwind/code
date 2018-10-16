#include <bits/stdc++.h>
#define N 520
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char mp1[N][N], mp2[N][N];
char str[N];
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++ i) {
    scanf("%s", str + 1);
    memcpy(mp1[i], str, sizeof str);
    memcpy(mp2[i], str, sizeof str);
  }
  for (int i = 1; i <= m; ++ i) {
    mp1[1][i] = '#';
    mp2[n][i] = '#';
  }
  for (int i = 1; i <= m; ++ i) {
    auto mp = (i & 1) ? mp1 : mp2;
    for (int j = 2; j < n; ++ j) {
      mp[j][i] = '#';
    }
  }
  for (int i = 1; i <= n; ++ i) {
    printf("%s\n", mp1[i] + 1);
  }
  puts("");
  for (int i = 1; i <= n; ++ i) {
    printf("%s\n", mp2[i] + 1);
  }
  return 0;
}