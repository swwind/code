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
  int s, w, id;
  friend bool operator < (const node &a, const node &b) {
    return a.s == b.s ? a.id < b.id : a.s > b.s;
  }
}a[N<<1];
int main(int argc, char const *argv[]) {
  // freopen("C:\\Users\\SW_Wind\\Downloads\\testdata (1).in", "r", stdin);
  int n = read() * 2, r = read(), q = read();
  for (int i = 1; i <= n; i++) {
    a[i].id = i;
    a[i].s = read();
  }
  for (int i = 1; i <= n; i++)
    a[i].w = read();
  while (r --) {
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i += 2) {
      if (a[i].w > a[i + 1].w) a[i].s ++;
      else a[i + 1].s ++;
    }
  }
  sort(a + 1, a + n + 1);
  cout << a[q].id << endl;
  return 0;
}