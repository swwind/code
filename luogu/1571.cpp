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
int a[N], b[N], cnt;
map<int, int> mp;
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    mp[a[i] = read()] = i;
  for (int i = 1; i <= m; i++) {
    int x = read();
    if (mp[x]) {
      b[++ cnt] = mp[x];
    }
  }
  sort(b + 1, b + cnt + 1);
  for (int i = 1; i <= cnt; i++)
    printf("%d ", a[b[i]]);
  puts("");
  return 0;
}