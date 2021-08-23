/*

we have EX

open w[1..n]
know C

EX -> x remaining

cost C -> if C = x with P = (1/2)^x then we know the answer
          if C = 0 with P = (1/2)^x then we know the answer



*/

#include <bits/stdc++.h>
#define N 100020

using namespace std;

double w[N];

int main() {
  int n; double c;
  cin >> n >> c;
  double ans1 = 0;
  for (int i = 1; i <= n; ++ i) {
    cin >> w[i];
  }
  sort(w + 1, w + n + 1);
  for (int i = 1; i <= n; ++ i) {
    ans1 += w[i];
    w[i] += w[i-1];
  }

  double ans2 = c;
  for (int i = 0; i < n; ++ i) {
    double p = pow(0.5, min(n-i+1, n))*2;
    ans2 += p * w[i];
    // cout << p << ", " << w[i] << endl;
  }

  printf("%.10f\n", min(ans1, ans2));
}
/*
00
01
10
11
*/