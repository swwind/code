#include <cstdio>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}

// 1 2 3 4 5 6 7 8 9
// A B C D E F G H I

int a[11];
int prv[4] = { 3, 0, 1, 2 };
int nxt[4] = { 1, 2, 3, 0 };

int mp[9][9] = {
/// A  B  C  D  E  F  G  H  I
  { 1, 1, 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 0, 1, 1, 0, 0, 0 },
  { 1, 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 1, 1, 1, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
  { 0, 0, 0, 0, 1, 1, 0, 1, 1 },
};

int used[11];

int bestsum = 600, best[11];

void dfs(int d) {
  if (d == 10) {
    int total = 0, sum = 0;
    for (int i = 1; i <= 9; ++ i) {
      total += a[i];
      sum += used[i];
    }
    if (!total) {
      if (sum < bestsum) {
        for (int i = 1; i <= 9; ++ i) {
          best[i] = used[i];
        }
      } else if (sum == bestsum) {
        // assert(false);
        puts("I love ya");
      }
    }

    return;
  }

  for (int i = 0; i < 4; ++ i) {
    used[d] = i;
    dfs(d + 1);
    for (int j = 1; j <= 9; ++ j) {
      if (mp[d - 1][j - 1]) {
        a[j] = nxt[a[j]];
      }
    }
  }
}

int main() {
  for (int i = 1; i <= 9; ++ i) scanf("%d", a + i);

  dfs(1);

  for (int i = 1; i <= 9; ++ i) {
    for (int j = 1; j <= best[i]; ++ j) {
      printf("%d ", i);
    }
  }
}