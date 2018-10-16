// manacher 求最长回文串

#include <bits/stdc++.h>
#define N 11000020
#define ll long long
using namespace std;
int rl[N<<1];
char val[N<<1];
int manacher(char *s) {
  int res = 0;
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    val[i << 1] = '#';
    val[i<<1|1] = s[i];
  }
  val[len << 1] = '#';
  int mxr = -1, pos = 0;
  len = len << 1 | 1;
  for (int i = 0; i < len; i++) {
    rl[i] = i < mxr ?
      min(rl[2 * pos - i], mxr - i) : 1;
    while (i - rl[i] >= 0 && i + rl[i] < len && val[i - rl[i]] == val[i + rl[i]])
      rl[i] ++;
    if (i + rl[i] - 1 > mxr) {
      mxr = i + rl[i] - 1;
      pos = i;
    }
    res = max(res, rl[i] - 1);
  }
  return res;
}
char str[N];
int main(int argc, char const *argv[]) {
  scanf("%s", str);
  printf("%d\n", manacher(str));
  return 0;
}