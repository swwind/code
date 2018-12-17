// 神題

#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
struct node {
  int a, b, c;
  void init() {
    a = read();
    b = read();
    c = read();
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
  }
  pair<node, int> get_father(int limit) {
    int dep = 0;
    node fake = *this;
    while (limit) {
      int x = fake.b - fake.a, y = fake.c - fake.b;
      if (x == y) break;
      if (x < y) {
        int k = min((y - 1) / x, limit);
        fake.a += k * x;
        fake.b += k * x;
        limit -= k; dep += k;
      } else {
        int k = min((x - 1) / y, limit);
        fake.b -= k * y;
        fake.c -= k * y;
        limit -= k; dep += k;
      }
    }
    return {fake, dep};
  }
  friend bool operator == (const node &a, const node &b) {
    return a.a == b.a && a.b == b.b && a.c == b.c;
  }
  friend bool operator != (const node &a, const node &b) {
    return !(a == b);
  }
} a, b;
int main(int argc, char const *argv[]) {
  a.init(); b.init();
  auto ares = a.get_father(1 << 30);
  auto bres = b.get_father(1 << 30);
  if (ares.first != bres.first)
    return puts("NO"), 0;
  int f1 = ares.second;
  int f2 = bres.second;
  if (f1 < f2) swap(a, b), swap(f1, f2);
  a = a.get_father(f1 - f2).first;
  int l = 0, r = f2;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (a.get_father(mid) == b.get_father(mid)) r = mid;
    else l = mid + 1;
  }
  printf("YES\n%d\n", f1 - f2 + (l << 1));
  return 0;
}

