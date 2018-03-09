// AC 自动机
#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int ch[N][26], val[N], cnt = 1;
char str[N];
void insert(int n) {
  int now = 1;
  for (int i = 1; i <= n; i++) {
    int x = str[i] - 'a';
    if (!ch[now][x])
      ch[now][x] = ++ cnt;
    now = ch[now][x];
  }
  val[now] ++;
}
int q[N], l, r, fail[N];
void build_fail() {
  q[++ r] = 1;
  while (l < r) {
    int now = q[++ l];
    for (int i = 0; i < 26; i++) {
      if (!ch[now][i])
        continue;
      int k = fail[now];
      while (k && !ch[k][i])
        k = fail[k];
      fail[ch[now][i]] = ch[k][i];
      q[++ r] = ch[now][i];
    }
  }
}
int query(int n) {
  int now = 1;
  for (int i = 1; i <= n; i++) {
    int x = str[i] - 'a';
    int k = ch[now][x];
    while (k) {
      ans += 
    }
    now = ch[now][x]
      ? ch[now][x]
      : ch[fail[now]][x]
  }
}
int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    insert(strlen(str + 1));
  }
  build_fail();
  scanf("%s", str + 1);
  cout << query(strlen(str + 1)) << endl;
  return 0;
}