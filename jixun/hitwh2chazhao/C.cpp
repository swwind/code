#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f?x:-x;
}

int a[102][2020];

struct fuck_you_asshole {
  short v[100];
  short p;
  int value;
  short& operator [] (const int &x) {
    return v[x-1];
  }
  friend bool operator < (const fuck_you_asshole &a, const fuck_you_asshole &b) {
    return a.value > b.value;
  }
  fuck_you_asshole copy() {
    fuck_you_asshole vec;
    memcpy(vec.v, v, sizeof v);
    vec.p = p;
    vec.value = value;
    return vec;
  }
};
priority_queue<fuck_you_asshole> q;
int res[2020];

int main() {

  int T = read();
  while (T --) {
    int n = read(), m = read();
    int sum = 0;
    while (!q.empty()) q.pop();
    // mmp.clear();
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        a[i][j] = read();
      }
      sort(a[i] + 1, a[i] + 1 + m);
      sum += a[i][1];
    }
    fuck_you_asshole vec;
    for (int i = 1; i <= n; ++ i) {
      vec[i] = 1;
    }
    vec.value = sum;
    vec.p = n;
    q.push(vec);
    int cnt = 0;
    // res[cnt] = sum;
    while (cnt < m) {
      fuck_you_asshole s = q.top(); q.pop();
      res[++ cnt] = s.value;
      for (int i = 1; i <= s.p; ++ i) {
        if (s[i] < m) {
          fuck_you_asshole fuck = s.copy();
          ++ fuck[i];
          fuck.p = i;
          fuck.value += a[i][fuck[i]] - a[i][fuck[i]-1];
          q.push(fuck);
        }
      }
    }
    for (int i = 1; i <= cnt; ++ i) {
      printf("%d%c", res[i], " \n"[i == cnt]);
    }
  }
}