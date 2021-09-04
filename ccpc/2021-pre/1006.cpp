#include <bits/stdc++.h>

using namespace std;

int sqr[1005];
long long sum[1005];
bool dp[4000020];
int pre[4000020];

int ans[1020];

int main() {

  for (int i = 1; i <= 1000; ++ i) {
    sqr[i] = i * i;
    sum[i] = sum[i-1]+sqr[i];
    // if (sum[i] > 4000000) {
    //   printf("sum[%d] = %d\n", i, sum[i]);
    //   break;
    // }
  }
  // int end = 144;
  dp[0] = 1;
  for (int i = 1; i <= 1000; ++ i) {
    for (int j = 1000000 - sqr[i]; j >= 0; -- j) {
      if (dp[j] && !dp[j + sqr[i]]) {
        dp[j + sqr[i]] = 1;
        pre[j + sqr[i]] = i;
      }
    }
  }

  int t; scanf("%d", &t);
  while (t --) {
    int n; scanf("%d", &n);
    // printf("read %d\n", n);

    int k = 1;
    while (sum[k] < n) ++ k;

    // know k is the first number which sum[k] >= n
    while (true) {
      if ((sum[k]+n)&1) {++k;continue;}
      int a = (sum[k]+n)/2;
      int b = (sum[k]-n)/2;
      // if (b < 0) assert(false);
      if (dp[b]) {
        for (int i = 1; i <= k; ++ i) {
          ans[i] = 1;
        }
        int i = pre[b];
        int x = b;
        while (x) {
          ans[i] = 0;
          x -= sqr[i];
          i = pre[x];
        }
        printf("%d\n", k);
        // long long sum = 0;
        for (int i = 1; i <= k; ++ i) {
          printf("%d", ans[i]);
          // if (ans[i]) sum += sqr[i];
          // else sum -= sqr[i];
        }
        puts("");
        // printf("sum = %lld\n", sum);
        // printf("n = %d\n", n);
        // assert(sum == n);
        break;
      }
      ++ k;
    }
  }

}