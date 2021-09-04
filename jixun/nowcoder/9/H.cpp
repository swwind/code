#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void dfs(int x) {

  int fuck = 3;
  int total = 3;
  while (x >= total) {
    fuck *= 3;
    total += fuck;
  }

  if (x < total) {
    int damn = fuck / 3;
    int y = x - (total - fuck);
    ans.push_back(y / damn);
    // total = 3, fuck = 3, damn = 1, y = x
    // total = 12, fuck = 9, damn = 3, y = x - 3
    if (damn > 1) {
      dfs(total - fuck - damn + y % damn);
    }
  }
}

int main() {
  int k; cin >> k; --k;
  dfs(k);
  for (int i = 0; i < ans.size(); ++i) {
    putchar("236"[ans[i]]);
  }
  putchar('\n');
}


/*

2   0 = 0
3   1 = 1
6   2 = 2
22  3 = 0 0
23  4 = 0 1
26  5 = 0 2
32  6 = 1 0
33  7 = 1 1
36  8 = 1 2
62  9 = 2 0
63  10 = 2 1
66  11 = 2 2
222 12 = 0 0 0

*/