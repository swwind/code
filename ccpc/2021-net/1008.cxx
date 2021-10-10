#include <bits/stdc++.h>
#define N 1000020
#define mod 1000000007

using namespace std;

inline long long read(){
	long long x=0;bool f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

int frac[N], invf[N];

int fast_pow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = (long long) x * x % mod) {
    if (y & 1) {
      res = (long long) res * x % mod;
    }
  }
  return res;
}

// res[n] -> ans[n][n]
int res[N];
// ras[n] -> ans[n][2] // 0 0 2 10 46 ..
int ras[N];
// rac[n] -> ans[n][n-2] // 0 2 12 72 ...
int rac[N];

const int inv2 = (mod + 1) / 2;

int work(int n, int m) {
  if (n == m) return res[n];
  if (m == 1) return frac[n];

  int ans = (long long) ras[n-m+2] * rac[m] % mod * inv2 % mod;
  ans = (ans + res[m]) % mod;
  ans = (ans - frac[m] + mod) % mod;
  ans = (ans + (long long) frac[n-m+1] * frac[m] % mod) % mod;
  // printf("%d\n", ras[n-m+2] * rac[m] / 2 + res[m] - frac[m]);
  return ans;
}

const int kMaxN = 1000000;
int main() {
  frac[0] = 1;
  for (int i = 1; i <= kMaxN; ++ i) {
    frac[i] = (long long) frac[i-1] * i % mod;
  }
  invf[kMaxN] = fast_pow(frac[kMaxN], mod - 2);
  for (int i = kMaxN - 1; ~i; -- i) {
    invf[i] = (long long) invf[i+1] * (i+1) % mod;
  }
  
  long long last = 0;
  for (int i = 1; i <= kMaxN; ++ i) {
    last = (last + invf[i]) % mod;
    res[i] = (long long) frac[i] * ((i - last + mod) % mod) % mod;
    res[i] = (res[i] + 1) % mod;
  }

  ras[2] = 0;
  for (int i = 3; i <= kMaxN; ++ i) {
    ras[i] = (ras[i-1] + 2ll * frac[i-3] % mod * (i-3) % mod) % mod;
  }

  for (int i = 1; i <= kMaxN; ++ i) {
    rac[i] = (frac[i+1] + 2ll * frac[i] % mod) % mod;
    rac[i] = (rac[i] - 4ll * frac[i] % mod + mod) % mod;
  }
  // for (int i = 1; i <= 10; ++ i) {
  //   printf("%d\n", ras[i]);
  // }

  int T = read();
  while (T --) {
    int n = read(), m = read();
    printf("%d\n", work(n, m));
  }
  // work(4, 2);
  // for (int n = 1; n <= 9; ++ n) {
  //   printf("n=%d |\t", n);
  //   for (int m = 1; m <= n; ++ m) {
  //     printf("%d%c", work(n, m), "\t\n"[n==m]);
  //   }
  // }
}