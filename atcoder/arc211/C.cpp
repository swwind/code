#include <bits/stdc++.h>
#include <cstdio>

#define N 200030

char s[N];
long long r[N];
long long dp[N];

long long a[N];
long long ac[N];
int cnt;
long long kk[N];
// long long kp[N];
// long long ks[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &r[i]);

  int st = 1;
  int ed = n;
  while (st <= n && s[st] == '#')
    st++;
  while (ed >= 1 && s[ed] == '#')
    ed--;

  if (st > ed) {
    puts("0");
    return 0;
  }

  long long mx = r[st];
  long long mxcnt = 1;
  for (int i = st + 1; i <= ed; ++i) {
    if (s[i] != s[i - 1]) {
      a[++cnt] = mx;
      ac[cnt] = mxcnt;
      mx = r[i];
      mxcnt = 1;
    } else {
      if (r[i] > mx) {
        mx = r[i];
        mxcnt = 1;
      } else if (r[i] == mx) {
        mxcnt += 1;
      }
    }
  }
  a[++cnt] = mx;
  ac[cnt] = mxcnt;

  // for (int i = 1; i <= cnt; ++i) {
  //   printf("%lld - %lld\n", a[i], ac[i]);
  // }

  for (int i = 2; i <= cnt; i += 2) {
    kk[i] = std::max(a[i - 1], std::max(a[i], a[i + 1]));
  }

  // kp[2] = kk[2];
  // for (int i = 4; i <= cnt; i += 2) {
  //   kp[i] = std::max(kk[i], kp[i - 2]);
  // }
  // ks[cnt - 1] = kk[cnt - 1];
  // for (int i = cnt - 3; i >= 1; i -= 2) {
  //   ks[i] = std::max(kk[i], ks[i + 2]);
  // }

  mx = 0;
  mxcnt = 0;
  for (int i = 2; i <= cnt; i += 2) {
    if (kk[i] > mx) {
      mx = kk[i];
      mxcnt = ac[i - 1] * ac[i + 1];
    } else if (kk[i] == mx) {
      mxcnt += ac[i - 1] * ac[i + 1];
    }
  }

  printf("%lld\n", mxcnt);
}
