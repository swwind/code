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
int fa[N];
int len[N], len_sum[N];
int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
char str1[N], str2[N];
int main(int argc, char const *argv[]) {
  freopen("../temp/input.in", "r", stdin);
  int n = read();
  for (int i = 0; i < n; ++ i) {
    len[i] = read();
    len_sum[i] = len_sum[i - 1] + len[i - 1];
  }
  len_sum[n] = len_sum[n - 1] + len[n - 1];
  int len0 = len_sum[n] + 1;
  int len1 = len0 + 1;
  for (int i = 1; i <= len1; ++ i) {
    fa[i] = i;
  }
  scanf("%s", str1 + 1);
  scanf("%s", str2 + 1);
  int pos1 = 1, it1 = 1;
  int pos2 = 1, it2 = 1;
  int strlen1 = strlen(str1 + 1);
  int strlen2 = strlen(str2 + 1);
  while (pos1 <= strlen1 && pos2 <= strlen2) {
    // printf("%d %d %d %d\n", pos1, it1, pos2, it2);
    char c1 = str1[pos1], c2 = str2[pos2];
    int f1 = c1 == '0' ? len0 : c1 == '1' ? len1 : find(len_sum[c1 - 'a'] + it1);
    int f2 = c2 == '0' ? len0 : c2 == '1' ? len1 : find(len_sum[c2 - 'a'] + it2);

    if (f1 + f2 == len0 + len1) return puts("0"), 0;
    if (f1 != f2) {
      if (f1 > len_sum[n]) fa[f2] = f1;
      else fa[f1] = f2;
    }

    if (c1 == '1' || c1 == '0' || it1 ++ == len[c1 - 'a']) {
      ++ pos1;
      it1 = 1;
    }
    if (c2 == '1' || c2 == '0' || it2 ++ == len[c2 - 'a']) {
      ++ pos2;
      it2 = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= len_sum[n]; ++ i) {
    ans += (find(i) == i);
  }
  printf("%.0Lf\n", powl(2.0L, ans));
  return 0;
}
