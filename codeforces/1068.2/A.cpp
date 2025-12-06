#include <cstdio>

char s[200];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);

    scanf("%s", s);

    int awake = 500;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        awake = 0;
      } else {
        if (awake++ >= m)
          ans++;
      }
    }

    printf("%d\n", ans);
  }
}
