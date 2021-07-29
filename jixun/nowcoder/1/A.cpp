#include <bits/stdc++.h>
using namespace std;

bool f[5001][5001];
// bool g[5001][5001];

// int work(int n, int m) {
//   if (n > m) swap(n, m);
//   if (n == 0 || n == 1) return 1;
//   if (m % n == 0) return 1;
//   if (f[n][m]) return g[n][m];

//   int res = 0;
//   for (int i = 0; i < n && !res; ++ i) {
//     for (int j = 0; j <= m && !res; j += n-i) {
//       if (!work(i, m-j)) {
//         res = 1;
//       }
//     }
//   }
//   for (int i = 0; i < m && !res; ++ i) {
//     for (int j = 0; j <= n && !res; j += m-i) {
//       if (!work(n-j, i)) {
//         res = 1;
//       }
//     }
//   }
//   f[n][m] = 1;
//   g[n][m] = res;
//   return res;
// }

void dabiao() {
  for (int n = 1; n <= 5000; ++ n) {
    for (int m = 1; m <= 5000; ++ m) {
      if (n%m == 0 || m%n == 0) f[n][m]=1;
      if (!f[n][m]) {
        // (n, m) is Bob
        for (int i = 1; n+i <= 5000; ++ i) {
          for (int j = 0; m+j <= 5000; j += i) {
            f[n+i][m+j] = 1;
          }
        }
        for (int i = 1; m+i <= 5000; ++ i) {
          for (int j = 0; n+j <= 5000; j += i) {
            f[n+j][m+i] = 1;
          }
        }
      }
    }
    // printf("%d\n", n);
  }
}

int main() {
  dabiao();
  int T; cin >> T;
  // for (int i = 1; i <= 5000; ++ i) {
  //   for (int j = i; j <= 5000; ++ j) {
  //     if (!work(i, j)) {
  //       printf("%d %d\n", i, j);
  //     }
  //   }
  // }
  while (T --) {
    int n, m;
    cin >> n >> m;
    puts(f[n][m] ? "Alice" : "Bob");
  }
}

/*
0 x -> Alice
1 x -> Alice
2 2x -> Alice
2 2x+1 -> 2 2x-1 -> ... -> 2 3 -> 2 1 -> ...
2 1 -> Alice
2 3 -> Bob
2 2x+1
| odd  x = Bob
| even x = Alice

3 3x -> Alice

3 0 -> Alice
3 1 -> Alice
3 2 -> Bob
3 3x+1 -> 3 3x+1 / 3 3x+2 (self profit)
3 3x+2 -> 3 3x+1 / 3 3x+2 (self profit)

3 1/2 -> Alice/Bob
3 4 -> 3 2 -> Alice
3 5 -> 3 2 -> Alice
3 7 -> 3 5 -> Alice
3 8 -> 3 5 -> Alice

4 0 -> Alice
4 1 -> Alice
4 2 -> Alice
4 3 -> Alice

4 5 -> Bob
4 6 -> Bob
4 7 -> 2 3 -> Alice

*/