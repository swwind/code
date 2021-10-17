#include <bits/stdc++.h>

using namespace std;

char fuck[20];

vector<int> pos, neg;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1, x; i <= n; ++ i) {
    scanf("%s%d", fuck, &x);
    if (fuck[0] == '+') pos.push_back(x);
    else neg.push_back(x);
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());

  long long ans = 0;
  for (size_t ns = 0, ps = 0; ns < neg.size(); ++ ns) {
    while (ps < pos.size() && pos[ps] <= neg[ns]) ++ ps;
    ans += pos.size() - ps;
  }
  printf("%.15lf\n", (double) ans / pos.size() / neg.size());

}