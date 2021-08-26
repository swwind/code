#include <bits/stdc++.h>

const int mod = 4933;

// read a int
int readInt() {
  int res = 0;
  char ch;
  while (1) {
    ch = getchar(); 
    if (ch == '\n' || ch == ' ')
      break;
    res = res * 10 + ch - '0';
  }
  return res;
}

// fast pow
int fast_pow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1)
      res = (long long) res * x % mod;
    x = (long long) x * x % mod;
    y >>= 1;
  }
  return res;
}

// get inverse of a int
int get_inverse(int x) {
  return fast_pow(x, mod - 2);
}

int main() {
  int n = readInt();
  int m = readInt();
  int k = readInt();
  int a = readInt();
  int l = readInt();
  int ans = 1;
  for (int i = 0; i < k; i++) {
    int x = readInt();
    int y = readInt();
    int z = readInt();

    int res = (long long) (z - y) * get_inverse(z) % mod;
    if (x) ans = (long long) ans * res % mod;
  }
  ans = (ans + a) % mod;
  printf("%d\n", ans);
  return 0;
}