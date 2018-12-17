#include <bits/stdc++.h>
#define N 500020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
multiset<int> st1, st2, st3;
int st[N], ed[N];
char str[N];
void del1(int x) {
  st1.erase(st1.find(x));
}
void add1(int x) {
  st1.insert(x);
}
void del2(int x) {
  st2.erase(st2.find(x));
}
void add2(int x) {
  st2.insert(x);
}
void del3(int x) {
  st3.erase(st3.find(x));
}
void add3(int x) {
  st3.insert(x);
}
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    st[i] = ed[i] = read();
    add2(abs(st[i]));
  }
  for (int i = 1; i < n; i++)
    add1(abs(ed[i] - st[i + 1]));
  multiset<int>::iterator it = st2.begin();
  int lst = *it; ++ it;
  while (it != st2.end()) {
    int now = *it; ++ it;
    add3(abs(lst - now));
    lst = now;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%s", str + 1);
    if (str[1] == 'I') {
      int p = read();
      int x = read();
      if (p == n) {
        add1(abs(ed[p] - x));
        ed[p] = x;
      } else {
        del1(abs(ed[p] - st[p + 1]));
        add1(abs(ed[p] - x));
        add1(abs(x - st[p + 1]));
        ed[p] = x;
      }
      add2(x);
      it = st2.find(x);
      int pre = 0, nxt = 0;
      if (it != st2.begin()) {
        pre = *-- it;
        ++ it;
      }
      if (it != --st2.end()) {
        nxt = *++ it;
        -- it;
      }
      // printf("%d %d\n", pre, nxt);
      if (pre && nxt)
        del3(abs(pre - nxt));
      if (pre)
        add3(abs(x - pre));
      if (nxt)
        add3(abs(nxt - x));
    } else if (str[5] == 'G') {
      printf("%d\n", *st1.begin());
    } else {
      printf("%d\n", *st3.begin());
    }
  }
  return 0;
}