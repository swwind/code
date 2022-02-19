#include <bits/stdc++.h>

using namespace std;

char s1[10020], s2[10020];
int c[10020];

int main() {

  int t;
  scanf("%d", &t);
  while (t --) {
    scanf("%s%s", s1, s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    memset(c, 0, sizeof(c));

    for (int i = 0; i < n1; ++ i) {
      c[n1 - i] += s1[i] - '0';
    }
    for (int i = 0; i < n2; ++ i) {
      c[n2 - i] += s2[i] - '0';
    }

    for (int i = 1; i <= max(n1, n2); ++ i) {
      c[i+1] += c[i] >> 1;
      c[i] &= 1;
    }
    int n = max(n1, n2) + 1;
    while (n && !c[n]) -- n;
    if (!n) ++ n;
    for (int i = n; i; -- i) {
      putchar('0' + c[i]);
    }
    puts("");
  }
}