#include <bits/stdc++.h>
#define N 200020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int s[N], w[N];
int b[N], c[N], d[N];
bool cmp(int x, int y) {
  return s[x] == s[y] ? x < y : s[x] > s[y];
}
int main(int argc, char const *argv[]) {
  int n = read(), r = read(), q = read(), n2 = n << 1;
  for (int i = 1; i <= n2; i++)
    s[i] = read();
  for (int i = 1; i <= n2; i++)
    w[i] = read();
  for (int i = 1; i <= n2; i++)
    b[i] = i;
  sort(b + 1, b + n2 + 1, cmp);
  while (r --) {
    for (int i = 2; i <= n2; i += 2) {
      if (w[b[i - 1]] > w[b[i]]) s[b[i - 1]] ++, c[i >> 1] = b[i - 1], d[i >> 1] = b[i];
      else s[b[i]] ++, d[i >> 1] = b[i - 1], c[i >> 1] = b[i];
    }
    merge(c + 1, c + n + 1, d + 1, d + n + 1, b + 1, cmp);
  }
  cout << b[q] << endl;
  return 0;
}