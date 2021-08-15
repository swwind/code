#include <bits/stdc++.h>

using namespace std;

struct Fuck {
  long long a, b;
  long long c;
  friend bool operator < (const Fuck &a, const Fuck &b) {
    return a.b > b.b;
  }
};

priority_queue<Fuck> fuck;

struct Pair {
  long long n;
  int pos;
} a[100020];

bool cmp(const Pair &a, const Pair &b) {
  return a.n < b.n;
}

int ans[100020];

int main() {
  int n; cin >> n;
  long long mx = 0;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i].n;
    a[i].pos = i;
    mx = max(mx, a[i].n);
  }
  sort(a + 1, a + n + 1, cmp);

  for (long long i = 2; i * i * i <= mx; ++ i) {
    fuck.push({ i, i * i * i, i * i });
  }

  int res = 1;
  for (int i = 1; i <= n; ++ i) {
    while (!fuck.empty() && fuck.top().b <= a[i].n) {
      Fuck damn = fuck.top();
      fuck.pop();
      ++ res;
      if (damn.b - 1 >= (mx + damn.a) / damn.c) {
        continue;
      }
      fuck.push({ damn.b, damn.b * damn.c - damn.a, damn.c });
    }
    ans[a[i].pos] = res;
  }

  for (int i = 1; i <= n; ++ i) {
    printf("%d\n", ans[i]);
  }
}
