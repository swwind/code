#include <bits/stdc++.h>
using namespace std;
int a[] = { 0, 7, 27, 41, 49, 63, 78, 108 };

// read a int t, and do the following t times
// 1. read a int n
// 2. read n integeres and calculate the sum of a[x]
// 3. if the sum greater than 120, than subtract the sum by 50
// 4. else if the sum greater than 89, than subtract the sum by 30
// 5. else if the sum greater than 69, than subtract the sum by 15
// 6. output the sum
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    while (n--) {
      int x;
      cin >> x;
      sum += a[x];
    }
    if (sum >= 120)
      sum -= 50;
    else if (sum >= 89)
      sum -= 30;
    else if (sum >= 69)
      sum -= 15;
    cout << sum << endl;
  }
  return 0;
}