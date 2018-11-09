#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline ll read(){
  ll x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
ll maxe;
struct Answer {
  long long a[5];
  inline long long& operator [] (int x) {
    return a[x];
  }
  inline void sort() {
    std::sort(a, a + 5);
  }
  friend bool operator < (Answer a, Answer b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    if (a[2] != b[2]) return a[2] < b[2];
    if (a[3] != b[3]) return a[3] < b[3];
    return a[4] < b[4];
  }
  inline bool valid() const {
    for (int i = 0; i < 4; ++ i) {
      if (a[i] == a[i + 1]) {
        return false;
      }
    }
    return true;
  }
};
set<Answer> mp;
void dfs(Answer sol) {
  // puts("fake");
  // if (dep > 3) return;
  sol.sort();
  // printf("%lld %lld %lld %lld %lld\n", sol[0], sol[1], sol[2], sol[3], sol[4]);
  if (mp.count(sol)) {
    return;
  }
  mp.insert(sol);
  for (int i = 0; i < 5; ++ i) {
    ll temp = maxe + sol[i];
    for (int j = 0; j < 5; ++ j) {
      if (j != i) {
        temp /= sol[j];
      }
    }
    if (!temp) continue;
    ll photoshop = 1;
    for (int j = 0; j < 5; ++ j) {
      if (j != i) {
        photoshop *= sol[j];
      }
    }
    Answer just;
    just[i] = photoshop - sol[i];
    for (int j = 0; j < 5; ++ j) {
      if (j != i) {
        just[j] = sol[j];
      }
    }
    dfs(just);
  }
  // puts("genuine");
}
int main(int argc, char const *argv[]) {
  maxe = read();
  dfs((Answer) {1, 1, 3, 3, 4});
  int ans = 0;
  for (auto it = mp.begin(); it != mp.end(); ++ it) {
    if (it -> valid()) {
      ++ ans;
    }
  }
  if (ans) {
    printf("%d\n", ans);
    for (auto it = mp.begin(); it != mp.end(); ++ it) {
      if (it -> valid()) {
        printf("%lld %lld %lld %lld %lld\n", it -> a[0], it -> a[1], it -> a[2], it -> a[3], it -> a[4]);
      }
    }
  } else {
    puts("No Solution");
  }
  return 0;
}