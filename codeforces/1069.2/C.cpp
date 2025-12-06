#include <cstdio>
#include <cstring>

char s[100020];
char t[100020];

int ss[26];
int ts[26];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    // int n, m;
    // scanf("%d%d", &n, &m);

    scanf("%s", s);
    scanf("%s", t);

    int n = strlen(s);
    int m = strlen(t);

    for (int i = 0; i < 26; ++i) {
      ss[i] = ts[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
      ss[s[i] - 'a'] += 1;
    }
    for (int i = 0; i < m; ++i) {
      ts[t[i] - 'a'] += 1;
    }

    int ok = 1;
    for (int i = 0; i < 26; ++i) {
      if (ss[i] > ts[i]) {
        ok = 0;
      }
    }

    if (!ok) {
      puts("Impossible");
      continue;
    }

    // printf("%d\n", n + m);
    // for (int i = 0; i < 26; ++i)
    //   printf("%d", ss[i]);
    // puts("");
    // for (int i = 0; i < 26; ++i)
    //   printf("%d", ts[i]);
    // puts("");

    int idx = 0;
    for (int i = 0; i < m; ++i) {
      // now choose the charactor

      int chosen = 0;
      for (int j = 0; j < 26; ++j) {
        if (ts[j] > ss[j] || (ts[j] == ss[j] && j == s[idx] - 'a')) {
          chosen = j;
          break;
        }
      }

      if (chosen == s[idx] - 'a') {
        ss[chosen] -= 1;
        idx += 1;
      }
      ts[chosen] -= 1;
      printf("%c", 'a' + chosen);
    }
    puts("");
  }
}
