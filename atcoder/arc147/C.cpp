#include <bits/stdc++.h>
#define N 300050
using namespace std;

int ls[N], rs[N];
int x[N];
int n;

long long calc(int mid) {
  for (int i = 1; i <= n; ++i) {
    if (rs[i] < mid) x[i] = rs[i];
    else if (ls[i] > mid) x[i] = ls[i];
    else x[i] = mid;
  }
  sort(x + 1, x + n + 1);

  long long ans = 0, sum = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (i - 1ll) * x[i] - sum;
    sum += x[i];
  }

  // printf(">> %d is %lld\n", mid, ans);
  // answer = min(answer, ans);
  return ans;
}

int main() {
  scanf("%d", &n);

  int l = INT_MAX, r = INT_MIN;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &ls[i], &rs[i]);
    l = min(l, ls[i]);
    r = max(r, rs[i]);
  }

  while (r - l >= 3) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;

    long long cnt1 = calc(mid1), cnt2 = calc(mid2);
    if (cnt1 < cnt2) r = mid2;
    else l = mid1;
  }

  long long ans = LONG_LONG_MAX;
  for (int i = l; i <= r; ++i) {
    ans = min(ans, calc(i));
  }

  printf("%lld\n", ans);
}