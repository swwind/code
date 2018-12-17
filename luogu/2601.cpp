#include <bits/stdc++.h>
#define XP 87
#define YP 79
#define N 1020
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
typedef unsigned int uii;

int mp[N][N];
int rmp[N][N];
int dmp[N][N];

uii pw[N][N];
uii hmp[N][N];
uii hrmp[N][N];
uii hdmp[N][N];

int n, m;

inline void calc_hash(int mp[N][N], uii hsh[N][N]) {
  for (int i = n; i; -- i) {
    for (int j = m; j; -- j) {
      hsh[i][j] = mp[i][j]
        + hsh[i + 1][j] * YP
        + hsh[i][j + 1] * XP
        - hsh[i + 1][j + 1] * XP * YP;
    }
  }
}

inline uii get_hash(uii hsh[N][N], int fx, int fy, int tx, int ty) {
  uii res = hsh[fx][fy];
  res -= hsh[fx][ty + 1]     * pw[0][ty - fy + 1];
  res -= hsh[tx + 1][fy]     * pw[tx - fx + 1][0];
  res += hsh[tx + 1][ty + 1] * pw[tx - fx + 1][ty - fy + 1];
  return res;
}

int main(int argc, char const *argv[]) {
  
  // initalize
  n = read();
  m = read();

  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      mp[i][j] = rmp[i][m - j + 1] = dmp[n - i + 1][j] = read();
    }
  }

  // pw(i,j) means x^i * y^j
  pw[0][0] = 1;
  for (int i = 1; i <= m; ++ i) {
    pw[0][i] = XP * pw[0][i - 1];
  }
  for (int i = 1; i <= n; ++ i) {
    pw[i][0] = YP * pw[i - 1][0];
    for (int j = 1; j <= m; ++ j) {
      pw[i][j] = XP * pw[i][j - 1];
    }
  }

  // end initalize

  // calculate hash value of each array
  calc_hash(mp, hmp);
  calc_hash(rmp, hrmp);
  calc_hash(dmp, hdmp);

  int ans = 0;

  // enumerate each points
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {

      // bisect
      int l = 1;
      int r = min(min(i, n - i + 1), min(j, m - j + 1)) + 1;

      while (r != l) {

        int mid = (l + r) >> 1;

        uii ha = get_hash(hmp, i - mid + 1, j - mid + 1, i + mid - 1, j + mid - 1);
        uii hb = get_hash(hrmp, i - mid + 1, m - j - mid + 2, i + mid - 1, m - j + mid);
        uii hc = get_hash(hdmp, n - i - mid + 2, j - mid + 1, n - i + mid, j + mid - 1);

        if (ha == hb && hb == hc) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }

      ans += l - 1;
    }
  }

  // enumerate each four points
  for (int i = 1; i < n; ++ i) {
    for (int j = 1; j < m; ++ j) {

      // bisect
      int l = 1;
      int r = min(min(i, n - i), min(j, m - j)) + 1;

      while (r != l) {

        int mid = (l + r) >> 1;

        uii ha = get_hash(hmp, i - mid + 1, j - mid + 1, i + mid, j + mid);
        uii hb = get_hash(hrmp, i - mid + 1, m - j - mid + 1, i + mid, m - j + mid);
        uii hc = get_hash(hdmp, n - i - mid + 1, j - mid + 1, n - i + mid, j + mid);

        if (ha == hb && hb == hc) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }

      ans += l - 1;
    }
  }

  // print the ans
  cout << ans << endl;

  return 0;
}