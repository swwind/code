#include <bits/stdc++.h>
using namespace std;

int f[102];

long long work(long long x) {
  if (x <= 99) return f[x];
  return f[99] + (x - 99);
}

bool fuck(int a) {
  return a % 3 == 0;
}

int main() {

  // for (int i = 100; i <= 999; ++ i) {
  //   int a = i/100;
  //   int b = (i/10)%10;
  //   int c = i%10;
  //   bool check = fuck(a) || fuck(b) || fuck(c) || fuck(a*10+b) || fuck(b*10+c) || fuck(a*100+b*10+c);
  //   if (!check) {
  //     printf("Fuck %d\n", i);
  //   }
  // }
  // puts("pass");

  int T; cin >> T;

  for (int i = 1; i <= 99; ++ i) {
    if (i%3 == 0 || (i%10)%3 == 0 || (i>9&&(i/10)%3==0)) {
      f[i] = f[i-1]+1;
    } else {
      f[i] = f[i-1];
    }
  }

  while (T --) {
    long long l, r;
    cin >> l >> r;
    printf("%lld\n", work(r) - work(l-1));
  }
}
