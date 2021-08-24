#include <bits/stdc++.h>
#define N 100020

using namespace std;

struct Cake {
  int t, id;
  friend bool operator < (const Cake &a, const Cake &b) {
    return a.t == b.t ? a.id < b.id : a.t > b.t;
  }
} cake[N];

struct Spot {
  int time, id;
  friend bool operator < (const Spot &a, const Spot &b) {
    return a.time == b.time ? a.id > b.id : a.time > b.time;
  }
};

priority_queue<Spot> q;

struct Ans {
  int k;
  int id;
  long long s1, s2;
  long long e1, e2;
  Ans(){}
  Ans(int id, long long s1, long long e1):k(1),id(id),s1(s1),e1(e1){}
  Ans(int id, long long s1, long long e1, long long s2, long long e2)
    :k(2),id(id),s1(s1),e1(e1),s2(s2),e2(e2){}
} ans[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  long long total = 0;
  int mx = 0;
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", &cake[i].t);
    mx = max(mx, cake[i].t);
    total += cake[i].t;
    cake[i].id = i;
  }
  sort(cake + 1, cake + n + 1);

  long long length = max((long long) mx, (total - 1) / m + 1);

  int now = 1;

  for (int i = 1, last = 0; i <= m && now <= n; ++ i) {
    while (now <= n && cake[now].t <= length - last) {
      ans[cake[now].id] = Ans(i, length - last - cake[now].t, length - last);
      last += cake[now].t;
      ++ now;
    }
    if (now <= n && last < length) {
      // still have remaining
      // ans[cake[l].id] = Ans(i, 0, length - last, cake[l].t - (length - last), length);
      // last = cake[l].t - (length - last);
      // ++ l;
      ans[cake[now].id] = Ans(i, 0, length - last, length - (cake[now].t - (length - last)), length);
      last = cake[now].t - (length - last);
      ++ now;
    } else {
      last = 0;
    }
  }

  for (int i = 1; i <= n; ++ i) {
    if (ans[i].k == 1) {
      printf("1 %d %d %d\n", ans[i].id, ans[i].s1, ans[i].e1);
    } else {
      printf("2 %d %d %d %d %d %d\n", ans[i].id, ans[i].s1, ans[i].e1, ans[i].id + 1, ans[i].s2, ans[i].e2);
    }
  }

  /*
  for (int i = 1; i <= m; ++ i) {
    q.push({ 0, i });
  }

  for (int i = 1; i <= n; ++ i) {
    Spot spot = q.top();
    q.pop();

    ansid[cake[i].id] = spot.id;
    ansl[cake[i].id] = spot.time;
    ansr[cake[i].id] = spot.time + cake[i].t;

    q.push({ spot.time + cake[i].t, spot.id });
  }

  for (int i = 1; i <= n; ++ i) {
    printf("1 %d %d %d\n", ansid[i], ansl[i], ansr[i]);
  }
  */
}