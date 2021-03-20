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

string str[N];

int def[10][10];
int a[10], b[10];

int main() {
  int T = read();
  for (int cs = 1; cs <= T; ++ cs) {
    int n = read();
    memset(def, 0, sizeof def);
    string beststr;
    for (int i = 1; i <= n; ++ i) {
      cin >> str[i];
      a[i] = i;
    }
    for (int i = 1; i <= n; ++ i) {
      int x = read();
      for (int j = 1; j <= x; ++ j) {
        string ss; cin >> ss;
        for (int k = 1; k <= n; ++ k) {
          if (str[k] == ss) {
            def[i][k] = 1;
          }
        }
      }
    }

    do {

      int suck = 1;

      for (int i = 1; i <= n; ++ i) {
        b[i] = i;
      }

      do {
        
        int k1 = 1, k2 = 1;
        while (k1 <= n && k2 <= n) {
          if (def[b[k2]][a[k1]]) ++ k1;
          else ++ k2;
        }
        
        suck &= k2 > n;

      } while (suck && next_permutation(b + 1, b + n + 1));

      if (suck) {
        string now = "";
        for (int i = 1; i <= n; ++ i) {
          now += str[a[i]];
          if (i < n) now += " ";
        }

        if (!beststr.length() || now < beststr) {
          beststr = now;
        }
      }

    } while (next_permutation(a + 1, a + n + 1));

    printf("Case %d: %s\n", cs, beststr.length() > 0 ? "Yes" : "No");
    if (beststr.length()) {
      cout << beststr << endl;
    }
  }
}
