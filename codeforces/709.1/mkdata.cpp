#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(0));
  int t = 20;
  cout << t << endl;
  while (t --) {
    int n = 1000;
    cout << n << endl;
    for (int i = 1; i <= n; ++ i) {
      cout << rand() % 2 + 1 << " \n"[i == n];
    }
  }
}
