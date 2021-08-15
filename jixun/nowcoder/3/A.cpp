#include <bits/stdc++.h>
using namespace std;

int nolie(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 1;
  if (n == 3) return 2;
  if (n == 4) return 2;
  if (n == 5) return 3;
}
int lie(int n) {
  if (n == 0) return 0;
  if (n == 1) return 3;
  if (n == 2) return 3;
  if (n == 3) return 4;
  if (n == 4) return 4;
  if (n == 5) return 5;
}

int main() {
  int n; scanf("%d", &n);

  for (int i = 1; i <= n; ++ i) {
    printf("%d + %d%c", lie(n-i+1), nolie(i-1), " \n"[i == n]);
  }
}


// 1..n -> y
// x <= y?
// x = 1..n && A always yes
// 1 2 3 4 5 6 7 8 ...
// 1    yes
// (1-4) lie once -> lie[4] = 5
// 2    yes
// (2-4) lie once -> lie[3] = 4
// (1)   no lie   -> nol[1] = 1
// 3    yes
// lie[2] + nol[2] = 4
// lie[2] = 3
// nol[2] = 1
/// lie[4] = no[4] + 
// lie[1] + nol[3] = 3
// 

/*
l[1] = 3
l[2] = 3
l[3] = 4
l[4] = 4
l[5] = 

*/