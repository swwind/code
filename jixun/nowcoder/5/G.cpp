#include <bits/stdc++.h>
using namespace std;

inline int read_i32(){
	int x=0;bool f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

inline __int128_t read_u128(){
	__int128_t x=0;bool f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

char str[2000];
void print_i128(__int128_t x) {
  if (x == 0) {
    puts("0");
    return;
  }
  vector<char> vec;
  while (x > 0) {
    vec.push_back((x % 10) + '0');
    x /= 10;
  }
  reverse(vec.begin(), vec.end());
  for (char c : vec) {
    putchar(c);
  }
  putchar('\n');
}

int n;
int p[20], q[20];
__int128_t a, b;
__int128_t fa[1<<18], fb[1<<18];

__int128_t fmin(__int128_t a, __int128_t b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return min(a, b);
}

void dfs(int dep, int bit, __int128_t v) {
  if (dep == n) {
    if (v >= a) {
      fa[bit] = fmin(fa[bit], v - a);
    }
    if (v >= b) {
      fb[bit] = fmin(fb[bit], v - b);
    }
    return;
  }

  for (int i = 0; i <= q[dep]; ++ i) {
    dfs(dep + 1, i == q[dep] ? bit | (1 << dep) : bit, v);
    v *= p[dep];
  }
}

int main() {
  n = read_i32();
  for (int i = 0; i < n; ++ i) {
    p[i] = read_i32();
    q[i] = read_i32();
  }
  a = read_u128();
  b = read_u128();

  for (int i = 0; i < (1 << n); ++ i) {
    fa[i] = fb[i] = -1;
  }

  dfs(0, 0, 1);

  for (int i = (1 << n) - 1; ~i; -- i) {
    for (int j = 0; j < n; ++ j) {
      if (!((i >> j) & 1)) {
        fa[i] = fmin(fa[i], fa[i^(1<<j)]);
        fb[i] = fmin(fb[i], fb[i^(1<<j)]);
      }
    }
  }

  int full = (1 << n) - 1;
  __int128_t ans = -1;

  for (int i = 0; i < (1 << n); ++ i) {
    ans = fmin(ans, fa[i] + fb[full^i]);
  }

  print_i128(ans);
}
