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
int ch[N][26], val[N], cnt;
char str[N];
void insert(int n) {
  int now = 0;
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
  for (int i = 0; i < 26; i++)
    if (ch[0][i]) q[++ r] = ch[0][i];
  while (l < r) {
    int now = q[++ l];
    for (int i = 0; i < 26; i++) {
      if (!ch[now][i]) ch[now][i] = ch[fail[now]][i];
      else fail[ch[now][i]] = ch[fail[now]][i], q[++ r] = ch[now][i];
    }
  }
}
int query(int n) {
  int now = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = str[i] - 'a';
    int k = now = ch[now][x];
    while (k && ~val[k]) {
      ans += val[k];
      val[k] = -1;
      k = fail[k];
    }
  }
  return ans;
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