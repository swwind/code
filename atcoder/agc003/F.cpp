#include <bits/stdc++.h>
#define N 1020
#define mod 1000000007
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

char str[N];
bool mp[N][N];

ll fast_pow(ll x, ll y) {
  ll z = 1;
  for (y = y % (mod - 1); y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      z = z * x % mod;
    }
  }
  return z;
}

struct Matrix {

  int num[2][2];

  void clear() {
    memset(num, 0, sizeof num);
  }

  Matrix() {
    clear();
  }

  Matrix(bool flag) {
    clear();
    for (int i = 0; i < 2; ++ i) {
      num[i][i] = 1;
    }
  }

  int* operator [] (int i) {
    return num[i];
  }

  friend Matrix operator * (Matrix a, Matrix b) {
    Matrix c;
    for (int k = 0; k < 2; ++ k) {
      for (int i = 0; i < 2; ++ i) if (a[i][k]) {
        for (int j = 0; j < 2; ++ j) if (b[k][j]) {
          c[i][j] = (c[i][j] + (ll) a[i][k] * b[k][j]) % mod;
        }
      }
    }
    return c;
  }

  friend Matrix operator ^ (Matrix a, ll b) {
    Matrix c(true);
    for (; b; b >>= 1, a = a * a) {
      if (b & 1) {
        c = c * a;
      }
    }
    return c;
  }


  void debug_print() {
    for (int i = 0; i < 2; ++ i) {
      printf("| ");
      for (int j = 0; j < 2; ++ j) {
        printf("%d ", num[i][j]);
      }
      printf("|\n");
    }
  }

};

int resolve(int v, int ud, int ev, ll k) {
  Matrix T;
  T[0][0] = v;
  T[0][1] = ev;
  T[1][1] = ud;

  Matrix A;
  A[0][0] = v;
  A[0][1] = ev;
  A[1][1] = 1;

  Matrix res = A * (T ^ (k - 2));

  return (res[0][0] - res[0][1] + mod) % mod;
}

int main(int argc, char const *argv[]) {
  int h = read(), w = read();
  ll k = read();
  int v = 0;
  for (int i = 1; i <= h; ++ i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= w; ++ j) {
      mp[i][j] = str[j] == '#';
      v += mp[i][j];
    }
  }
  int lr = 0, ud = 0;
  for (int i = 1; i <= h; ++ i) {
    lr += mp[i][1] && mp[i][w];
  }
  for (int i = 1; i <= w; ++ i) {
    ud += mp[1][i] && mp[h][i];
  }

  if (lr && ud || k == 1) {
    puts("1");
  } else if (!lr && !ud) {
    printf("%lld\n", fast_pow(v, k - 1));
  } else {
    int ev = 0;
    for (int i = 1; i <= h; ++ i) {
      for (int j = 1; j <= w; ++ j) {
        ev += lr ? (mp[i][j] && mp[i][j + 1]) : (mp[i][j] && mp[i + 1][j]);
      }
    }
    int res = resolve(v, max(lr, ud), ev, k);
    printf("%d\n", res);
  }


  return 0;
}
/*
题目应该是保证了初始图连通的吧

分 3 种情况讨论

(let v = 黑色数量)

1)
  原图在边缘部分不连通

  ...
  .#.
  ...

  那么答案显然就是 v^(k-1)

2)
  原图四个方向都连通

  .#.
  ###
  .#.

  图永远连通，答案为 1

3)
  原图仅有上下（或左右）连通

  .#.
  .#.
  .#.

  左右和上下可以通过旋转 90° 合并成同一种情况

  当前假设只有上下连通

  对于连通数，我们有一个公式：

    C     = V   - E
    连通数 = 点数 - 边数

  我们只需要维护点数(V)和边数(E)即可。

  考虑递推式，

    Vk = V(k-1) * v               ,    V1 = v
    Ek = E(k-1) * ud + V(k-1) * ev,    E1 = ev

  (let ud = 上下边缘处相交的黑格数量,
       ev = 上下相邻的黑格数量)

  For example

         .#.
         ###
         #.#

    V1 = 6
    E1 = 2
    C1 = 4

      ....#....
      ...###...
      ...#.#...
      .#..#..#.
      #########
      #.##.##.#
      .#.....#.
      ###...###
      #.#...#.#

    V2 = 36
    E2 = 2*2+6*2 = 16
    C2 = V2 - E2 = 20

  两个用矩乘一起算即可。

  附转移矩阵：

    | v  ev |
    | 0  ud |

  总复杂度 O(WH+logk)

*/