#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int v = abs(n - m);

  puts((v&1) ? "Alice" : "Bob");
}