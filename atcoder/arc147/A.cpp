#include <bits/stdc++.h>
#define N 200020
using namespace std;

int a[N];

struct vec {
  int x, y;
  friend bool operator < (const vec& a, const vec& b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  }
};

set<vec> st;

int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    st.insert((vec) { x, i });
  }

  int ans = 0;
  while (st.size() > 1) {
    set<vec>::iterator sm = st.begin();
    set<vec>::iterator lg = --st.end();

    int res = lg->x % sm->x;

    if (res == 0) {
      st.erase(lg);
    }
    else {
      st.insert((vec) { res, lg->y });
      st.erase(lg);
    }

    ans++;
  }

  printf("%d\n", ans);

}