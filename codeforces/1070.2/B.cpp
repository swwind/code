#include <algorithm>
#include <cstdio>

#define N 200020

char s[N];

int main() {
  int T;
  scanf("%d", &T);

  while (T--) {
    // int n, m;
    // scanf("%d%d", &n, &m);

    int n;
    scanf("%d", &n);

    scanf("%s", s);

    int ans = 0;
    int mx = 0;
    int start = 0;
    while (s[start] == '0')
      start++;
    int cnt = start;
    for (int i = start; i < n; ++i) {
      //   printf("%d\n", s[i])
      if (s[i] == '1') {
        mx = std::max(mx, cnt);
        cnt = 0;
      } else {
        cnt += 1;
      }
    }
    mx = std::max(mx, cnt + start);

    printf("%d\n", mx);
  }
}