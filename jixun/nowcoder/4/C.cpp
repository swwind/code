#include <bits/stdc++.h>
#define N 10020

using namespace std;

char s1[N], s2[N], s3[N];
int t1, t2, t3;

int main() {
  int a, b, c, n;

  cin >> a >> b >> c >> n;

  while (a > 0 && b > 0 && c > 0) {
    s1[++ t1] = 'a';
    s2[++ t2] = 'a';
    s3[++ t3] = 'a';

    -- a; -- b; -- c;
  }

  while (a > 0) {
    s1[++ t1] = 'b';
    s2[++ t2] = 'b';
    -- a;
  }

  while (b > 0) {
    s2[++ t2] = 'c';
    s3[++ t3] = 'c';
    -- b;
  }

  while (c > 0) {
    s1[++ t1] = 'd';
    s3[++ t3] = 'd';
    -- c;
  }

  if (t1 > n || t2 > n || t3 > n) {
    puts("NO");
    return 0;
  }

  while (t1 < n) s1[++ t1] = 'e';
  while (t2 < n) s2[++ t2] = 'f';
  while (t3 < n) s3[++ t3] = 'g';

  puts(s1 + 1);
  puts(s2 + 1);
  puts(s3 + 1);

}