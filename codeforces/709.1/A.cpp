#include <bits/stdc++.h>
#define N 500020
#define int long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

set<long long> st;
int a[N];

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int nxt[N], prv[N];
int ans[N];
long long fck[N];

signed main() {
  int t = read();
  while (t --) {
    int n = read();
    for (int i = 0; i < n; ++ i) {
      a[i] = read();
      nxt[i] = (i + 1) % n;
      prv[(i + 1) % n] = i;
    }

    st.clear();

    for (int i = 0; i < n; ++ i) {
      if (gcd(a[i], a[nxt[i]]) == 1) {
        st.insert(i);
        // printf("%d %d are prime\n", a[i], a[nxt[i]]);
      }
      fck[i] = i;
    }
    // cout << st.size() <<  "fuck" << endl;

    int cnt = 0;
    while (st.size() > 0) {
      long long top = *st.begin();
      st.erase(st.begin());
      // remove point x
      int x = nxt[top % n];
      ans[++ cnt] = x;
      nxt[prv[x]] = nxt[x];
      prv[nxt[x]] = prv[x];
      // puts("fuck ss");
      st.erase(fck[x]);
      // puts("fuck dd");

      if (top % n == x) continue;

      if (gcd(a[top % n], a[nxt[top % n]]) == 1) {
        st.insert(top + n);
        fck[top % n] = top + n;
      }
    }

    // sort(ans + 1, ans + cnt + 1);
    // printf("%d", cnt);
    cout << cnt;
    for (int i = 1; i <= cnt; ++ i) {
      // printf(" %d", ans[i] + 1);
      cout << " " << ans[i] + 1;
    }
    // puts("");
    cout << endl;
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




for each e i want to know if exists (u, v, l) suits

dis(x, u) + w[x][y] + dis(y, v) <= l

*/