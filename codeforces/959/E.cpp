#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
ll n, ans, cnt;
int main(int argc, char const *argv[]) {
  cin >> n;
  for (int i = 1; i <= 60; i++) {
    ll s = (n>>i)+(n-((n>>i)<<i)>(1ll<<i-1));
    ans += s << i-1;
  }
  cout << ans << endl;
  return 0;
}