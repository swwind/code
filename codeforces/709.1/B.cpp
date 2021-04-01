#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

set<int> st;
int a[N];

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int nxt[N], prv[N];
int ans[N], fck[N];

int main() {
  int t = read();
  while (t --) {
    int n = read();
    for (int i = 0; i < n; ++ i) {
      a[i] = read();
      nxt[i] = (i + 1) % n;
      prv[(i + 1) % n] = i;
    }

    int cnt = 0, now = 0, cur = 0;
    while (cur <= n) {
      if (gcd(a[now], a[nxt[now]]) == 1) {
        int x = nxt[now];
        ans[++ cnt] = x;
        nxt[prv[x]] = nxt[x];
        prv[nxt[x]] = prv[x];
        cur = 0;

        if (now == x) {
          break;
        }
      }

      now = nxt[now];
      ++ cur;
    }

    // sort(ans + 1, ans + cnt + 1);
    printf("%d", cnt);
    for (int i = 1; i <= cnt; ++ i) {
      printf(" %d", ans[i] + 1);
    }
    puts("");
  }

}
/*
5 9 2 10 15

1-1
1-2
2-3
5-4
5-5


1-1 delete it & *-2
add 1-6

1-6
2-3
5-4
5-5

1-6 delete it & *-3
add 5-11

5-4
5-5
5-11


    1 2
nxt 1 0
prv 1 0

1 2 3 4 5 6
1 3 4 5 6
1 3 5 6
1 3 5
1 5
5
1 2 3 4 5 6 7
1 3 4 5 6 7
1 3 5 6 7
1 3 5 7
3 5 7
3 7
7
*/