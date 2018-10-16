#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
char str[N];
vector<int> vec[N];
int main(int argc, char const *argv[]) {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  int cnt = 0, mxt = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') {
      vec[++ cnt].push_back(i);
      mxt = max(mxt, cnt);
    } else {
      if (!cnt) return puts("-1"), 0;
      vec[cnt --].push_back(i);
    }
  }
  if (cnt < mxt)
    return puts("-1"), 0;
  cout << mxt << endl;
  for (int i = 1; i <= cnt; i++) {
    cout << vec[i].size();
    for (auto x : vec[i])
      cout << " " << x;
    cout << endl;
  }
  return 0;
}